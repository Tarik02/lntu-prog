﻿/*******************************************************/
/*                                                     */
/*  lab_work_09_03                                     */
/*  Мова: C                                            */
/*                                                     */
/*    Підрахувати кількість цифр у заданому            */
/*  натуральному числі.                                */
/*    Циклічні процеси реалізувати командою do.        */
/*                                                     */
/*******************************************************/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

int main() {
	int n;      // число
	int i;
	int k = 0;  // кількість цифр у числі

	clrscr();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Введіть число n: ");
	scanf("%d", &n);

	i = n;
	do {
		++k;
		i /= 10;
	} while (i != 0);

	printf("Кількість цифр у числі %d: %d\n", n, k);

	getch();

	return 0;
}