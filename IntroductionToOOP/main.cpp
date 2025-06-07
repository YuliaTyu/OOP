#pragma warning(disable:4326)
#include<iostream>
using namespace std;

//создание класса
class Point //новый тип данных 'Point' (создавая структуру или класс)
{
	double x; //переменные члены класса
	double y;
public: 
	double get_x() const // реализуем инкапсуляцию
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x; //указатель на объект 
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// секция конструктор создание объекта
	//Point()
	//{
	//	x = y = 0;
	//	cout << "Default constructor \t" << this << endl;
	//}
	//Point(int x) //конструкотор с параметрами
	//{
	//	this->x = x;
	//	this->y = 0;
	//	cout << "Constructor \t\t" << this << endl;
	//}
	Point(double x=0, double y=0)//констуктор принимает два параметра- работает с тремя объектами
	{
		this->x = x;
		this->y = y;
		cout << "Constructor \t\t" << this << endl;

	}



	//деструктор - удаление объекта
	~Point()
	{
		cout << "Destructor\t\t" << this << endl;
	}

	//Methods
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;


	}


	//секция метод
	void print()const
	{
		cout << "X = " << get_x() << "\tY = " << get_y() << endl;
	}


};

//функция
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

//#define CONSTRUCTORS_CHECK
//#define STRACT_POINT
#define DISTANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRACT_POINT
	//создане объекта
	Point A;         //объявление переменной А типа Point// создание объекта А структруры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif

#ifdef CONSTRUCTORS_CHECK


	//создание объекта
	Point A; //здесь неявно вызывается конструктор по умолчанию
	         // так как мы создаем объект по умолчанию
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();


	Point B = 5;
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();
		
	Point C(7, 8);
	C.print();
#endif 

	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();

	cout << "Растояние от точки А до точки В" << A.distance(B)<< endl;
	cout << "Растояние от точки B до точки A" << B.distance(A)<< endl;
	cout << "Растояние между точками А и В" << distance(A, B)<< endl;

}