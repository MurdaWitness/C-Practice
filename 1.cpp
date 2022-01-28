//Подключение необходимых библиотек
#include <iostream>
#include <cmath>
#include <algorithm>

/*
Объявление служебного класса Point, 
который представляет собой точки в углах треугольника
*/
class Point
{
    private:
        //Координаты точки
        double x;
        double y;
    public:
        //Конструктор по умолчанию
        Point()
        {
            x = 0;
            y = 0;
        }
    
        //Конструктор с координатами точки
        Point(double x, double y)
        {
            this->x = x;
            this->y = y;
        }
        
        //Конструктор копирования
        Point(Point &other)
        {
            x = other.x;
            y = other.y;
        }
    
        //Сложение двух точек
        Point operator+(Point other)
        {
            return Point(x+other.x, y+other.y);
        }
        
        //Вычитание двух точек
        Point operator-(Point other)
        {
            return Point(x-other.x, y-other.y);
        }
        
        //Умножение точки на число
        Point operator*(double number)
        {
            return Point(x*number, y*number);
        }
        
        //Деление точки на число
        Point operator/(double number)
        {
            return Point(x/number, y/number);
        }
        
        //Расстояние между двумя точками
        double distance(Point other)
        {
            return *this - other;
        }
        
        /*
        Оператор перевода точки в тип double.
        Возвращает расстояние до начала координат
        */
        operator double()
        {
            return sqrt(x*x+y*y);
        }
};

/*
Объявление класса треугольников. 
*/
class Triangle
{
    private:
        //Переменные, хранящие точки треугольника
        Point a;
        Point b;
        Point c;
        
        /*
        Переменные, хранящие длинны сторон треугольника.
        Каждая сторона находится напротив соответствующей точки.
        */
        double A;
        double B;
        double C;
        
        /*
        Метод для вычисления высоты, прилегающей к стороне.
        Метод объявлен приватным, так как принимает в качестве
        аргумента длину стороны, а не ее название, что может
        быть небезопасно при неаккуратном использовании.
        */
        double calculateHeight(double side)
        {
            return 2*getArea()/side;
        }
        
        /*
        Метод для вычисления угла между сторонами B и C.
        Метод объявлен приватным, так как пользователю неудобно каждый
        раз писать три аргумента, для этого у метода есть обертка.
        */
        double calculateAngle(double sideA, double sideB, double sideC)
        {
            double cos = (sideB*sideB + sideC*sideC - sideA*sideA)/(2*sideC*sideB);
            return acos(cos);
        }
    public:
        //Конструктор по умолчанию
        Triangle() : 
            a(0, 0),
            b(0, 1),
            c(1, 0)
        {
            A = b.distance(c);
            B = a.distance(c);
            C = a.distance(b);    
        }
    
        //Конструктор, принимающий три точки в качестве аргументов
        Triangle(Point a, Point b, Point c) :
            a(0, 0),
            b(0, 0),
            c(0, 0)
        {
            this->a = a;
            this->b = b;
            this->c = c;
            
            A = b.distance(c);
            B = a.distance(c);
            C = a.distance(b);
        }
        
        //Метод, вычисляющий периметр треугольника
        double getPerimeter()
        {
            return A + B + C;
        }
        
        //Метод, вычисляющий площадь треугольника
        double getArea()
        {
            double p = getPerimeter()/2;
            return sqrt(p * (p-A) * (p-B) * (p-C));
        }
        
        /*
        Метод-обертка над методом calculateHeight(),
        вычисляющий высоту треугольника, падающую
        на выбранную сторону.
        */
        double getHeight(char side)
        {
            switch (side)
            {
                case 'A':
                    return calculateHeight(A);
                case 'B':
                    return calculateHeight(B);
                case 'C':
                    return calculateHeight(C);
            }
        }
        
        //Метод, возвращающий длину выбранной стороны
        double getSide(char side)
        {
            switch (side)
            {
                case 'A':
                    return A;
                case 'B':
                    return B;
                case 'C':
                    return C;
            }
        }
        
        /*
        Метод-обертка над методом calculateAngle(),
        вычисляющий угол, противолежащий указанной стороне.
        */
        double getAngle(char side)
        {
            switch (side)
            {
                case 'A':
                    return calculateAngle(A, B, C);
                case 'B':
                    return calculateAngle(B, C, A);
                case 'C':
                    return calculateAngle(C, A, B);
                default:
                    return calculateAngle(A, B, C);
            }
        }
        
        /*
        Метод, проверяющий равенство треугольников
        по длинам его сторон
        */
        bool isEqual(Triangle other)
        {
            double sides[3];
            sides[0] = A;
            sides[1] = B;
            sides[2] = C;
            std::sort(std::begin(sides), std::end(sides));
            
            double otherSides[3];
            otherSides[0] = other.A;
            otherSides[1] = other.B;
            otherSides[2] = other.C;
            std::sort(std::begin(otherSides), std::end(otherSides));
            
            return (sides[0] == otherSides[0] && sides[1] == otherSides[1] && sides[2] == otherSides[2]);
        }
        
        /*
        Метод, проверяющий, подобны ли треугольники,
        по соотношению длин их сторон.
        */
        bool isSimiliar(Triangle other)
        {
            double sides[3];
            sides[0] = A;
            sides[1] = B;
            sides[2] = C;
            std::sort(std::begin(sides), std::end(sides));
            
            double otherSides[3];
            otherSides[0] = other.A;
            otherSides[1] = other.B;
            otherSides[2] = other.C;
            std::sort(std::begin(otherSides), std::end(otherSides));
            
            return (sides[0]/otherSides[0] == sides[1]/otherSides[1] && sides[0]/otherSides[0] == sides[2]/otherSides[2]);
        }
};

//Функция main()
int main()
{
    std::setlocale(0, "rus");
    
    int x, y;
    Point a, b, c;
    std::cout << "Создание первого треугольника" << std::endl;
    std::cout << "Введите координаты 1-й точки:" << std::endl;
    std::cin >> x >> y;
    a = Point(x, y);
    std::cout << "Введите координаты 2-й точки:" << std::endl;
    std::cin >> x >> y;
    b = Point(x, y);
    std::cout << "Введите координаты 3-й точки:" << std::endl;
    std::cin >> x >> y;
    c = Point(x, y);
    
    Triangle triangle1 = Triangle(a, b, c);
    
    std::cout << std::endl;
    std::cout << "Создание второго треугольника" << std::endl;
    std::cout << "Введите координаты 1-й точки:" << std::endl;
    std::cin >> x >> y;
    a = Point(x, y);
    std::cout << "Введите координаты 2-й точки:" << std::endl;
    std::cin >> x >> y;
    b = Point(x, y);
    std::cout << "Введите координаты 3-й точки:" << std::endl;
    std::cin >> x >> y;
    c = Point(x, y);
    
    Triangle triangle2 = Triangle(a, b, c);
    
    std::cout << "Треугольник 1:" << std::endl;
    std::cout << "Площадь:" << triangle1.getArea() << std::endl;
    std::cout << "Периметр:" << triangle1.getPerimeter() << std::endl;
    std::cout << "Углы в радианах:" << triangle1.getAngle('A') << ", " << triangle1.getAngle('B') << ", " << triangle1.getAngle('C') << std::endl;
    std::cout << std::endl;
    
    std::cout << "Треугольник 2:" << std::endl;
    std::cout << "Площадь:" << triangle2.getArea() << std::endl;
    std::cout << "Периметр:" << triangle2.getPerimeter() << std::endl;
    std::cout << "Углы в радианах:" << triangle2.getAngle('A') << ", " << triangle2.getAngle('B') << ", " << triangle2.getAngle('C') << std::endl;
    std::cout << std::endl;
    
    if(triangle1.isSimiliar(triangle2)) std::cout << "Треугольник 1 подобен треугольнику 2" << std::endl;
    else std::cout << "Треугольник 1 не подобен треугольнику 2" << std::endl;
    
    if(triangle1.isEqual(triangle2)) std::cout << "Треугольник 1 равен Треугольнику 2" << std::endl;
    else std::cout << "Треугольник 1 не равен Треугольнику 2" << std::endl;
    
    return 0;
}
