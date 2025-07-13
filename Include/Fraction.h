#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define delimiter "\n----------------------------------------\n";

using std::cout;
using std::cin;
using std::endl;

////////////////////ОБЪЯВЛЕНИЕ КЛАССА////////////////////////

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
bool operator ==(Fraction left, Fraction right);
bool operator !=(const Fraction& left, const Fraction& right);
bool operator <=(Fraction left, Fraction right);
bool operator >=(Fraction left, Fraction right);
bool operator <(Fraction left, Fraction right);
bool operator >(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);


class Fraction
{
	int integer;             //целая часть
	int numerator;           //числитель
	int denominator;         //знаменатель
public:
	int get_integer()const;
	int get_numerator() const;
	int get_denomerator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//секция конструкторы
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//оператор присваивания
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);

	//секция инкремент декремент
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	// операторы преобразование типов
	explicit operator int()const;
	explicit operator double()const;

	//методы
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;

	void print()const;

	Fraction& reduce();
};
/////////////////КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА//////////////////////////////
