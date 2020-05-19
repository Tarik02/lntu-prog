/***********************************************************/
/*                                                         */
/*  lab_work_22_03                                         */
/*  Мова: C++                                              */
/*                                                         */
/*  Функцiя визначення довжини стрiчки з бiблiотеки        */
/* обробки стрiчок <cstring>:                              */
/*  size_t strlen(const char *s);                          */
/*                                                         */
/*  Функцiя визначає довжину стрiчки s. Повертає кiлькiсть */
/* символiв, якi передують завершальному нулю.             */
/*                                                         */
/***********************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	// s1 - Задана стрiчка, довжину якої визначаємо:
	const char *s1 = "Це стрiчка-тест на функцiю strlen";

	// s2 - Ще одна стрiчка, довжину якої визначаємо:
	const char *s2 = "123456789";

	// s3 - Ще одна стрiчка, довжину якої визначаємо:
	const char *s3 = "";

	int len1, len2, len3; // довжини вiдповiдних стрiчок

	cout << "Задано такі стрічки:" << endl;
	cout << "  s1 = " << s1 << endl;
	cout << "  s2 = " << s2 << endl;
	cout << "  s3 = " << s3 << endl;

	cout << "Демонструємо роботу функцiї size_t strlen(const char *s):" << endl;

	len1 = strlen(s1);
	len2 = strlen(s2);
	len3 = strlen(s3);

	cout << "  strlen(s1) = " << len1 << endl;
	cout << "  strlen(s2) = " << len2 << endl;
	cout << "  strlen(s3) = " << len3 << endl;

	return 0;
}
