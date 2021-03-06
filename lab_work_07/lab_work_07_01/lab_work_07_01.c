﻿/*******************************************************/
/*                                                     */
/*  lab_work_07_01                                     */
/*  Мова: C                                            */
/*                                                     */
/*    Табулювання функції на інтервалі засобами мови   */
/*  C. Обчислити всі значення функції                  */
/*  y = 2*sin(3*x) + 3*cos(5*x), аргумент x якої       */
/*  змінюється на інтервалі [2;4] з кроком h=0.2 .     */
/*  Обчислити також суму, кількість та середнє         */
/*  арифметичне тих значень функції, які задовільняють */
/*  нерівність 1 <= y <= 3. Якщо таких значень не      */
/*  виявиться, вивести відповідне повідомлення.        */
/*    Циклічні процеси реалізувати командою for.       */
/*                                                     */
/*******************************************************/

#include <stdio.h>
#include <math.h>

int main() {
	float x;      // Аргумент функції
	float y;      // Значення функції
	float s = 0;  // Сума значень функції з інтервалу [1;3]
	float sa;     // Середнє ариметичне значень функції з інтервалу [1;3]
	int k = 0;    // Кількість значень функції з інтервалу [1;3]

	// Табулювання функції на заданому інтервалі
	// з одночасним обчисленням кількісті k та суми s:
	printf("\n  Результати табулювання функції:\n");

	for (x = 2.0f; x < 4.1f; x += 0.2f) {
		y = 2*sin(3*x) + 3*cos(5*x);
		printf("  x=%+4.2f y=%+4.2f\n", x, y);
		if (y >= 1.0f && y <= 3.0f) {
			++k;
			s += y;
		}
	}

	printf("\n  Обробка результатів табулювання функції:\n");
	if (k > 0) {
		sa = s / k;
		printf("\n  Кількість значень функції з інтервалу [1;3] k=%3d", k);
		printf("\n  Сума значень функції з інтервалу [1;3] s=%6.2f", s);
		printf("\n  Середнє арифметичне значень функції з інтервалу [1;3] sa=%6.2f", sa);
	} else {
		printf("\n  Значень функції на інтервалі [1;3] немає\n");
	}

	return 0;
}
