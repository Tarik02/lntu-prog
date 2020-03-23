/**********************************************************/
/*                                                        */
/*  cr_1                                                  */
/*  Мова: C++                                             */
/*                                                        */
/*  Табулювання ф-ції, аргументи якої пробігають через    */
/* задані масивом a значення.                             */
/*  Функція: y=cos^2(x)+arctg^2(x+5)/(S+x)                */
/* де S - добуток елементів масиву a.                     */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

int n;              // Кількість елементів масиву
double a[MAX_SIZE]; // Вхідний масив
double b[MAX_SIZE]; // Вихідний масив

void read_data(); // Функція для зчитування вхідних даних

void compute(); // Функція для табулювання

void write_results(); // Функція для виводу результатів

int main() {
	read_data();

	compute();

	write_results();

	return 0;
}

// Функція для зчитування вхідних даних
void read_data() {
	cout << "Введіть кількість елементів масиву a (n <= " << MAX_SIZE << "): ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << "  Введіть a[" << i << "]: ";
		cin >> *(a + i);
	}
}

// Функція для табулювання
void compute() {
	double s = 1.0;

	for (int i = 0; i < n; ++i) {
		s *= *(a + i);
	}

	for (int i = 0; i < n; ++i) {
		double x = *(a + i);

		double y = pow(cos(x), 2) + pow(atan(x + 5), 2) / (s + x);

		*(b + i) = y;
	}
}

// Функція для виводу результатів
void write_results() {
	cout << "Результат табулювання:" << endl;

	for (int i = 0; i < n; ++i) {
		cout << "  a[" << i << "] = " << setw(10) << left << *(a + i);
		cout << "y = " << *(b + i) << endl;
	}
}
