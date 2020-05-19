/**********************************************************/
/*                                                        */
/*  lab_work_22_01                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Робота з функцiями для обробки символiв з бiблiотеки  */
/* обробки символів <cstring>:                            */
/*  char *strcpy(char *s1, const char *s2);               */
/*  char *strncpy(char *s1, const char *s2, size_t n);    */
/*  char *strcat(char *s1, const char *s2);               */
/*  char *strncat(char *s1, const char *s2, size_t n);    */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	char x[] = "Щасливого Вам Нового року!";
	char y[100];
	char z[100];

	cout << "Демонструємо роботу функцiй, якi копiюють стрiчки:" << endl;

	// Функцiя char *strcpy(char *s1, const char *s2)
	// копiює стрiчку s2 в масив s1. Повертає стрiчку s1:
	cout << "Стрiчка в масивi x є такою: " << endl << "  " << x << endl;
	cout << "Стрiчка в масивi y є такою: " << endl << "  " << strcpy(y, x) << endl;

	// Функцiя char *strncpy(char *s1, const char *s2, size_t n)
	// копiює не більше, ніж n символів зі стрiчки s2 в масив s1.
	// Повертає стрiчку s1:
	strncpy(z, x, 16);
	z[16] = '\0';
	cout << "Стрiчка в масивi z є такою:" << endl << "  " << z << endl;

	cout << "Демонструємо роботу функцiй, якi об'єднують стрiчки:" << endl;

	char s1[20] = "Happy ";
	char s2[] = "New Year";
	char s3[40] = "";
	cout << "  s1 = " << s1 << endl;
	cout << "  s2 = " << s2 << endl;

	// Функцiя char *strcat(char *s1, const char *s2)
	// об'єднує стрiчку s2 зi стрiчкою масиву s1.
	// Перший символ стрiчки s2 переписує символ NULL.
	// Повертає стрiчку s1:
	cout << "  strcat(s1, s2) = " << strcat(s1, s2) << endl;

	// Функцiя char *strncat(char *s1, const char *s2, size_t n)
	// об'єднує не бiльше, нiж n символiв стрiчки s2, зi стрiчкою s1.
	// Перший символ стрiчки s2 переписує символ NULL.
	// Повертає стрiчку s1:
	cout << "  strncat(s3, s1, 6) = " << strncat(s3, s1, 6) << endl;
	cout << "  strcat(s3, s1) = " << strcat(s3, s1) << endl;

	return 0;
}
