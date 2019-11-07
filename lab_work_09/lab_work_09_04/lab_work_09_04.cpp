/*******************************************************/
/*                                                     */
/*  lab_work_09_04                                     */
/*  Мова: C++                                          */
/*                                                     */
/*    Підрахувати кількість цифр у заданому            */
/*  натуральному числі.                                */
/*    Циклічні процеси реалізувати командою do.        */
/*                                                     */
/*******************************************************/

#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
using namespace std;

int main() {
	int n;      // число
	int i;
	int k = 0;  // кількість цифр у числі

	clrscr();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введіть число n: ";
	cin >> n;

	i = n;
	do {
		++k;
		i /= 10;
	} while (i != 0);

	cout << "Кількість цифр у числі " << n << ": " << k << "\n";

	getch();

	return 0;
}
