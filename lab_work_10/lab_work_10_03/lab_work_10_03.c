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
	float a, b, c, e, x, xt, xp;
	int has_root = 0;

	for (x = -10.0f; x <= 10.0f; x += 0.5f) {
		printf("f(%.1f) = %.3f\n", x, f(x));
		if (f(x) * f(x + 0.5f) < 0) {
			a = x;
			b = x + 0.5f;
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

	if (f(a) * fss(a) > 0) {
		xt = a;
	} else {
		xt = b;
	}

	do {
		xp = xt;
		xt = xp - f(xp) / fs(xp);
	} while ((xt - xp) > e);

	printf("  x  = %.3f\n", xt);
	printf("f(x) = %.3f\n", f(xt));

	return 0;
}
