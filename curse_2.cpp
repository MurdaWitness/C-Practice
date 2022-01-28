#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Sportsmen
{ 
    public:
		int num;
        string FIO;
		string mark;
		
        Sportsmen(int n, string f, string m)
        {
            num = n;
            FIO = f;
			mark = m;
        }
        
        void Print()
        {
			cout<<"№ водителя: "<<num<<endl;
			cout<<"ФИО водителя: "<<FIO<<endl;
			cout<<"Марка автомобиля: "<<mark<<endl;
			cout<<endl;
        }
};

class Track
{
    public:
        int num;
        string geo;
		int length;
		
        Track(int n, string g, int l)
        {
            num = n;
            geo = g;
			length = l;
        }
        
        void Print()
        {
			cout<<"№ трассы: "<<num<<endl;
			cout<<"Месторасположение трассы: "<<geo<<endl;
			cout<<"Протяжённость, км: "<<length<<endl;
			cout<<endl;
        }
};

class Results
{
    public:
        Sportsmen *sports;
		Track *trck;
		int time;
		
        Results(Track *t, Sportsmen *s, int tim)
        {
            sports = s;
            trck = t;
			time = tim;
        }
        
        void Print()
        {
			cout<<"№ трассы: "<<trck->num<<endl;
			cout<<"№ водителя: "<<sports->num<<endl;
			cout<<"Время прохождения трассы, мин: "<<time<<endl;
			cout<<endl;
        }
};


int main()
{
	cout<<"\tСПОРТСМЕНЫ"<<endl;
    Sportsmen driver1 = Sportsmen(1, "Семен Варламов", "Гранд Чероки");
    driver1.Print();
	Sportsmen driver2 = Sportsmen(2, "Евгений Малкин", "ЛендКрузер");
    driver2.Print();
	Sportsmen driver3 = Sportsmen(3, "Вячеслав Войнов", "Шевроле Нива");
    driver3.Print();
	Sportsmen driver4 = Sportsmen(4, "Дмитрий Мальчиков", "РенджРовер");
    driver4.Print();
	Sportsmen driver5 = Sportsmen(5, "Роман Граборенко", "ЛендКрузер");
    driver5.Print();
	cout<<endl;
	
	cout<<"\t  ТРАССЫ"<<endl;
	Track tr1 = Track(1, "Карелия", 60);
	tr1.Print();
	Track tr2 = Track(2, "Тверь", 40);
	tr2.Print();
	Track tr3 = Track(3, "Московская область", 30);
	tr3.Print();
	cout<<endl;
	
	cout<<"\tРЕЗУЛЬТАТЫ СОРЕВНОВАНИЯ"<<endl;
	Results res1 = Results(&tr1, &driver1, 169);
	res1.Print();
	Results res2 = Results(&tr1, &driver3, 178);
	res2.Print();
	Results res3 = Results(&tr1, &driver4, 185);
	res3.Print();
	Results res4 = Results(&tr2, &driver2,131);
	res4.Print();
	Results res5 = Results(&tr2, &driver4, 123);
	res5.Print();
	Results res6 = Results(&tr3, &driver1, 118);
	res6.Print();
	Results res7 = Results(&tr3, &driver2,124);
	res7.Print();
	Results res8 = Results(&tr3, &driver3, 119);
	res8.Print();
	Results res9 = Results(&tr3, &driver4, 125);
	res9.Print();
}