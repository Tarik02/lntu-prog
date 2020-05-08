/**************************************************************/
/*                                                            */
/*  z_7                                                       */
/*  Мова: C++                                                 */
/*                                                            */
/*  Створити клас для задання:                                */
/* 1. Прізвище.                                               */
/* 2. Дата народження.                                        */
/* 3. Адреса персони.                                         */
/*                                                            */
/*  Об'єкт ob1 створити за допомогою конструктора з           */
/* параметрами.                                               */
/*  Об'єкт ob2 створити за допомогою конструктора копіювання. */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <cstring>

using namespace std;


class Pupil {
public:
	Pupil(const char *n, const char *b, const char *a); // конструктор з параметрами
	Pupil(const Pupil &other); // конструктор копіювання
	~Pupil(); // деструктор

	void show(); // функція для виведення інформації

private:
	char *name, *birthday, *address;
};

// конструктор з параметрами
Pupil::Pupil(const char *n, const char *b, const char *a) {
	name = strdup(n);
	birthday = strdup(b);
	address = strdup(a);
}

// конструктор копіювання
Pupil::Pupil(const Pupil &other) {
	name = strdup(other.name);
	birthday = strdup(other.birthday);
	address = strdup(other.address);
}

// деструктор
Pupil::~Pupil() {
	free(name);
	free(birthday);
	free(address);
}

// функція для виведення інформації
void Pupil::show() {
	cout << "  Ім'я: " << name << endl;
	cout << "  Дата народження: " << birthday << endl;
	cout << "  Адреса: " << address << endl;
}

int main() {
	// об'єкт класу
	Pupil p1("Коля", "13 квітня 2004 року", "вул. Перемоги 4");

	// об'єкт класу, створений за допомогою конструктора копіювання
	Pupil p2 = p1;

	cout << "Початковий об'єкт класу:" << endl;
	p1.show();

	cout << endl;

	cout << "Об'єкт класу, створений за допомогою конструктора копіювання:" << endl;
	p2.show();

	return 0;
}
