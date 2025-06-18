#include<iostream>
using namespace std;
#define delimiter "\n----------------------------------------\n";

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;             //целая часть
	int numerator;           //числитель
	int denominator;         //знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denomerator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//секция конструкторы
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 0;
		cout << "DefoultConstraction\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor\t\t" << this << endl;
	}
	Fraction(const Fraction& other)  // конструктор копирования
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destuctor\t\t" << this << endl;
	}

	//оператор присваивания
	Fraction& operator=(const Fraction& other)
	{
    this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment\t\t" << this << endl;
	return *this;
    }

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other) //целая часть?
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other) //целая часть?
	{
		return *this = *this - other;
	}

	//секция инкремент декремент
	Fraction& operator++()  //префикс 
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)  //постфикс
	{
		Fraction old = *this; //создание локальной переменной для возврата в функцию
		integer++;
		return old;
	}
	Fraction& operator--()  //префикс 
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)  //постфикс
	{
		Fraction old = *this; //создание локальной переменной для возврата в функцию
		integer--;
		return old;
	}
	
	//методы
	Fraction& to_improper()
	{
		//переводим дробь в неправильную
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}

};



//перегрука операторов - ФУНКЦИИ
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denomerator() * right.get_denomerator());
	return result;*/
	
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denomerator() * right.get_denomerator()
	);
	return result;*/

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denomerator() * right.get_denomerator()
	).to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)    //целая часть?
{
	/*return Fraction
	(
		left.get_numerator() + right.get_numerator(),
		left.get_denomerator() + right.get_denomerator()
	).to_proper();*/
	Fraction result;
	result.set_numerator(left.get_numerator() + right.get_numerator());
	result.set_denominator(left.get_denomerator() + right.get_denomerator());
	return result;
}
Fraction operator-(Fraction left, Fraction right)        //целая часть?
{
	Fraction result;
	result.set_numerator(left.get_numerator() - right.get_numerator());
	result.set_denominator(left.get_denomerator() - right.get_denomerator());
	return result;
}
//операторы сравнения
bool operator ==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denomerator() == right.get_numerator() * left.get_denomerator();
}
bool operator !=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator <=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denomerator() <= right.get_numerator() * left.get_denomerator();
}
bool operator >=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denomerator() >= right.get_numerator() * left.get_denomerator();
}
bool operator <(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denomerator() < right.get_numerator() * left.get_denomerator();
}
bool operator >(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denomerator() > right.get_numerator() * left.get_denomerator();
}



std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denomerator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
/*std::ostream& operator>>(std::ostream& os, const Fraction& obj) процcес перегрузки оператора ввода >>
{
	if (obj.get_integer())os >> obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os >> obj.get_numerator() << "/" << obj.get_denomerator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os >> 0;
	return os;
}*/




//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARIFMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMP_OPERATOR

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK


	Fraction A;         //конс без параметров
	A.print();

	Fraction B=5;       // конст с одним параметром
	B.print();

	Fraction C(1, 2);  //конст с параметрами
	C.print();

	Fraction D(2, 3, 4);//конст с параметрами
	D.print();

	Fraction E = D;     //конст копирования для НОВОГО ОБЪЕКТА
	E.print();

	Fraction F;        //оператор присваивания для СУЩЕСТВУЮЩЕГО ОБЪЕКТА
	F = E;
	F.print();

#endif //CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK


	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Fraction A, B, C;
	cout << delimiter;
	A = B = C = Fraction(2,3,4);  //явный вызов конст-ра, кот создает временный безымяный объект
	                              //(существует в пределах одного выражения)
	cout << delimiter;
#endif // ASSIGNMENT_CHECK

#ifdef ARIFMETICAL_OPERATORS


	Fraction A(1, 2);
	Fraction B(2, 3, 4);
	Fraction C = A - B;
	A.print();
	B.print();
	C.print();

	cout << delimiter;
	A -= B;
	A.print();
	B.print();

#endif // ARIFMETICAL_OPERATORS
	
#ifdef INCREMENT_DECREMENT


	Fraction A(1, 2);
	Fraction B = A--;
	A.print();
	B.print();


#endif // INCREMENT_DECREMENT

#ifdef COMP_OPERATOR


	cout << (Fraction(1, 2) == Fraction(5, 10)) << endl;

	cout << (Fraction(1, 2) != Fraction(5, 10)) << endl;

	cout << (Fraction(1, 2) <= Fraction(5, 11)) << endl;

	cout << (Fraction(1, 2) >= Fraction(1, 2)) << endl;

	cout << (Fraction(1, 3) < Fraction(5, 10)) << endl;

	cout << (Fraction(1, 3) > Fraction(5, 10)) << endl;

#endif // COMP_OPERATOR



	Fraction A;
	cout << "Введите простую дробь"; cin >> A;

	cout << A << endl;

}
