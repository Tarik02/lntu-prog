/**************************************************************/
/*                                                            */
/*  lab_work_27_01                                            */
/*  Мова: C++                                                 */
/*                                                            */
/*  Конструювання класів та об'єктів.                         */
/*  Завдання. Сконструювати структуру client з такими полями: */
/* int number - номер рахунку клієнта;                        */
/* char name[128] - прізвище клієнта;                         */
/* float balance - баланс клієнта.                            */
/*                                                            */
/*  Сконструювати базовий клас Client з такими полями:        */
/* Закриті елементи класу - відсутні.                         */
/* Відкриті елементи класу:                                   */
/* int k         - кількість клієнтів;                        */
/* client m[100] - масив структур типу client;                */
/* void enter()  - функцiя введення даних;                    */
/* void print()  - функцiя виведення даних;                   */
/*                                                            */
/*  Сконструювати похідний клас Sort з такими полями:         */
/* Закриті елементи класу:                                    */
/* void swap(int, int) - функцiя обмiну значень.              */
/* Вiдкритi елементи классу:                                  */
/* void sort() - функцiя сортування масиву;                   */
/* void sort1() - функцiя сортування даних з ручним введенням */
/*                способу (до 10 спроб) і виведенням.         */
/*                                                            */
/*  Доступ до елементiв класу Sort здiйснити за допомогою     */
/* об'єкта obS та вказівника на об'єкт *obSp.                 */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

// Оголошення структури client
struct client {
	int number;      // Номер рахунку клієнта
	char name[128];  // Прiзвище клiента
	float balance;   // Баланс клієнта
};

// Оголошення базового класу Client
class Client {
public:           // Вiдкритi елементи класу Client
	Client();       // Конструктор
	~Client();      // Деструктор

	int k;          // Кількість банківських клієнтів
	client m[100];  // Масив структур типу client

	void enter();   // Функцiя введення даних
	void print();   // Функцiя виведення даних
};

// Оголошення класу Sort - нащадка класу Client
class Sort : public Client {
public:                // Відкриті елементи класу Sort
	Sort();              // Конструктор
	~Sort();             // Деструктор

private:
	void swap(int, int); // Обмін значень

public:
	void sort(int);      // Сортування масиву
	void sort1();        // Сортування масиву з ручним введенням способу і виведенням на екран
};

// Опис функцій класу Client

// Опис конструкторiв та деструкторiв
Client::Client() {
	k = 3;
}

Client::~Client() {
}

// Функцiя введення значень елементiв масиву структур
void Client::enter() {
	for (int i = 0; i < k; ++i) {
		cout << "  Введiть номер рахунку клiєнта: ";
		cin >> m[i].number;
		cout << "  Введiть прiзвище клiєнта:      ";
		cin.ignore();
		cin.getline(m[i].name, sizeof(m[i].name));
		cout << "  Введiть баланс клiєнта:        ";
		cin >> m[i].balance;
		cout << endl;
	}
}

// Функцiя виведення на друк значень елементiв масиву структур
void Client::print() {
	for (int i = 0; i < k; ++i) {
		cout << "Структура N" << setw(3) << i + 1 << ":" << endl;
		cout << "  number =  " << m[i].number << endl;
		cout << "  name =    " << m[i].name << endl;
		cout << "  balance = " << setprecision(3) << m[i].balance << endl;
	}
	cout << endl;
}

// Опис функцій класу Sort

Sort::Sort() : Client() {
}

Sort::~Sort() {
}

// Опис iнших функцiй класу Client

// Функцiя обмiну значень
void Sort::swap(int i, int j) {
	client c = m[i];
	m[i] = m[j];
	m[j] = c;
}

// Функцiя сортування за ознакою ind значень елементiв массиву структур
void Sort::sort(int ind) {
	for (int i = 0; i < k - 1; ++i) {
		for (int j = i + 1; j < k; ++j) {
			switch (ind) {
				case 1:
					if (m[i].number > m[j].number) {
						swap(i, j);
					}
					break;
				case 2:
					if (strcmp(m[i].name, m[j].name) > 0) {
						swap(i,j);
					}
					break;
				case 3:
					if (m[i].balance > m[j].balance) {
						swap(i, j);
					}
					break;
				default:
					cout << "  Введено помилковий параметр" << endl;
					return;
			}
		}
	}
}

// Функцiя сортування значень елементiв масиву структур
// з ручним введенням ознаки сортування ind
void Sort::sort1() {
	for (int i = 0; i < 10; ++i) {
		cout << "Виберiть параметр сортування:" << endl;
		cout << "  1 - за номером рахунку" << endl;
		cout << "  2 - за iм'ям" << endl;
		cout << "  3 - за величиною балансу" << endl;
		cout << "  5 - вихiд" << endl;
		cout << "> ";
		int ind;
		cin >> ind;
		if (ind == 5) {
			exit(1);
		}
		sort(ind);
		cout << "Результат сортування за параметром " << ind << ":" << endl;
		print();
	}
}

int main() {
	Sort obS, *obSp;
	obSp = &obS;

	obS.enter();

	obSp->print();

	obSp->sort(2);
	obSp->print();

	obSp->sort1();
	obSp->print();

	return 0;
}
