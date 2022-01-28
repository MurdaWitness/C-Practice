#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Complex_number
{
    private:
        float rl;
        float img;
    public:
        Complex_number()
        {
            rl = 0;
            img = 0;
        }
        
        Complex_number(float r, float i)
        {
            rl = r;
            img = i;
        }
        
        void Print()
        {
            if(rl != 0)
            {
                cout << rl;
                
                if (img == -1)
                cout << " - " << "i\n";
                else if(img < 0)
                cout << " - " << fabs(img) << "i\n";
                else if (img == 0)
                cout << "\n";
                else if (img == 1)
                cout << " + " << "i\n";
                else
                cout << " + " << img << "i\n";
            }
            else
            {
                if (img == -1)
                cout << "-i\n";
                else if (img == 0)
                cout << rl << "\n";
                else if (img == 1)
                cout << "i\n";
                else
                cout << img << "i\n";
            }
        }
        
        Complex_number operator+(Complex_number n2)
        {
            return Complex_number(rl + n2.rl, img + n2.img);
        }
        
        Complex_number operator-(Complex_number n2)
        {
            return Complex_number(rl - n2.rl, img - n2.img);
        }
        
        Complex_number operator*(Complex_number n2)
        {
            return Complex_number(rl * n2.rl - img * n2.img, img * n2.rl + rl * n2.img);
        }
		
		Complex_number operator/(Complex_number n2)
        {
			float rl_prt = (rl*n2.rl + img*n2.img)/(pow(n2.rl,2)+pow(n2.img,2));
			float img_prt = (img*n2.rl - rl*n2.img)/(pow(n2.rl,2)+pow(n2.img,2));
            return Complex_number(rl_prt, img_prt);
        }
		
		Complex_number complex_pow (int stepan)
		{
			Complex_number new_num = *this;
			for (int i = 1; i<stepan; i++)
				new_num = new_num * (*this);
			return new_num;
		}
		
		Complex_number* complex_root (int korney)
		{
			Complex_number *array = new Complex_number[korney * sizeof(Complex_number)];
			float w = sqrt(rl*rl + img*img);
			float f = atan(img/rl);
			for (int i = 0; i<korney; i++)
			{
				float rl_prt = pow(w, 1.0/korney) * cos((f + 2 * M_PI * i)/korney);
				float img_prt = pow(w, 1.0/korney) * sin((f + 2 * M_PI * i)/korney);
				array[i] = Complex_number(rl_prt, img_prt);
			}
			return array;
		}
};


int main()
{
	float rl;
	float img;
	cout<<"Первое комплексное число:\n";
	cout<<"Реальная часть:";
	cin>>rl;
	cout<<"Мнимая часть:";
	cin>>img;
    Complex_number num1 = Complex_number(rl, img);
    num1.Print();
	cout<<"\n";

	cout<<"Второе комплексное число:\n";
	cout<<"Реальная часть:";
	cin>>rl;
	cout<<"Мнимая часть:";
	cin>>img;
    Complex_number num2 = Complex_number(rl, img);
    num2.Print();
	cout<<"\n";

	cout<<"Сложение:\n";
    Complex_number num3 = num1 + num2;
    num3.Print();

	cout<<"\nВычитание:\n";
    Complex_number num4 = num1 - num2;
    num4.Print();

	cout<<"\nУмножение:\n";
	Complex_number num5 = num1 * num2;
    num5.Print();

	cout<<"\nДеление:\n";
	Complex_number num6 = num1 / num2;
    num6.Print();
	
	int stepan;
	cout<<"\nВозведение первого комплексного числа в степень:\n";
	cout<<"Введите степень:";
	cin>>stepan;
	Complex_number num7 = num1.complex_pow(stepan);
    num7.Print();

	int korney;
	cout<<"\nНахождение корней первого комплексного числа:\n";
	cout<<"Введите степень корня:";
	cin>>korney;
	Complex_number *array = num1.complex_root(korney);
    for(int i = 0; i<korney; i++)
	array[i].Print();
}