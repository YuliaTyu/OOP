#include"String.h"



//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS
#define ISTREAM_OPERATOR
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