/*******************************************************/
/*                                                     */
/*  lab_work_10_01                                     */
/*  Мова: C                                            */
/*                                                     */
/*  Знайти приблизне значення кореня рівняння методом  */
/*    половинного ділення:                             */
/*    x^3-8x+5=0                                       */
/*                                                     */
/*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
	return pow(x, 3.0f) - 8*x + 5;
}

int main() {
	float a, b, c, d, e, x;
	int has_root = 0;

	printf("Введіть інтервал табуляції: d=");
	scanf("%f", &d);
	printf("Введіть точність: e=");
	scanf("%f", &e);

	for (x = -10.0f; x <= 10.0f; x += d) {
		printf("f(%.1f) = %.3f\n", x, f(x));
		if (f(x) * f(x + d) < 0) {
			a = x;
			b = x + d;
			printf("\n");
			printf("    Знак змінюється між x=%.1f і x=%.1f\n", a, b);
			has_root = 1;

			printf("    Знаходження розвязку на проміжку [%.1f, %.1f]\n", a, b);

			c = (a + b) / 2;

			do {
				if (f(c) * f(a) > 0) {
					a = c;
				} else {
					b = c;
				}

				c = (a + b) / 2;
			} while (fabsf(f(c)) > e);

			printf("      x  = %.3f\n", c);
			printf("    f(x) = %.3f\n", f(c));
			printf("\n");
		}
	}

	if (has_root == 0) {
		printf("Рівняння не має коренів на проміжку [-10; 10]\n");
		return 0;
	}

	return 0;
}
