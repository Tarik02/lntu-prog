/**************************************************************/
/*                                                            */
/*  lab_work_26_02                                            */
/*  Мова: C++                                                 */
/*                                                            */
/*  Констуювання класiв та об'єктiв засобами мови С++.        */
/*  Завдання. Сформувати клас Money з такими компонентами:    */
/* закритi елементи класу - немає;                            */
/* вiдкритi елементи класу:                                   */
/*  Money(int a, int b, int c) - конструктор з 3-ма парам.;   */
/*  Money() - конструктор без параметрів;                     */
/*  int usd - кількість доларів на поточному рахунку;         */
/*  int uah - кількість гривень на поточному рахунку;         */
/*  int pln - кількість злотів на поточному рахунку;          */
/*  void printMoney() - функція друку залишку на рахунку;     */
/*  void currExchange() - функція для перерахунку валют за    */
/* курсом обміну.                                             */
/*  Передбачити різні форми звертання до об'єктів класу.      */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

// Оголошення класу Money
class Money {
public:
	int usd, uah, pln;

public:
	// Конструктор1 (без параметрiв)
	Money() : usd(0), uah(0), pln(0) {}

	// Конструктор2 (з трьома параметрами)
	Money(int usd, int uah, int pln) : usd(usd), uah(uah), pln(pln) {}

	// Друк залишку на рахунку (долари, гривнi, злоті):
	void printBalance();

	// Функцiя перерахунку валют за курсом обмiну
	void currExchange();
};

// Оголошення функцiй класу Money

// Функцiя виведення на друк поточного рахунку
void Money::printBalance() {
	cout << "Ваш поточний рахунок:" << endl;
	cout << "  Долар:  " << usd << endl;
	cout << "  Гривня: " << uah << endl;
	cout << "  Злотий: " << pln << endl;
}

// Функцiя перерахунку валют за курсом обмiну
void Money::currExchange() {
	do {
		cout << "Введіть операцію. Доступні операції:" << endl;
		cout << "  0. Завершити обмін;" << endl;
		cout << "  1. Обмін доларів на гривні;" << endl;
		cout << "  2. Обмін доларів на злоті;" << endl;
		cout << "  3. Обмін гривні на долари;" << endl;
		cout << "  4. Обмін гривні на злоті;" << endl;
		cout << "  5. Обмін злоті на долари;" << endl;
		cout << "  6. Обмін злоті на гривні." << endl;

		int op;
		cout << "> ";
		cin >> op;

		int *from, *to;
		const char *name;
		switch (op) {
		case 0:
			return;
		case 1:
			from = &usd;
			to = &uah;
			name = "долари-гривні";
			break;
		case 2:
			from = &usd;
			to = &pln;
			name = "долари-злоті";
			break;
		case 3:
			from = &uah;
			to = &usd;
			name = "гривні-долари";
			break;
		case 4:
			from = &uah;
			to = &pln;
			name = "гривні-злоті";
			break;
		case 5:
			from = &pln;
			to = &usd;
			name = "злоті-долари";
			break;
		case 6:
			from = &pln;
			to = &uah;
			name = "злоті-гривні";
			break;
		default:
			cout << "Неправильний номер операції. Для продовження натисність будь-яку клавішу." << endl;
			cin.get();
			printBalance();
			cout << endl;
			continue;
		}

		int amount;
		cout << "Введіть суму для обміну:" << endl << "> ";
		cin >> amount;

		if (*from < amount) {
			cout << "На рахунку недостатньо коштів для операції. Для продовження натисність будь-яку клавішу." << endl;
			cin.get();
			printBalance();
			cout << endl;
			continue;
		}

		int course;
		cout << "Введіть курс обміну " << name << ":" << endl << "> ";
		cin >> course;
		*from -= amount;
		*to += amount * course;

		printBalance();
		cout << endl;
	} while (true);
}


int main() {
	cout << "Демонстрацiя роботи Конструктора 1:" << endl;
	Money *p1 = new Money(100, 250, 300);
	p1->printBalance();
	cout << endl;
	p1->currExchange();
	p1->printBalance();
	delete p1;

	cout << endl;
	cout << endl;

	cout << "Демонстрацiя роботи Конструктора 2:" << endl;
	Money *p2 = new Money();
	cout << "  Долар:  ";
	cin >> p2->usd;
	cout << "  Гривня: ";
	cin >> p2->uah;
	cout << "  Злотий: ";
	cin >> p2->pln;
	cout << endl;
	p2->currExchange();
	p2->printBalance();
	delete p2;

	return 0;
}
