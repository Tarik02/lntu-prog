/*************************************************************/
/*                                                           */
/*  z_6                                                      */
/*  Мова: C++                                                */
/*                                                           */
/*  Введення даних студентів:                                */
/* - номер;                                                  */
/* - прізвище;                                               */
/* - середній бал.                                           */
/*  Файл має мiстити записи з такими полями:                 */
/* - номер рахунку;                                          */
/* - прiзвище власника;                                      */
/* - борг.                                                   */
/*                                                           */
/*************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>

using namespace std;

struct student_t {
	int number;
	string name;
	double rating;
};

vector<student_t> input_students(); // функція для вводу списку студентів
student_t input_student(); // функція для вводу студента
void output_students(const vector<student_t> &students); // функція для виводу списку студентів
void output_student(const student_t &student); // функція для виводу студента

int main() {
	vector<student_t> students = input_students();

	output_students(students);

	return 0;
}

// функція для вводу списку студентів
vector<student_t> input_students() {
	vector<student_t> result;
	int n;

	cout << "Введіть кількість студентів:" << endl << "> ";
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		result.push_back(input_student());
	}

	return result;
}

// функція для вводу студента
student_t input_student() {
	student_t s;
		
	cout << "Введіть номер студента:" << endl << "> ";
	cin >> s.number;

	cout << "Введіть прізвище студента:" << endl << "> ";
	cin.ignore();
	getline(cin, s.name);

	cout << "Введіть середній бал студента:" << endl << "> ";
	cin >> s.rating;

	return s;
}

// функція для виводу списку студентів
void output_students(const vector<student_t> &students) {
	cout << "Список студентів:" << endl;

	int i = 0;
	for (const student_t &s : students) {
		cout << ++i << ":" << endl;
		output_student(s);
	}
}

// функція для виводу студента
void output_student(const student_t &student) {
	cout << "  Номер: " << student.number << endl;
	cout << "  Прізвище: " << student.name << endl;
	cout << "  Середній бал: " << student.rating << endl;
}
