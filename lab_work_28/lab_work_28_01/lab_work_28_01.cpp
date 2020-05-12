/**************************************************************/
/*                                                            */
/*  lab_work_28_01                                            */
/*  Мова: C++                                                 */
/*                                                            */
/*  Дружні функції.                                           */
/*  Завдання. Сформувати:                                     */
/* базовий клас Client та клас-нащадок Sort.                  */
/*  Для доступу до закритих елементів класів утворити такі    */
/* функції:                                                   */
/*  int funCF(Client &obC) - доступ до obC - закритого        */
/* елемента-об'єкта obC класу Client;                         */
/*  void funCSF(Client &obC, Sort &obS) - доступ до об'єкта   */
/* obc0 - закритого елемента класу Client та до функції swap  */
/* - закритого елемента класу Sort;                           */
/*  void Client::call(Sort &ob, int i, int j) - функція-      */
/* елемент класу Client, дружню до класу Sort.                */
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

class Sort;

// Оголошення базового класу Client
class Client {
private:
	client obc0;    // структурний об'єкт типу client

public:           // Вiдкритi елементи класу Client
	// Конструктор
	Client(int k) : k(k) {
	}
	~Client() {     // Деструктор
	}

	int k;          // Кількість банківських клієнтів
	client m[100];  // Масив структур типу client

	void enter();   // Функцiя введення даних
	void print();   // Функцiя виведення даних

	// Прототип функції, дружньої до Client
	friend int funCF(Client &);

	// Прототип функції, дружньої до Client та Sort
	friend void funCSF(Client &, Sort &);

	// Функція-елемент класу Client, дружня до Sort
	void call(Sort &, int, int);
};

// Оголошення класу Sort - нащадка класу Client
class Sort : public Client {
public:                // Відкриті елементи класу Sort
	// Конструктор
	Sort(int k = 3) : Client(k) {
	}
	~Sort() {            // Деструктор
	}

private:
	void swap(int, int); // Обмін значень

public:
	void sort(int);      // Сортування масиву

	// Прототип функції, дружньої до Client та Sort
	friend void funCSF(Client &, Sort &);

	// Функція-елемент класу Client, дружня до Sort
	friend void Client::call(Sort &, int, int);
};

// Опис функцій класу Client

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

// Опис дружнiх функцiй
// Доступ до obc0 - закритого елемента об'єкта obC класу Client
// Функцiя забезпечує:
// введення значень полiв однiєї структури obc0 об'єкта obC
// збереження сформованої структури в елементi масиву m[0]
// виведення значень полiв однiєї структури obc0 об'єкта obC
// перевiрку платоспроможностi клiєнта
int funCF(Client &obC) {
	cout << "Послiдовно введiть номер рахунку, прiзвище, баланс:" << endl;
	cout << "> ";
	cin >> obC.obc0.number;
	cout << "> ";
	cin.ignore();
	cin.getline(obC.obc0.name, sizeof(obC.obc0.name));
	cout << "> ";
	cin >> obC.obc0.balance;
	obC.m[0] = obC.obc0;
	obC.print();

	// Перевiрка платоспроможностi
	if (obC.m[0].balance < 0) {
		return -1;
	}
	if (obC.m[0].balance == 0) {
		return 0;
	}
	return 1;
}

// Доступ до об'єкта obc0 - закритого елемента класу Client
// та до функцiї swop - закритого елемента класу Sort // Функцiя забезпечує:
// введення значень полiв K структур obc0 об'єкта obC
// i їх збереження у масивi m[j] об'єкта obS
void funCSF(Client &obC, Sort &obS) {
	for (int j = 0; j < obS.k; ++j) {
		cout << "Послiдовно введiть номер рахунку, прiзвище, баланс:" << endl;
		cout << "> ";
		cin >> obC.obc0.number;
		cout << "> ";
		cin.ignore();
		cin.getline(obC.obc0.name, sizeof(obC.obc0.name));
		cout << "> ";
		cin >> obC.obc0.balance;
		obS.m[j] = obC.obc0;
	}
	cout << "Значення полiв структур об'єкта obS до обмiну:" << endl;
	obS.print();
	obS.swap(0, obS.k - 1);
	cout << "Значення полiв структур об'єкта obS пiсля обмiну:" << endl;
	obS.print();
}

// Функцiя-елемент класу Client
// Ця функцiя дружня до класу Sort
// Функцiя забезпечує:
// обмiн значень елементiв масиву m[i] та m[j]
// (структури об'єкта ob);
// виведення на друк полiв структури об'єкта ob пiсля цього обмiну
void Client::call(Sort &ob, int i, int j) {
	ob.swap(i,j);
	print();
}

int main() {
	Client obC(1);

	// Виклик дружньої функцiї: аргумент-об'єкт класу Client
	cout << "Демонстрацiя роботи дружньої функцiї funCF(obC):" << endl;
	if (funCF(obC) < 0) {
		cout << "  Клiєнт-боржник" << endl;
	} else {
		cout << "  Клiєнт-платоспроможний" << endl;
	}

	Sort obS;   // За замовчуванням аргумент дорiвнює 3

	cout << "Демонстрацiя роботи дружньої функцiї funCSF(obC, obS):" << endl;
	funCSF(obC, obS);
	cout << endl;

	// Виклик дружньої функцiї - елементу класу Client
	cout << "Демонстрацiя роботи дружньої функції obS.call(obS, 0, obS.k - 1):" << endl;
	obS.call(obS, 0, obS.k - 1);

	return 0;
}
