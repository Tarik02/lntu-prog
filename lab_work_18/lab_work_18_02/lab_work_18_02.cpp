/**********************************************************/
/*                                                        */
/*  lab_work_18_02                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Дано:                                                 */
/* - натуральнi числа n, m = n * (n + 1) / 2              */
/* - дано одновимiрний масив a[m], елементи якого         */
/*   дiйсного типу                                        */
/*  Необхiдно сформувати i надрукувати двовимiрний масив  */
/* b[n][n], розташовуючи у ньому елементи одномiрного     */
/* масиву за наведеною на малюнку схемою.                 */
/*  Результат вивести у вигляді таблиці.                  */
/*  Доступ до елементiв масивiв здiйснити за допомогою    */
/* вказiвникiв.                                           */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

int n, m;
double a[MAX_SIZE * MAX_SIZE];
double b[MAX_SIZE][MAX_SIZE];

void read_data() {
	cout << "Введiть натуральне число n (n <= " << MAX_SIZE << "): ";
	cin >> n;

	m = n * (n + 1) / 2;

	cout << "Введіть елементи масиву a:" << endl;

	for (int i = 0; i < m; ++i) {
		cout << "  a[" << i << "] = ";
		cin >> *(a + i);
	}
}

void compute_data() {
	int k = 0;

	for (int j = 0; j < n; ++j) {
		if (j % 2 == 1) {
			// Формування непарного стовпчика:
			for (int i = n - 1; i > -1; --i) {
				if (i < j) {
					b[i][j] = 0;
				} else {
					b[i][j] = a[k];
					++k;
				}
			}
		} else {
			// Формування парного стовпчика:
			for (int i = 0; i < n; ++i) {
				if (i < j) {
					b[i][j] = 0;
				} else {
					b[i][j] = a[k];
					++k;
				}
			}
		}
	}
}

void print_data() {
	cout << "Масив a:" << endl << " ";

	for (int i = 0; i < m; ++i) {
		cout << " " << *(a + i);
	}

	cout << endl;


	cout << "Масив b:";

	for (int i = 0; i < n; ++i) {
		cout << endl << "  ";
		for (int j = 0; j < n; ++j) {
			cout << " " << left << setw(4) << *(*(b + i) + j);
		}
	}

	cout << endl;
}

int main() {
	read_data();

	compute_data();

	print_data();

	return 0;
}
