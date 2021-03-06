/*******************************************************/
/*                                                     */
/*  lab_work_08_04                                     */
/*  Мова: C++                                          */
/*                                                     */
/*    Знаходження значення виразу суми з використанням */
/*  засобів мови C++. Вираз:                           */
/*  S = E[i=1,11](                                     */
/*    (pow(-1, i + 1) * (i + 1)) /                     */
/*    (pow(i, 2) + 2 * i + 7)                          */
/*  )                                                  */
/*    Циклічні процеси реалізувати командою while.     */
/*                                                     */
/*******************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	float i;
	float s;

	i = 1.0f;
	while (i <= 11.0f) {
		s += (
			(pow(-1, i + 1) * (i + 1)) /
			(pow(i, 2) + 2 * i + 7)
		);

		i += 1.0f;
	}

	cout.precision(4);
	cout << "Результат: " << s << endl;

	return 0;
}
