/***********************************************************/
/*                                                         */
/*  lab_work_22_02                                         */
/*  Мова: C++                                              */
/*                                                         */
/*  Робота з функцiями порівняння стрічок з бiблiотеки     */
/* обробки символів <cstring>:                             */
/*  int strcmp(const char *s1, const char *s2);            */
/*  int strncmp(const char *s1, const char *s2, size_t n); */
/*                                                         */
/***********************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	const char *s1 = "Happy New Year";
	const char *s2 = "Happy New Year";
	const char *s3 = "Happy Holidays";

	cout << "Задано такі стрічки:" << endl;
	cout << "  s1 = " << s1 << endl;
	cout << "  s2 = " << s2 << endl;
	cout << "  s3 = " << s3 << endl;

	// Функцiя int strcmp(const char *s1, const char *s2)
	// порiвнює стрiчку s1 зi стрiчкою s2. Повертає значення:
	// менше нуля - якщо s1 менше за s2;
	// нуль - якщо s1 дорiвнює s2;
	// бiльше нуля - якщо s1 бiльше за s2;

	cout << "strcmp:" << endl;
	cout << "  strcmp(s1, s2) = " << strcmp(s1, s2) << endl;
	cout << "  strcmp(s1, s3) = " << strcmp(s1, s3) << endl;
	cout << "  strcmp(s3, s1) = " << strcmp(s3, s1) << endl;

	// Функцiя int strncmp(const char *s1, const char *s2)
	// порiвнює не бiльше, нiж n символiв стрiчки s1,
	// зi стрiчкою s2. Повертає значення:
	// менше нуля - якщо s1 менше за s2;
	// нуль - якщо s1 дорiвнює s2;
	// бiльше нуля - якщо s1 бiльше за s2;

	cout << "strncmp:" << endl;
	cout << "  strncmp(s1, s2, 6) = " << strncmp(s1, s2, 6) << endl;
	cout << "  strncmp(s1, s3, 7) = " << strncmp(s1, s3, 7) << endl;
	cout << "  strncmp(s3, s1, 7) = " << strncmp(s3, s1, 7) << endl;

	return 0;
}
