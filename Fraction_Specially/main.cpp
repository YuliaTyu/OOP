#include"Fraction.h"

//-----------------------------------------------------------------//


//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARIFMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMP_OPERATOR
#define ISTREAM_OPERATOR
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define HAVE_A_NICE_DAY

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK

	//Fraction A;         //конс без параметров (defoult constructor)
	//A.print();

	//Fraction B=5;       // конст с одним параметром (singl - argument constructor)
	//B.print();

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
	A = B = C = Fraction(2, 3, 4);  //явный вызов конст-ра, кот создает временный безымяный объект
	//(существует в пределах одного выражения)
	cout << delimiter;
#endif // ASSIGNMENT_CHECK

#ifdef ARIFMETICAL_OPERATORS

	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A + B;
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
	Fraction B = ++A++;
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

#ifdef ISTREAM_OPERATOR

	Fraction A;
	cout << "Введите простую дробь"; cin >> A;
	cout << delimiter;
	cout << A << endl;
	cout << delimiter;

#endif //ISTREAM_OPERATOR 

#ifdef CONVERSION_FROM_OTHER_TO_CLASS

	Fraction A = (Fraction)5;
	cout << A << endl;

	Fraction B;
	B = Fraction(8345);
	cout << B << endl;
#endif // #define CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER

	Fraction A(2, 3, 4);
	cout << A << endl;

	int a = (int)A;
	cout << a << endl;

	double b = (double)A;
	cout << b << endl;

#endif //CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HAVE_A_NICE_DAY

	Fraction A = 2.76;
	cout << A << endl;

#endif // HAVE_A_NICE_DAY


}