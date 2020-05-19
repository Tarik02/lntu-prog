/*******************************************************/
/*                                                     */
/*  lab_work_10_03                                     */
/*  Мова: C                                            */
/*                                                     */
/*  Знайти приблизне значення кореня рівняння методом  */
/*    дотичних:                                        */
/*    pow(x, 2)=sin(x)                                 */
/*                                                     */
/*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
	return pow(x, 2) - sin(x);
}

float fs(float x) {
	return 2 * x - cos(x);
}

float fss(float x) {
	return 2 + sin(x);
}

int main() {
	float a, b, c, d, e, x, xt, xp;
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

			if (f(a) * fss(a) > 0) {
				xt = a;
			} else {
				xt = b;
			}

			do {
				xp = xt;
				xt = xp - f(xp) / fs(xp);
			} while ((xt - xp) > e);

			printf("      x  = %.3f\n", xt);
			printf("    f(x) = %.3f\n", f(xt));
			printf("\n");
		}
	}

	if (has_root == 0) {
		printf("Рівняння не має коренів на проміжку [-10; 10]\n");
		return 0;
	}

	return 0;
}
