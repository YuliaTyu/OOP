#include<Windows.h>
#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

class String
{
	int size;  //размер строки в байтах 
	char* str; //указатель на строку в динамической памяти 
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str() const // гарантия что на месте вызова не изменится значение
	{
		return str;
	}
	char* get_str() 
	{
		return str;
	}

	//конструкторы

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstruction\t" << this << endl;
	}
	String(const char str[])
	{
		size = 0;
		while(str[size++]);
			this->str = new char[size] {};
			for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constuctor\t\t" << this << endl;
	}

	//конструктор копирования DeepCopy - ПОБИТОВОЕ КОПИРОВАНИЕ - т е выделять дин память под объект и побитово
	// поэлементно копировать содержимое динам памяти из существующего объекта в создаваемый
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor\t" << this << endl;
	}

	~String()
	{
		delete[] str;
		this->str = nullptr;
		this->size = 0;
		cout << "Destructor\t\t" << this << endl;
	}

	//оператор присваивания
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment\t" << this << endl;
		return *this;
	}
	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//методы 
	void info() const
	{
		cout << "Size\t" << size << endl;
		cout << "Str\t" << str << endl;
	}

};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; left.get_str()[i]; i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; right.get_str()[i]; i++)
		//result.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
		result[left.get_size() - 1 + i] = right[i];
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


//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS

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
	String str3 = str1 + " " + str2;
	cout << str3 << endl;

#endif // OPERATOR_PLUS


	String str;
	cout << "Введите строку";
	SetConsoleCP(1251);
	//cin >> str;
	//cin.getline(str.get_str(), str.get_size());
	getline(cin, str);
	SetConsoleCP(866);
	cout << str << endl;

}