/**************************************************************/
/*                                                            */
/*  lab_work_25_03                                            */
/*  Мова: C++                                                 */
/*                                                            */
/* Констуювання класiв та об'єктiв засобами мови С++.         */
/* Завдання. Сформувати клас Faculty з такими компонентами:   */
/*  Закритi компоненти класу:                                 */
/* - char title[64] - назва факультету;                       */
/* - int students_cnt - кiлькiсть студентiв;                  */
/* - int out_students_cnt - кiлькiсть вибувших студентiв;     */
/*  Вiдкритi елементи класу:                                  */
/* - Faculty(char *, int, int) - конструктор;                 */
/* - Faculty(char *, int) - конструктор;                      */
/* - Faculty() - конструктор;                                 */
/* - void get_title(char *t) - повернення назви;              */
/* - void set_title(char *t) - збереження назви;              */
/* - int get_students_cnt() - кількість студентів;            */
/* - void set_students_cnt(int k) - збереження ксті. студ.;   */
/* - int get_out_students_cnt() - кiлькость вибувших студ.;   */
/* - void set_out_students_cnt(int kv) - збереження;          */
/* - void print() - друк результатiв.                         */
/*  Передбачити різні форми звертання до об'єктів класу.      */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Faculty {
private:
	char title[64];
	int students_cnt;
	int out_students_cnt;

public:
	Faculty(char *, int, int);
	Faculty(char *, int);
	Faculty();
	void get_title(char *t);
	void set_title(char *t);
	int get_students_cnt();
	void set_students_cnt(int k);
	int get_out_students_cnt();
	void set_out_students_cnt(int kv);
	void print();
};

Faculty::Faculty(char *t, int s, int o) {
	strcpy(title, t);
	students_cnt = s;
	out_students_cnt = o;
}

Faculty::Faculty(char *t, int s) {
	strcpy(title, t);
	students_cnt = s;
	out_students_cnt = 0;
}

Faculty::Faculty() {
	strcpy(title, "");
	students_cnt = 0;
	out_students_cnt = 0;
}

void Faculty::get_title(char *t) {
	strcpy(t, title);
}

void Faculty::set_title(char *t) {
	strcpy(title, t);
}

int Faculty::get_students_cnt() {
	return students_cnt;
}

void Faculty::set_students_cnt(int k) {
	students_cnt = k;
}

int Faculty::get_out_students_cnt() {
	return out_students_cnt;
}

void Faculty::set_out_students_cnt(int kv) {
	out_students_cnt = kv;
}

void Faculty::print() {
	cout << "  Назва факультету:             " << title << endl;
	cout << "  Загальна кiлькiсть студентiв: " << students_cnt << endl;
	cout << "  Загальна вибувших студентiв:  " << out_students_cnt << endl;
}


int main() {
	int k, kv, a[3], m;
	char s[70];
	cout << "Передача даних через конструктор з трьома параметрами." << endl;
	cout << "Всi три параметри - константи:" << endl;

	Faculty d1("ФКНIT", 10, 2);
	d1.print();


	cout << endl;


	cout << "Передача даних через конструктор з трьома параметрами." << endl;
	cout << "Перший параметр - константа, а два iншi параметри мають бути введенi з клавiатури:" << endl;
	cout << "  Факультет ФБ." << endl;
	cout << "  Введiть загальну кiлькiсть студентiв: ";
	cin >> k;
	cout << "  Введiть кiлькiсть вибувших студентiв: ";
	cin >> kv;

	Faculty d2("ФБ", k, kv);
	d2.print();


	cout << endl;


	cout << "Передача даних через конструктор з трьома параметрами." << endl;
	cout << "Перший параметр - константа, а два iншi параметри мають бути введенi з клавiатури:" << endl;
	cout << "  Факультет ФОФ." << endl;
	cout << "  Введiть загальну кiлькiсть студентiв: ";
	cin >> k;
	cout << "  Введiть кiлькiсть вибувших студентiв: ";
	cin >> kv;

	Faculty d3("ФОФ", k, kv);
	d3.print();


	cout << endl;

	
	cout << "Передача даних через конструктор з двома параметрами." << endl;
	cout << "Перший параметр - константа, а другий параметр має бути введений з клавiатури:" << endl;
	cout << "  Факультет МБФ." << endl;
	cout << "  Введiть загальну кiлькiсть студентiв:";
	cin >> k;

	Faculty d4("МБФ", k);
	d4.print();

	cout << "Кiлькiсть вибувших студентiв - неправильна!" << endl;
	cout << "У функцiю d4.print передано два параметри, а треба три!" << endl;
	cout << "Додатково введiть кiлькiсть вибувших студентiв: ";
	cin >> kv;
	d4.set_out_students_cnt(kv);
	d4.print();

	cout << "Тепер всi данi правильнi!" << endl;

	
	cout << endl;


	cout << "Передача даних через конструктор без параметрiв." << endl;
	cout << "Всi аргументи функцiї d5.print() мають бути введені поза конструктором." << endl;

	Faculty d5;

	cout << "  Введiть назву факультету:             ";
	cin.ignore();
	cin.getline(s, sizeof(s));
	cout << "  Введiть загальну кiлькiсть студентiв: ";
	cin >> k;
	cout << "  Введiть кiлькiсть вибувших студентiв: ";
	cin >> kv;

	d5.set_title(s);
	d5.set_students_cnt(k);
	d5.set_out_students_cnt(kv);
	d5.print();


	cout << endl;


	cout << "Передача даних через конструктор з трьома параметрами." << endl;
	cout << "Перший параметр - константа, а два iншi параметри мають бути введенi з клавiатури:" << endl;
	cout << "  Факультет ФЕПЕС." << endl;
	cout << "  Введiть загальну кiлькiсть студентiв: ";
	cin >> k;
	cout << "  Введiть кiлькiсть вибувших студентiв: ";
	cin >> kv;

	Faculty d6("ФЕПЕС", k, kv);
	d6.print();
	cout << "Загальна кiлькiсть студентiв: " << d6.get_students_cnt() << endl;
	cout << "(Визначено за допомогою функцiї d6.get_students_cnt())" << endl;


	cout << endl;


	// Створення динамiчного масиву
	// Доступ до об'єктiв здiйснюється за допомогою вказiвника
	cout << "Обробка даних по трьох факультетах:" << endl;
	Faculty *d7 = new Faculty[3];
	m = 0;

	for (int i = 0; i < 3; ++i) {
		cout << "  Введiть назву " << i +1 << "-го факультету: ";
		cin.ignore();
		cin.getline(s, sizeof(s));
		cout << "  Введiть кiлькiсть студентiв: ";
		cin >> k;
		cout << "  Введiть кiлькiсть вибувших студентiв: ";
		cin >> kv;
		d7[i].set_title(s);
		d7[i].set_students_cnt(k);
		d7[i].set_out_students_cnt(kv);
	}
	
	for (int i = 0; i < 3; ++i) {
		d7[i].print();
		m += d7[i].get_out_students_cnt();
	}

	cout << "Всього вибувших студентiв: " << m << endl;

	return 0;
}
