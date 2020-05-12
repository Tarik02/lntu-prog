/**************************************************************/
/*                                                            */
/*  lab_work_26_01                                            */
/*  Мова: C++                                                 */
/*                                                            */
/*  Конструювання класів та об'єктів.                         */
/*  Завдання. Сконструювати структуру client з такими полями: */
/* int number - номер рахунку клієнта;                        */
/* char name[128] - прізвище клієнта;                         */
/* float balance - баланс клієнта.                            */
/*                                                            */
/*  Сконструювати клас Client з такими полями:                */
/* Закриті елементи класу:                                    */
/* client m[N] - масив структур типу client;                  */
/* void swop(int,int) - функцiя обмiну значень;               */
/* Вiдкритi елементи классу Client:                           */
/* Client() – конструктор класу;                              */
/* ~Client() - деструктор класу;                              */
/* void enter() - функцiя введення даних;                     */
/* void print() - функцiя виведення даних;                    */
/* void sort() - функцiя сортування даних;                    */
/* void sort1() - функцiя сортування даних з ручним вибором   */
/*                параметра сортування.                       */
/*                                                            */
/*  Доступ до елементiв класу Client здiйснитиза допомогою    */
/* об'єкта ob.                                                */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

const int N = 3; // Кiлькiсть банкiвських клiєнтiв

// Оголошення структури client
struct client {
	int number;      // Номер рахунку клієнта
	char name[128];  // Прiзвище клiента
	float balance;   // Баланс клієнта
};

// Оголошення базового класу Client
class Client {
private:               // Закритi елементи класу за замовчуванням
	client m[N];         // Масив структур типу client
	void swap(int, int); // Обмiн значенням

public:           // Вiдкритi елементи класу Client
	Client();       // Конструктор класу Client
	~Client();      // Деструктор класу Client
	void enter();   // Функцiя введення даних
	void print();   // Функцiя виведення даних
	void sort(int); // Сортування масиву
	void sort1();   // Сортування масиву з ручним введенням iндекса до 10 спроб i виведенням на екран
};

// Опис конструкторiв та деструкторiв класу Client
Client::Client() {
}

Client::~Client() {
}

// Опис iнших функцiй класу Client

// Функцiя обмiну значень комірок m[i] та m[j] масиву;
void Client::swap(int i, int j) {
	client c = m[i];
	m[i] = m[j];
	m[j] = c;
}

// Функцiя введення значень елементiв масиву структур
void Client::enter() {
	for (int i = 0; i < N; ++i) {
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
	for (int i = 0; i < N; ++i) {
		cout << "Структура N" << setw(3) << i + 1 << ":" << endl;
		cout << "  number =  " << m[i].number << endl;
		cout << "  name =    " << m[i].name << endl;
		cout << "  balance = " << setprecision(3) << m[i].balance << endl;
	}
	cout << endl;
}

// Функцiя сортування за ознакою ind значень елементiв массиву структур
void Client::sort(int ind) {
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
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
void Client::sort1() {
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
	Client ob;  //Об'єкт класу Client

	ob.enter(); //Введення значень елементiв масиву структур

	ob.print(); // Виведення значень елементiв масиву структур

	cout << "Результат роботи функцiї sort(2) яка сортує масив структур за параметром 2 (за iм'ям):" << endl;

	ob.sort(2); // Сорування значень елементiв масиву структур за ознакою 2

	ob.print(); // Виведення значень елементiв вiдсортованого масиву структур

	cout << "Результат роботи функцiї sort1()" << endl;
	cout << "Вибiр режиму сортування здiйснюється вручну" << endl;
	cout << "Для продовження натиснiть будь-яку клавiшу." << endl;

	ob.sort1(); // Виведення значень елементiв вiдсортованого масиву структур з ручним вибором режиму сортування

	return 0;
}
