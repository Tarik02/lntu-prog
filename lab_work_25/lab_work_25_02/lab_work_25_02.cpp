/**************************************************************/
/*                                                            */
/*  lab_work_25_02                                            */
/*  Мова: C++                                                 */
/*                                                            */
/*  Конструювання класів та об'єктів засобами мови C++.       */
/*  Завдання. Сформувати клас FootTeam з такими елементами:   */
/*   Закриті поля класу:                                      */
/*  - char title[64] - назва команди;                         */
/*  - char best_player[64] - прізвище кращого гравця;         */
/*  - char country[64] - країна;                              */
/*  - int rating - рейтинг;                                   */
/*   Відкриті методи класу:                                   */
/*  - FootTeam(char *, char *, int, char *) - конструктор;    */
/*  - FootTeam() - конструктор;                               */
/*  - void show() - вивести на друк дані про команду.         */
/*  Передбачити різні форми звертання до об'єктів класу.      */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class FootTeam {
public:
	FootTeam(char *, char *, int, char *);
	FootTeam();

	void show();

private:
	char title[64];
	char best_player[64];
	char country[64];
	int rating;
};

FootTeam::FootTeam(char *t, char *c, int r, char *b) {
	strcpy(title, t);
	strcpy(country, c);
	rating = r;
	strcpy(best_player, b);
}

FootTeam::FootTeam() {
	rating = 118;
	strcpy(title, "Зоря Луганськ");
	strcpy(country, "Україна");
	strcpy(best_player, "Тьоркiн");
}

void FootTeam::show() {
	cout << "Назва команди: " << title << endl;
	cout << "Країна: " << country << endl;
	cout << "Рейтинг команди: " << rating << endl;
	cout << "Кращий гравець: " << best_player << endl;
}

int main() {
	FootTeam d1("Барселона", "Iспанiя", 1, "Mеcci");
	FootTeam d2("Динамо Киiв", "Україна", 32, "Блохiн");
	FootTeam d3;

	d1.show();

	cout << endl;

	d2.show();

	cout << endl;

	d3.show();

	return 0;
}
