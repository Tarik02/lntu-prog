/*******************************************************/
/*                                                     */
/*  lab_work_12_01                                     */
/*  Мова: C++                                          */
/*                                                     */
/*  Знайти значення знакозмінного ряду.                */
/*                                                     */
/*******************************************************/

#include <iostream>
using namespace std;

int main() {
	float e = 0.001f;
	float x = 0.2f;

	float a;
	float s = 0;
	float u = 1;
	float z = 1;

	cout << "Проміжні значення:\n";
	do {
		cout << s << endl;
		a = z * u;
		s += a;
		u = u * (x * x);
		z *= -1;
	} while (abs(a) > e);

	cout << "Фінальний результат: " << s << endl;
	cout << "Точний результат: " << (1 / (1 + x*x)) << endl;

	return 0;
}

