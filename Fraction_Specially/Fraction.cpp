#include"Fraction.h"


////////////////����������� ������///////////////////////////////////
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator() const
{
	return numerator;
}
int Fraction::get_denomerator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//������ ������������
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefoultConstraction\t" << this << endl;
}
Fraction::Fraction(int integer) // ��������� ������� ��������������
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "SinglArgConstructor\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	//decimal - ���������� 
	decimal += 0.0000000001;// = 1e-10
	integer = decimal; // ������� �������������� ����� �� double � int - ��������� ����� �����
	decimal -= integer;
	denominator = 1000000000;// 1e+9 = 1 000 000 000//����������� ��������� �������� � ��������� (9 ���������� ��������)
	numerator = decimal * denominator;
	reduce();
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	cout << "Constructor\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)  // ����������� �����������
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor\t\t" << this << endl;
}
Fraction:: ~Fraction()
{
	cout << "Destuctor\t\t" << this << endl;
}

//�������� ������������
Fraction& Fraction:: operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment\t\t" << this << endl;
	return *this;
}

Fraction& Fraction:: operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction:: operator/=(const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction:: operator+=(const Fraction& other) //����� �����?
{
	return *this = *this + other;
}
Fraction& Fraction:: operator-=(const Fraction& other) //����� �����?
{
	return *this = *this - other;
}


//������ ��������� ���������
Fraction& Fraction:: operator++()  //������� 
{
	integer++;
	return *this;
}
Fraction Fraction:: operator++(int)  //��������
{
	Fraction old = *this; //�������� ��������� ���������� ��� �������� � �������
	integer++;
	return old;
}
Fraction& Fraction:: operator--()  //������� 
{
	integer--;
	return *this;
}
Fraction Fraction:: operator--(int)  //��������
{
	Fraction old = *this; //�������� ��������� ���������� ��� �������� � �������
	integer--;
	return old;
}

// ��������� �������������� �����
Fraction:: operator int()const //����� ����������� - �� �������� ������ ��� �������� ����������
{
	return integer + numerator / denominator;
}
Fraction:: operator double()const
{
	return integer + (double)numerator / denominator;
}

//������
Fraction& Fraction::to_improper() // ������� � ������������ �����
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::to_proper() // ������� � ���������� ����� (�������� ����� �����)
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}

Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}

void Fraction::print()const
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

Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator < denominator)
	{
		less = numerator;
		more = denominator;
	}
	else
	{
		more = numerator;
		less = denominator;
	}
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}



//��������� ���������� - �������
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
	result.to_proper();
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
Fraction operator+(Fraction left, Fraction right)    //����� �����?
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denomerator() + right.get_numerator() * left.get_denomerator(),
		left.get_denomerator() * right.get_denomerator()
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)        //����� �����?
{
	Fraction result;
	result.set_numerator(left.get_numerator() - right.get_numerator());
	result.set_denominator(left.get_denomerator() - right.get_denomerator());
	return result;
}
//��������� ���������
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
	//bool operator<=( const Fraction& left, const Fraction& right)
	//return left < right || left == right;
	//return !(left > right);
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denomerator() <= right.get_numerator() * left.get_denomerator();
}
bool operator >=(Fraction left, Fraction right)
{
	//bool operator>=( const Fraction& left, const Fraction& right)
	//return left > right || left == right;
	//return !(left < right);
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
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 32;
	char sz_input[SIZE] = {};
	//is >> sz_input; //sz - ������ ��������������� �����
	is.getline(sz_input, SIZE);//���� ������ � ��������� 
	const char delimiters[] = { '(', '/', ')', ' ', '.', ',', 0 };//������� ��������� ������ ������������, ����� � ����������� ������ ����������� ����� (�. �. ������� ������).
	int numbers[3] = {};
	int n = 0;
	for (char* pch = strtok(sz_input, delimiters); pch && n < 3; pch = strtok(NULL, delimiters))
		numbers[n++] = atoi(pch);

	//������� strtok ��������� ������ �� ������, ��� ���� ������� ����� ������ ������� �� ���� ����� ��������� - ����������� (delimiters) ��� � ������� �� ������� ����� ������ ������
	//� ������ - ��� �������, ������� ����� ������� �� ������(��� ��� �� �����������)
	//��� ������ strtok ��������� ������� ������
	//������ strtok ������� ��� ����������� ����������� �� �� ���� �����, � �� ������������������ �������, 
	//��� ��� ������� ������ ��������� ������ ��� ������ ������
	//��� ����������� ������� - � �������� ������� ��������� ���������� NULL
	//���� ��� ����������� ������� ����������� ������ strtok �������� ����� �������.
	//������ strtok ���������� ��������� �� ��������� �����, ���� ����� �� ������ �� ������� ���������� nullptr;
	//pch - �������� ��������� �� ������ ������ ������

	//atoi() ��������� ������ ASCII to Integer, � ���������� ����� �����, �������������� ���� ������.

	//for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;

	switch (n)
	{
	case 1:obj = Fraction(numbers[0]); break;
	case 2:obj = Fraction(numbers[0], numbers[1]); break;
	case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}

	return is;

}

//////////////////����� ����������� ������//////////////////////////
