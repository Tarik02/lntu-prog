/**********************************************************/
/*                                                        */
/*  lab_work_21_05                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Робота з функцiями для обробки символiв з бiблiотеки  */
/* обробки символів <cstdio>:                             */
/*   char *gets(char *s);                                 */
/*   int puts(const char *s);                             */
/*   int putchar(int c);                                  */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void reverse(const char *const sPtr);

int main() {
	char s[20]; // Задана стрiчка з 20 символiв
	int i, len;

	// Функцiя char *gets(char *s) вводить символи зi
	// стандартного пристрою вводу/виводу у символьний масив s
	// до тих пiр, поки не зустрiне символ нової стрiчки
	// або iндикатор кiнця файлу. Пiсля цього до масиву s
	// додає завершальний нуль
	cout << "Введiть стрiчку i натиснiть клавiшу Ввiд:" << endl << "  ";
	gets(s);
	len = strlen(s); // len – довжина стрічки s

	// Функцiя int putchar(const char *s) друкує один символ // зi стрiчки s
	cout << "Посимвольний друк стрiчки s:" << endl << "  ";
	for (i = 0; i < len; ++i) {
		putchar(s[i]);
	}
	cout << endl;

	// Функцiя int puts(const char *s) друкує всю стрiчку s
	// відразу i переводить курсор на початок нової стрiчки
	cout << "Друк всiєї стрiчки s вiдразу i перевід курсора на початок нової стрiчки:" << endl << "  ";
	puts(s);

	cout << "Друк стрiчки у зворотному порядку:" << endl << "  ";
	reverse(s);
	cout << endl;

	return 0;
}

//----------------------------------------------------
// Інверсія стрічки

void reverse(const char *const sPtr) {
	if (sPtr[0] == '\0') {
		return;
	}

	reverse(&sPtr[1]);
	putchar(sPtr[0]);
}
