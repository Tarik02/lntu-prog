/**************************************************************/
/*                                                            */
/*  lab_work_25_01                                            */
/*  Мова: C++                                                 */
/*                                                            */
/*  Класи та об'єкти в С++.                                   */
/*  Завдання. Створити клас Complex для роботи з комплексними */
/* числами, у якому передбачити такi елементи-функції:        */
/*  - введення дiйсної та уявної частини комлексного числа;   */
/*  - виведення дiйсної, уявної частини i модуля комлексного  */
/*    числа;                                                  */
/*  - обчислення модуля комлексного числа;                    */
/*  - додавання двох комлексних чисел;                        */
/*  - вiднiмання двох комлексних чисел;                       */
/*  - множення двох комлексних чисел;                         */
/*  - дiлення двох комлексних чисел.                          */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

class Complex {
public:
	double re, im, mod;

public:
	Complex();
	Complex(double re, double im);

	void recalc();
};

Complex::Complex() {
	re = 0;
	im = 0;
	mod = 0;
}

Complex::Complex(double re, double im) {
	this->re = re;
	this->im = im;
	recalc();
}

void Complex::recalc() {
	mod = sqrt(re * re + im * im);
}

istream &operator >>(istream &in, Complex &c) {
	cout << "  Введіть дійсьну частину комплексного числа: ";
	in >> c.re;
	cout << "  Введіть уявну частину комплексного числа: ";
	in >> c.im;
	c.recalc();
	return in;
}

ostream &operator <<(ostream &out, const Complex &c) {
	out << "  Дiйсна частина комлексного числа: " << c.re << endl;
	out << "  Уявна частина комлексного числа: " << c.im << endl;
	out << "  Модуль комлексного числа: " << c.mod;

	return out;
}

Complex operator +(const Complex &a, const Complex &b) {
	return Complex(a.re + b.re, a.im + b.im);
}

Complex operator -(const Complex &a, const Complex &b) {
	return Complex(a.re - b.re, a.im - b.im);
}

Complex operator *(const Complex &a, const Complex &b) {
	return Complex(a.re * b.re - a.im * b.im, a.re * b.im + b.re * a.im);
}

Complex operator /(const Complex &a, const Complex &b) {
	return Complex(
		(a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im),
		(-a.re * b.im + b.re * a.im) / (b.re * b.re + b.im * b.im)
	);
}

int main() {
	Complex c1, c2;

	cout << "Введення першого комплексного числа:" << endl;
	cin >> c1;

	cout << endl;

	cout << "Введення другого комплексного числа:" << endl;
	cin >> c2;

	cout << endl;

	cout << "Перше комплексне число:" << endl;
	cout << c1 << endl;

	cout << endl;

	cout << "Друге комплексне число:" << endl;
	cout << c2 << endl;

	cout << endl;

	cout << "Сума двох комплексних чисел:" << endl;
	cout << c1 + c2 << endl;

	cout << endl;

	cout << "Різниця двох комплексних чисел:" << endl;
	cout << c1 - c2 << endl;

	cout << endl;

	cout << "Добуток двох комплексних чисел:" << endl;
	cout << c1 * c2 << endl;

	cout << endl;

	cout << "Частка двох комплексних чисел:" << endl;
	cout << c1 / c2 << endl;

	return 0;
}
