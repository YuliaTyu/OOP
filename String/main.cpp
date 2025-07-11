#include<Windows.h>
#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------\n"

       ///////Объявление класса /////////

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;  //размер строки в байтах 
	char* str; //указатель на строку в динамической памяти 
public:
	int get_size()const;
	const char* get_str() const;
	char* get_str();

	                  ////////конструкторы////////
					  
	//к-р по умолчанию выделил память остальные к-ры выполняют за него всю работу (ДЕЛЕГИРОВАНИЕ)
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

/////// конец объявления класса /////////

//////////////////-------------------------------------------//////////////////

/////// определение класса///////////////////
int String::get_size()const
{
	return size;
}
const char* String::get_str() const 
{
	return str;
}
char* String::get_str()
{
	return str;
}

////////конструкторы////////

//к-р по умолчанию выделил память остальные к-ры выполняют за него всю работу (ДЕЛЕГИРОВАНИЕ)
String::String(int size) :size(size), str(new char[this->size] {})//1size - перем члена класса, 2size - принимаемый пар-тр
{
	cout << "DefaultConstruction\t" << this << endl;
}
//:: - оператор разрешения видимости
String::String(const char str[]) :String(strlen(str) + 1)//к-р char вызывает к-р по умолчанию
{
	for (int i = 0; str[i]; i++)
		this->str[i] = str[i];
	cout << "Constuctor\t\t" << this << endl;
}

//конструктор копирования DeepCopy 
String::String(const String& other) :String(other.str)// вызывает к-р типа char 
{
	cout << "CopyConstructor\t\t" << this << endl;
}

String::String(String&& other) :size(other.size), str(other.str) //К-р переноса НЕЛЬЗЯ ДЕЛЕГИРОВАТЬ - так как не выделяет память!
{
	other.size = 0;
	other.str = nullptr; //защищаем память от удаления деструктором - суть к-ра переноса!!!!!!
	cout << "MoveConstructor\t\t" << this << endl;
}

String::~String()
{
	delete[] str;
	this->str = nullptr;
	this->size = 0;
	cout << "Destructor\t\t" << this << endl;
}

//оператор присваивания
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment\t\t" << this << endl;
	return *this;

}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//методы 
void String::info() const
{
	cout << "Size\t" << size << endl;
	cout << "Str\t" << str << endl;
}



//глобальная функция!!! не надо писать String ::
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; left.get_str()[i]; i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; right.get_str()[i]; i++)
		//result.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
		result[left.get_size() - 1 + i] = right[i];
	cout << "Operator +" << endl;
	return result;
}


std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

std::istream& operator>>(std::istream& cin, String& obj) //ПРОБЕЛ - разделитель прерывает работу !!!! ввол без пробелов
{
	const int SIZE = 1024; //размер буфера - 1KB
	char buffer[SIZE] = {};
	cin >> buffer;
	obj = buffer;
	return cin;
}

std::istream& getline(std::istream& cin, String& obj)
{
	cin.getline(obj.get_str(), obj.get_size());
	return cin;
}

/////// конец определения класса///////////////////



//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS
//#define ISTREAM_OPERATOR
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK


	String str1 (5);//explicit-конструктор можно вызвать при помощи круглых скобок
	str1.info();
	cout << str1 << endl;
	str1.info();

	String str2 = "Hello";
	str2 = str2;
	cout << str2 << endl;

	String str3 = str2;
	cout << str3 << endl;

	String str4;
	str4 = str3;
	cout << str4 << endl;


#endif // #define CONSTRUCTORS_CHECK


#ifdef OPERATOR_PLUS

	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;
	String str4 = str3;
	cout << delimiter << endl;
	cout << str4 << endl;

#endif // OPERATOR_PLUS

#ifdef ISTREAM_OPERATOR

	String str;
	cout << "Введите строку";
	SetConsoleCP(1251);
	//cin >> str;
	//cin.getline(str.get_str(), str.get_size());
	getline(cin, str);
	SetConsoleCP(866);
	cout << str << endl;
#endif // #define ISTREAM_OPERATOR

#ifdef CALLING_CONSTRUCTORS

	String str1;//к-р по умолчанию
	str1.info();

	String str2(8);//к-р с одним параметром
	str2.info();

	String str3 = "Hello";//к-р по умолчанию const char - указатель на конструктор
	str3.info();

	cout << typeid("Hello").name()<< endl;

	String str4();//никакой к-р - объявление функции, кот не принимает, но возвращает объект типа String
	//в теле функции нельзя вызывать другую функцию
	//str.4

	String str5(8);    //создание строки 8 байт
	String str6{ 8 }; //создание строки 8 байт - инициали в стиле с++
	String str7{};    //явный вызов к-ра по умолчанию

	String str9 = str3; //к-р копирования
	str9.info();

#endif // CALLING_CONSTRUCTORS



}