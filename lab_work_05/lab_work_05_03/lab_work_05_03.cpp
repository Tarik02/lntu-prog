
/*******************************************************/
/*                                                     */
/*  lab_work_05_03                                     */
/*  Мова: C++                                          */
/*                                                     */
/*    Обчислення значення складної функції засобами    */
/*  мови C++.                                          */
/*    Обчислити значення складної функції y:           */
/*  y = pow((x*x + a*b*a*b + 1)                        */
/*    / (abs(a*x) + 1), 1.0f/8), якщо      a*x <  0    */
/*  y = pow(log(a*x + 1), 2),    якщо 0 <= a*x <  4    */
/*  y = pow(cos(a + pow(x*x, 1.0f/3)), 2),             */
/*                               якщо      a*x >= 4    */
/*    Розгалужені процеси реалізувати командою if.     */
/*                                                     */
/*******************************************************/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

int main() {
	float a;  // Параметр a
	float b;  // Параметр b
	float x;  // Аргумент функції
	float y;  // Значення функції

	clrscr();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Ввід значення аргумента:
	printf("\n  Введіть значення параметра a: ");
	scanf("%f", &a);
	printf("\n  Введіть значення параметра b: ");
	scanf("%f", &b);
	printf("\n  Введіть значення аргумента: ");
	scanf("%f", &x);

	// Обчислення значення складної функції:
	if (a*x < 0) { // Перша гілка:
		y = pow((x*x + a*b*a*b + 1) / (abs(a*x) + 1), 1.0f/8);
		printf("  x=%4.2f    y=%4.2f\n", x, y);
	} else if (0 <= a*x && a*x < 4) { // Друга гілка:
		y = pow(log(a*x + 1), 2);
		printf("  x=%4.2f    y=%4.2f\n", x, y);
	} else if (a*x >= 4) { // Третя гілка:
		y = pow(cos(a + pow(x*x, 1.0f/3)), 2);
		printf("  x=%4.2f    y=%4.2f\n", x, y);
	} else {
		printf("  x=%4.2f    функція не існує.\n", x);
	}

	getch();

	return 0;
}
