/*******************************************************/
/*                                                     */
/*  lab_work_12_02                                     */
/*  Мова: C++                                          */
/*                                                     */
/*  Знайти значення знакопостійного ряду.              */
/*                                                     */
/*******************************************************/

#include <iostream>
#include <cmath>
using namespace std;

float e = 0.001f;

void calc(float x) {
	float u1 = x, u2 = 1;
	float s = 0;
	float a, b;
	int i = 1;

	cout << "  Проміжні значення:\n";
	do {
		a = u1 / u2;
		b = u1 / (u2 * i);
		cout << "  " << s << " " << b << endl;
		s += a;
		u1 *= x;
		u2 *= i;
		++i;
	} while (abs(b) > e);

	cout << "Фінальний результат: " << s << endl;
	cout << "Точний результат: " << (x * exp(x)) << endl;
}

int main() {
	float x = 0.2f;

	float a;
	float s = 0;
	float u = 1;

	for (float x = 0.1f; x <= 0.9f; x += 0.1f) {
		cout << "x = " << x << ":\n";
		calc(x);
		cout << endl;
	}

	return 0;
}

