/**************************************************************/
/*                                                            */
/*  z_9                                                       */
/*  Мова: C++                                                 */
/*                                                            */
/*  Створити клас у якому здійсьнються введенняя масиву       */
/* структур з інформацією про школярів:                       */
/*  1. ПІБ.                                                   */
/*  2. Номер школи.                                           */
/*  3. Назва класу.                                           */
/* Завдання. Відсортувати по вказаному полю.                  */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

struct Student {
	char full_name[128];
	char school_name[128];
	char class_name[128];
};

class StudentsCollection {
private:
	int count;
	Student *students;

public:
	StudentsCollection();
	~StudentsCollection();

private:
	void swap(int i, int j);

public:
	void input();
	void output();
	void sort(int field);
};

StudentsCollection::StudentsCollection() {
	count = 0;
	students = new Student[0];
}

StudentsCollection::~StudentsCollection() {
	delete[] students;
}

void StudentsCollection::swap(int i, int j) {
	Student tmp = students[i];
	students[i] = students[j];
	students[j] = tmp;
}

void StudentsCollection::input() {
	cout << "Введіть кількість учнів:" << endl << "> ";
	cin >> count;

	delete[] students;
	students = new Student[count];

	cin.ignore();

	for (int i = 0; i < count; ++i) {
		cout << "Учень №" << i + 1 << ":" << endl;

		cout << "  ПІБ:         ";
		cin.getline(students[i].full_name, sizeof(students[i].full_name));

		cout << "  Назва школи: ";
		cin.getline(students[i].school_name, sizeof(students[i].school_name));

		cout << "  Назва класу: ";
		cin.getline(students[i].class_name, sizeof(students[i].class_name));
	}
}

void StudentsCollection::output() {
	cout << "Учні:" << endl;

	for (int i = 0; i < count; ++i) {
		cout << "- ПІБ:         " << students[i].full_name << endl;
		cout << "  Назва школи: " << students[i].school_name << endl;
		cout << "  Назва класу: " << students[i].class_name << endl;
	}
}

void StudentsCollection::sort(int field) {
	for (int i = 0; i < count - 1; ++i) {
		for (int j = i + 1; j < count; ++j) {
			switch (field) {
				case 1:
					if (strcmp(students[i].full_name, students[j].full_name) > 0) {
						swap(i, j);
					}
					break;
				case 2:
					if (strcmp(students[i].school_name, students[j].school_name) > 0) {
						swap(i, j);
					}
					break;
				case 3:
					if (strcmp(students[i].class_name, students[j].class_name) > 0) {
						swap(i, j);
					}
					break;
			}
		}
	}
}

int main() {
	StudentsCollection collection;
	
	collection.input();
	cout << endl;

	collection.output();
	cout << endl;

	while (true) {
		int field = -1;

		cout << "Введіть поле для сортування або 0 для виходу:" << endl;
		cout << "  1 - ПІБ;" << endl;
		cout << "  2 - Назва школи;" << endl;
		cout << "  3 - Назва класу;" << endl;
		cout << "> ";
		cin >> field;

		if (field == 0) {
			return 0;
		}

		if (field < 1 || field > 3) {
			continue;
		}

		collection.sort(field);
		collection.output();
		cout << endl;
	}

	return 0;
}
