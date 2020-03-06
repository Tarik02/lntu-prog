/*******************************************************/
/*                                                     */
/*  lab_work_15_04                                     */
/*  Мова: C                                            */
/*                                                     */
/*  Табулювання функції. Обчислити всі значення        */
/* функції y=sin(3*x)^2, аргумент якої набуває         */
/* заданих значень.                                    */
/*  Розв'язати цю задачу для випадку, коли масив       */
/* ініціалізовано n значеннями. Доступ до елементів    */
/* масивів здійсьнити за допомогою індексів.           */
/*                                                     */
/*******************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int n;
float x[100], y[100];

void readInput() {
	cout << "Введіть кількість елементів масиву: ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << "  Введіть x[i]: ";
		cin >> x[i];
	}
}

void doCalculations() {
	for (int i = 0; i < n; ++i) {
		y[i] = pow(sin(3 * x[i]), 2);
	}
}

void writeOutput() {
	cout << endl << "Результати обчислень:" << endl;

	for (int i = 0; i < n; ++i) {
		cout << setw(10) << "x[" << i << "] = " << x[i];
		cout << ": ";
		cout << setw(10) << "y[" << i << "] = " << y[i];
		cout << endl;
	}
}

int main() {
	readInput();

	doCalculations();

	writeOutput();

	return 0;
}
