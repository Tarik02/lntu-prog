/**********************************************************/
/*                                                        */
/*  lab_work_21_04                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Робота з функцiями для обробки символiв з бiблiотеки  */
/* обробки символів <cstdlib>:                            */
/*  double atof(const char *nPtr);                        */
/*  int    atoi(const char *nPtr);                        */
/*  long   atol(const char *nPtr);                        */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	// Функцiя double atof(const char *nPtr) перетворює
	// стрiчку nPtr в число типу double:
	double d = atof("99.0");
	cout << "Стрiчка \"99.0\", перетворена у число типу double: " << d << endl;
	cout << "  Отримане число, роздiлене на 2, дорiвнює: " << (d / 2) << endl;

	// Функцiя int atoi(const char *nPtr) перетворює
	// стрiчку nPtr в число типу int:
	int i = atoi("2593");
	cout << "Стрiчка \"2593\", перетворена у число типу int: " << i << endl;
	cout << "  Отримане число мiнус 593, дорiвнює: " << (i - 593) << endl;

	// Функцiя long atol(const char *nPtr) перетворює
  // стрiчку nPtr в число типу long:
	long l = atol("1000000");
	cout << "Стрiчка \"1000000\", перетворена у число типу long: " << l << endl;
	cout << "  Отримане число, роздiлене на 2, дорiвнює: " << (l / 2) << endl;

	return 0;
}
