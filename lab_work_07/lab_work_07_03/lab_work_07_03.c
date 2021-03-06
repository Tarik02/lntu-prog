﻿/*******************************************************/
/*                                                     */
/*  lab_work_07_03                                     */
/*  Мова: C                                            */
/*                                                     */
/*    Табулювання функції на інтервалі засобами мови   */
/*  C. Обчислити всі значення функції                  */
/*  y = (pow(cos(a*x), 2) + exp(-a*x)) /            */
/*    (pi*2 - atan(sqrt(b) + sqrt(x))), аргумент x     */
/*  якої змінюється на інтервалі [0.6;0.8] з кроком    */
/*  h=0.02, a=1.3, b=0.75                              */
/*  Обчислити також:                                   */
/*   * кількість значень y<2.75                        */
/*   * кількість значень y>2.75                        */
/*  Циклічні процеси реалізувати командою for.         */
/*                                                     */
/*******************************************************/

#include <stdio.h>
#include <math.h>

#define pi 3.14159f

int main() {
	float a = 1.3f;
	float b = 0.75f;

	float x;      // Аргумент функції
	float y;      // Значення функції
	int k1 = 0;   // кількість значень y<2.75
	int k2 = 0;   // кількість значень y>2.75

	// Табулювання функції на заданому інтервалі
	// з одночасним обчисленням кількісті k та суми s:
	printf("\n  Результати табулювання функції:\n");

	for (x = 0.6f; x <= 0.8f; x += 0.02f) {
		y = (pow(cos(a*x), 2) + exp(-a*x)) / (pi*2 - atan(sqrt(b) + sqrt(x)));
		printf("  x=%+4.2f y=%+4.2f\n", x, y);

		if (y < 2.75f) {
			++k1;
		}
		if (y > 2.75f) {
			++k2;
		}
	}

	printf("\n  Обробка результатів табулювання функції:\n");

	if (k1 > 0) {
		printf("\n  Кількість значень функції y < 2.75: k1=%3d", k1);
	} else {
		printf("\n  Значень функції y < 2.75 немає\n");
	}

	if (k2 > 0) {
		printf("\n  Кількість значень функції y > 2.75: k2=%3d", k2);
	} else {
		printf("\n  Значень функції y > 2.75 немає\n");
	}

	return 0;
}
