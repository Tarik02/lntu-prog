/*******************************************************/
/*                                                     */
/*  lab_work_10_02                                     */
/*  Мова: C                                            */
/*                                                     */
/*  Знайти приблизне значення кореня рівняння методом  */
/*    хорд:                                            */
/*    (x-1)*(log(x-2)/log(2))=1                        */
/*                                                     */
/*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
	return (x - 1) * (log(x - 2) / log(2)) - 1;
}

int main() {
	float a, b, c, e, x;
	int has_root = 0;

	for (x = -10.0f; x <= 10.0f; x += 1.0f) {
		printf("f(%.1f) = %.3f\n", x, f(x));
		if (f(x) * f(x + 1.0f) < 0) {
			a = x;
			b = x + 1.0f;
			printf("Знак змінюється між x=%.1f і x=%.1f\n", a, b);
			has_root = 1;
		}
	}

	if (has_root == 0) {
		printf("Рівняння не має коренів на проміжку [-10; 10]\n");
		return 0;
	}

	printf("Знаходження розвязку на проміжку [%.1f, %.1f]\n", a, b);
	printf("Введіть точність: e=");
	scanf("%f", &e);

	do {
		c = a - (f(a) * (b - a)) / (f(b) - f(a));
		if (fabsf(f(c)) <= e) {
			break;
		}
		if (f(a) * f(c) < 0) {
			b = c;
		} else {
			a = c;
		}
	} while (1);

	printf("  x  = %.3f\n", c);
	printf("f(x) = %.3f\n", f(c));

	return 0;
}
