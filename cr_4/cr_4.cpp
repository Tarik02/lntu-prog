/**********************************************************/
/*                                                        */
/*  cr_4                                                  */
/*  Мова: C++                                             */
/*                                                        */
/*  Заданий двовимірний масив (m стрічок, n стовбчиків).  */
/*  Знайти значення максимального елемента кожної стрічки */
/* і номер стовпчика, в якому він розміщенний.            */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

struct row_info_t { int value; int col; };

int m;                     // Кількість стрічок
int n;                     // Кількість стовбчиків
int a[MAX_SIZE][MAX_SIZE]; // Масив
row_info_t inf[MAX_SIZE];  // Інформація про кожен рядок

void read_data(); // Функція для зчитування вхідних даних

void find_maxes(); // Функція для пошуку максимального елемента кожної стрічки

void write_results(); // Функція для виводу результатів

int main() {
	read_data();

	find_maxes();

	write_results();

	return 0;
}

// Функція для зчитування вхідних даних
void read_data() {
	cout << "Введіть кількість стрічок масиву (1 <= m <= " << MAX_SIZE << "): ";
	cin >> m;

	cout << "Введіть кількість стовбчиків масиву (1 <= n <= " << MAX_SIZE << "): ";
	cin >> n;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << "  Введіть a[" << i << "][" << j << "] = ";
			cin >> *(*(a + i) + j);
		}
	}
}

// Функція для пошуку максимального елемента кожної стрічки
void find_maxes() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == 0 || inf[i].value < *(*(a + i) + j)) {
				inf[i].value = *(*(a + i) + j);
				inf[i].col = j;
			}
		}
	}
}

// Функція для виводу результатів
void write_results() {
	cout << "Результати:";

	for (int i = 0; i < m; ++i) {
		cout << endl << "  ";

		for (int j = 0; j < n; ++j) {
			cout << left << setw(4) << *(*(a + i) + j);
		}

		cout << "Максимум " << i << ": значення - " << inf[i].value << ", стовбець - " << inf[i].col;
	}

	cout << endl;
}
