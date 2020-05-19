/**********************************************************/
/*                                                        */
/*  m3_1                                                  */
/*  Мова: C++                                             */
/*                                                        */
/*  Дано: одномірний масив a, що містить n елементів.     */
/*  Знайти: номер максимального за модулем елемента       */
/* масиву.                                                */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

void read_data(double *arr, int &n); // Функція для зчитування вхідних даних

int find_max_by_modulo(double *arr, int n); // Функція для пошуку максимального елемента за модулем

void write_results(double *arr, int index); // Функція для виводу результатів

int main() {
	int n; // Кількість елементів масиву
	double a[MAX_SIZE]; // Вхідний масив

	read_data(a, n);

	int index = find_max_by_modulo(a, n);

	write_results(a, index);

	return 0;
}

// Функція для зчитування вхідних даних
void read_data(double *arr, int &n) {
	cout << "Введіть кількість елементів масиву a (n <= " << MAX_SIZE << "): ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << "  Введіть a[" << i << "]: ";
		cin >> *(arr + i);
	}
}

// Функція для пошуку максимального елемента за модулем
int find_max_by_modulo(double *arr, int n) {
	int res = 0;

	for (int i = 1; i < n; ++i) {
		if (abs(*(arr + res)) < abs(*(arr + i))) {
			res = i;
		}
	}

	return res;
}

// Функція для виводу результатів
void write_results(double *arr, int index) {
	cout
		<< "Максимальний елемент масиву за модулем: "
		<< *(arr + index)
		<< " (індекс - "
		<< index
		<< ")" << endl;
}
