#pragma once
#include<Windows.h>
#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------\n"

///////ќбъ€вление класса /////////

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& cin, String& obj);
std::istream& getline(std::istream& cin, String& obj);

class String
{
	int size;  //размер строки в байтах 
	char* str; //указатель на строку в динамической пам€ти 
public:
	int get_size()const;
	const char* get_str() const;
	char* get_str();

	////////конструкторы////////

//к-р по умолчанию выделил пам€ть остальные к-ры выполн€ют за него всю работу (ƒ≈Ћ≈√»–ќ¬јЌ»≈)
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//оператор 
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	char operator[](int i)const;
	char& operator[](int i);

	//методы 
	void info() const;

};

/////// конец объ€влени€ класса /////////

//////////////////-------------------------------------------//////////////////