/***********************************************************/
/*                                                         */
/*  lab_work_22_04                                         */
/*  Мова: C++                                              */
/*                                                         */
/*  Функцiя пошуку з бiблiотеки обробки стрiчок <cstring>: */
/*                                                         */
/*  char *strchr(const char *s, int c);                    */
/*                                                         */
/*  size_t strcspn(const char *s1, const char *s2);        */
/*                                                         */
/*  size_t strspn(const char *s1, const char *s2);         */
/*                                                         */
/*  char *strprbk(const char *s1, const char *s2);         */
/*                                                         */
/*  char *strrchr(const char *s, int c);                   */
/*                                                         */
/*  char *strstr(const char *s1, const char *s2);          */
/*                                                         */
/*  char *strtok(const char *s1, const char *s2);          */
/*                                                         */
/***********************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Функцiя char *strchr(const char *s, int c) знаходить
// позицiю першого входження символа с у стрiчку s.
// Якщо с знайдено, повертає вказiвник на с в стрiчцi s.
// Iнакше повертається вказiвник зi значенням NULL.
void test_strchr() {
	const char *s1 = "This is a const pointer to a char";
	char c1 = 'a';// змiнна типу char
	char c2 = 'b'; // змiнна типу char

	cout << "Демонструємо роботу функцiї char *strchr(const char *s, int c):" << endl;

	if (strchr(s1, c1) != NULL) {
		cout << "  Символ '" << c1 << "' входить в стрічку \"" << s1 << "\"." << endl;
	} else {
		cout << "  Символ '" << c1 << "' не входить в стрічку \"" << s1 << "\"." << endl;
	}

	if (strchr(s1, c2) != NULL) {
		cout << "  Символ '" << c2 << "' входить в стрічку \"" << s1 << "\"." << endl;
	} else {
		cout << "  Символ '" << c2 << "' не входить в стрічку \"" << s1 << "\"." << endl;
	}
}

// Функцiя size_t strcspn(const char *s1, const char *s2)
// визначає i повертає довжину початкового сегмента стрiчки s1,
// який мiстить лише тi символи, якi не входять у стрiчку s2.
void test_strcspn() {
	const char *s1 = "The value is 3.14159"; // вказiвник-константа на char
	const char *s2 = "i1234567890"; // вказiвник-константа на char

	cout << "Демонструємо роботу функцiї size_t strcspn(const char *s1, const char *s2):" << endl;
	cout << "  s1 = " << s1 << endl;
	cout << "  s2 = " << s2 << endl;
	cout << "  Довжина початкового сегмента стрiчки s1, який мiстить тiльки тi символи, що не входять у стрiчку s2:" << endl;
	cout << "    " << strcspn(s1, s2) << endl;
}

// Функцiя size_t strspn(const char *s1, const char *s2)
// визначає i повертає довжину початкового сегмента стрiчки s1,
// який мiстить лише тi символи, якi входять у стрiчку s2.

// Функцiя char *strprbk(const char *s1, const char *s2) знаходить
// позицiю першого входження будь-якого символа стрiчки s2
// у стрiчцi s1. Якщо символ стрiчки s2 знайдено, функцiя повертає
// вказiвник на цей символ у стрiчцi s1.
// Iнакше повертається вказiвник зi значенням NULL.

// Функцiя char *strrchr(const char *s,int c ) знаходить
// позицiю позицiю останнього входження символа с у стрiчку s.
// Якщо символ c знайдено, функцiя повертає
// вказiвник на цей символ у стрiчцi s.
// Iнакше повертається вказiвник зi значенням NULL.

// Функцiя char *strstr(const char *s1, const char *s2) знаходить
// позицiю першого входження стрiчки s2 у стрiчцi s1.
// Якщо пiдстрiчка знайдена, повертає вказiвник пiдстрiчки у стрiчцi s1.
// Iнакше повертається вказiвник зi значенням NULL.

// Функцiя char *strtok(const char *s1, const char *s2) дiлить
// стрiчку s1 на лексеми, роздiленi мiж собою символами стрiчки s2.
// Пiд час першого виклику функцiя отримує як аргумент стрiчку s1.
// У наступних викликах функцiї для розбиття тiєї ж самої стрiчки s1
// на лексеми, як перший аргумент передається NULL.
// Пiд час кожного виклику функцiї повертається вказiвник на поточну
// лексему стрiчки s1. Якщо за чергового виклику функцiї з'ясовується,
// що лексем бiльше немає, повертається вказiвник зi значенням NULL:

int main() {
	test_strchr();

	test_strcspn();

	return 0;
}
