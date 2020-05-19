/**********************************************************/
/*                                                        */
/*  cr_5                                                  */
/*  Мова: C++                                             */
/*                                                        */
/*  Сформувати двовимірний масив (розміром nxn), елементи */
/* якого утворюються за правилом індивідуального          */
/* варіанту.                                              */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

int n;                      // Кількість стрічок та стовбчиків вихідного масиву
int m;                      // Кількість елементів вхідного масиву
int a[MAX_SIZE][MAX_SIZE];  // Вихідний масив
int b[MAX_SIZE * MAX_SIZE]; // Вхідний масив

void read_data(); // Функція для зчитування вхідних даних

void build_array(); // Функція побудови вихідного масиву

void write_results(); // Функція для виводу результатів

int main() {
	read_data();

	build_array();

	write_results();

	return 0;
}

// Функція для зчитування вхідних даних
void read_data() {
	cout << "Введіть кількість стрічок та стовбчиків масиву (1 <= n <= " << MAX_SIZE << "): ";
	cin >> n;

	m = (n * (n - 1)) / 2;

	for (int i = 0; i < m; ++i) {
		cout << "Введіть b[" << i << "]: ";
		cin >> *(b + i);
	}
}

// Функція побудови вихідного масиву
void build_array() {
	int i = 0, j = n - 2, k = 0;

	while (j != -1) {
		*(*(a + i) + j) = *(b + k);

		if ((n - 1 - j) % 2 == 0) {
			++i;
			if (i == (n - j - 1)) {
				--j;
			}
		} else {
			--i;
			if (i == -1) {
				i = 0;
				--j;
			}
		}

		++k;
	}
}

// Функція для виводу результатів
void write_results() {
	cout << "Вхідний масив:" << endl << " ";

	for (int i = 0; i < m; ++i) {
		cout << " " << *(b + i);
	}

	cout << endl;


	cout << "Вихідний масив:";

	for (int i = 0; i < n; ++i) {
		cout << endl << "  ";

		for (int j = 0; j < n; ++j) {
			cout << left << setw(4);

			if (n - i - 1 < j + 1) {
				cout << "-";
			} else {
				cout << *(*(a + i) + j);
			}
		}
	}

	cout << endl;
}
