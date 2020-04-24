/**********************************************************/
/*                                                        */
/*  m3_2                                                  */
/*  Мова: C++                                             */
/*                                                        */
/*  Дано: двовимірний масив a, що складається з m стрічок */
/* та n стовпчиків. Елементи масиву дійсного типу.        */
/*  Знайти: середнє геометричне значення елементів        */
/* кожного стовпчика і масиву в цілому.                   */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double **read_data(int &m, int &n); // Функція для зчитування вхідних даних

double find_sqr_median(double *arr, int n); // Функція для пошуку середнього геометричного одновимірного масиву

double *find_sqr_medians(double **arr, int m, int n); // Функція для пошуку середнього геометричного для кожного стовбчика

void write_results(double **arr, int m, int n, double *medians, double median); // Функція для виводу результатів

void free_data(double **arr, int m, int n); // Функція для очищення пам'яті вхідних даних

void free_medians(double *arr, int m, int n); // Функція для очищення середніх геометричних

int main() {
	int m; // Кількість стрічок масиву
	int n; // Кількість стовбчиків масиву

	double **a = read_data(m, n);

	double *medians = find_sqr_medians(a, m, n);
	double median = find_sqr_median(medians, n);

	write_results(a, m, n, medians, median);

	free_data(a, m, n);
	free_medians(medians, m, n);

	return 0;
}

// Функція для зчитування вхідних даних
double **read_data(int &m, int &n) {
	cout << "Введіть кількість стрічок масиву a (m): ";
	cin >> m;

	cout << "Введіть кількість стовбчиків масиву a (n): ";
	cin >> n;

	double **arr = new double *[n];

	for (int j = 0; j < n; ++j) {
		*(arr + j) = new double[m];
	}

	for (int i = 0; i < m; ++i) {
		cout << "Введіть стрічку масиву під номером " << i << ":" << endl << "  ";

		for (int j = 0; j < n; ++j) {
			cin >> *(*(arr + j) + i);
		}
	}

	return arr;
}

// Функція для пошуку середнього геометричного одновимірного масиву
double find_sqr_median(double *arr, int n) {
	double res = 1.0;

	for (int i = 0; i < n; ++i) {
		res *= *(arr + i);
	}

	res = pow(res, 1.0 / n);

	return res;
}

// Функція для пошуку середнього геометричного для кожного стовбчика
double *find_sqr_medians(double **arr, int m, int n) {
	double *res = new double[n];

	for (int j = 0; j < n; ++j) {
		*(res + j) = find_sqr_median(*(arr + j), m);
	}

	return res;
}

// Функція для виводу результатів
void write_results(double **arr, int m, int n, double *medians, double median) {
	cout << "Вхідний масив:" << endl;

	cout.precision(4);

	for (int i = 0; i < m; ++i) {
		cout << "  ";
		for (int j = 0; j < n; ++j) {
			cout << setw(7) << fixed << *(*(arr + j) + i) << " ";
		}
		cout << endl;
	}

	cout << "Середнє геометричне для кожного стовбчика:" << endl;

	cout << "  ";
	for (int j = 0; j < n; ++j) {
		cout << setw(7) << fixed << *(medians + j) << " ";
	}
	cout << endl;

	cout << "Середнє геометричне всього масиву: " << fixed << median << endl;
}

// Функція для очищення пам'яті вхідних даних
void free_data(double **arr, int m, int n) {
	for (int j = 0; j < n; ++j) {
		delete[] *(arr + j);
	}
}

// Функція для очищення середніх геометричних
void free_medians(double *arr, int m, int n) {
	delete[] arr;
}
