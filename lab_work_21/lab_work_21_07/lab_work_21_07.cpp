/***********************************************************************/
/*                                                                     */
/*  lab_work_21_07                                                     */
/*  Мова: C++                                                          */
/*                                                                     */
/*  Робота з функцiями для обробки символiв з бiблiотеки               */
/* обробки символів <cstdlib>:                                         */
/*   double strtod(const char *nPtr,char **endPtr);                    */
/*   long strtol(const char *nPtr, char **endPtr, int base);           */
/*   unsigned long strtoul(const char *nPtr, char **endPtr, int base); */
/*                                                                     */
/***********************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	{
		// Функцiя double strtod(const char *nPtr, char **endPtr)
		// перетворює стрiчку nPtr в число типу double:
		const char *str = "51.2 % вiд кiлькостi учнiв";
		char *strPtr; // Вказiвник на char

		// Змiнна для запам'ятовування результату перетворення:
		double v = strtod(str, &strPtr);

		cout << "Стрiчка \"" << str << "\" конвертується на двi частини:" << endl;
		cout << "  Число " << v << " типу double та стрiчку \"" << strPtr << "\"" << endl;
	}

	{
		// Функцiя long strtol(const char *nPtr, char **endPtr, int base)
		// перетворює стрiчку nPtr в число типу long:
		const char *str = "-1234567abc";
		char *strPtr; // Вказiвник на char

		// Змiнна для запам'ятовування результату перетворення:
		long v = strtol(str, &strPtr, 0);

		cout << "Стрiчка \"" << str << "\" конвертується на двi частини:" << endl;
		cout << "  Число " << v << " типу long та стрiчку \"" << strPtr << "\"" << endl;
	}

	{
		// Функцiя unsigned long strtoul(const char *nPtr, char **endPtr, int base)
		// перетворює стрiчку nPtr в число типу unsigned long:
		const char *str = "1234567abc";
		char *strPtr; // Вказiвник на char

		// Змiнна для запам'ятовування результату перетворення:
		long v = strtoul(str, &strPtr, 0);

		cout << "Стрiчка \"" << str << "\" конвертується на двi частини:" << endl;
		cout << "  Число " << v << " типу unsigned long та стрiчку \"" << strPtr << "\"" << endl;
	}

	return 0;
}
