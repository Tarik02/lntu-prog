/**********************************************************/
/*                                                        */
/*  lab_work_21_06                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Робота з функцiями для обробки символiв з бiблiотеки  */
/* обробки символів <cstdio>:                             */
/*   int getchar();                                       */
/*   int sprintf(char *s, const char *format, ...);       */
/*   int sscanf(const char *s, const char *format, ...);  */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	char c;
	char s[100]; // Задана стрiчка з 100 символiв
	int i = 0, len;

	cout << "Введiть стрiчку з 20 (або менше) символiв:" << endl << "  ";

	// Функцiя int getchar() вводить один символ зi
	// стандартного пристрою введення/виведення i повертає
	// його у формi цiлого
	while ((c = getchar()) != '\n') {
		s[i++] = c;
	}
	s[i] = '\0'; // В кiнцi додаємо завершальний нуль
	cout << "Введена посимвольно стрiчка:" << endl << "  ";
	puts(s);

	int x;
	double y;

	cout << "Введiть два числа - типу int та типу double:" << endl << "  ";
	cin >> x >> y;

	// Функцiя int sprintf(char *s, const char *format, ...)
	// еквiвалентна функцiї printf, однак вивiд здiснюється
	// в масив s, а не вiдображується на екранi
	sprintf(s, " цiле: %6d, дiйсне: %8.2f", x, y);
	cout << "Форматований вигляд вмiсту масиву s є таким:" << endl << "  " << s << endl;

	char s1[] = "31298 87.375";

	// Функцiя int sscanf(const char *s, const char *format, ...)
	// еквiвалентна функцiї scanf, однак ввiд здiснюється
	// з масиву s, а не з клавiатури
	sscanf(s1, "%d%lf", &x, &y);
	cout << "Величини, записанi в масивi s1, є такими:" << endl << "  ";
	cout << "ціле: " << x << ", з плаваючою комою: " << y << endl;

	return 0;
}
