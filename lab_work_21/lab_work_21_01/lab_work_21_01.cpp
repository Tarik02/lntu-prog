/**********************************************************/
/*                                                        */
/*  lab_work_21_01                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Робота з функцiями для обробки символiв з бiблiотеки  */
/* обробки символів <cctype>:                             */
/*  int isdigit(int c);                                   */
/*  int isalpha(int c);                                   */
/*  int isalnum(int c);                                   */
/*  int isxdigit(int c);                                  */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cctype>

using namespace std;

int main() {
	// int isdigit(int c) – повертає істинне значення, якщо с – ціла
	// цифра, і 0 - в протилежному випадку
	cout << "Демонструємо роботу з функцiєю isdigit:" << endl;
	cout << "  " << '8' << (isdigit('8') ? " є" : " не є") << " цифрою" << endl;
	cout << "  " << '#' << (isdigit('#') ? " є" : " не є") << " цифрою" << endl;

	// int isalpha(int c) – повертає істинне значення, якщо с –
	// буква, і 0 - в протилежному випадку
	cout << "Демонструємо роботу з функцiєю isalpha:" << endl;
	cout << "  " << 'A' << (isalpha('A') ? " є" : " не є") << " буквою" << endl;
	cout << "  " << 'b' << (isalpha('b') ? " є" : " не є") << " буквою" << endl;
	cout << "  " << '&' << (isalpha('&') ? " є" : " не є") << " буквою" << endl;
	cout << "  " << '4' << (isalpha('4') ? " є" : " не є") << " буквою" << endl;

	// int isalnum(int c) – повертає істинне значення, якщо с – ціла
	// цифра або буква, і 0 - в протилежному випадку
	cout << "Демонструємо роботу з функцiєю isalnum:" << endl;
	cout << "  " << 'A' << (isalnum('A') ? " є" : " не є") << " цифрою або буквою" << endl;
	cout << "  " << '8' << (isalnum('8') ? " є" : " не є") << " цифрою або буквою" << endl;
	cout << "  " << '#' << (isalnum('#') ? " є" : " не є") << " цифрою або буквою" << endl;

	// int isxdigit(int c) – повертає істинне значення, якщо с –
	// шістнадцяткова цифра, і 0 - в протилежному випадку
	cout << "Демонструємо роботу з функцiєю isxdigit:" << endl;
	cout << "  " << 'F' << (isxdigit('F') ? " є" : " не є") << " шістнадцятковою цифрою" << endl;
	cout << "  " << 'J' << (isxdigit('J') ? " є" : " не є") << " шістнадцятковою цифрою" << endl;
	cout << "  " << '7' << (isxdigit('7') ? " є" : " не є") << " шістнадцятковою цифрою" << endl;
	cout << "  " << '$' << (isxdigit('$') ? " є" : " не є") << " шістнадцятковою цифрою" << endl;
	cout << "  " << 'f' << (isxdigit('f') ? " є" : " не є") << " шістнадцятковою цифрою" << endl;

	return 0;
}
