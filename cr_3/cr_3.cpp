/**********************************************************/
/*                                                        */
/*  cr_3                                                  */
/*  Мова: C++                                             */
/*                                                        */
/*  Зчитати 2 масиви a (n елементів), b (m елементів).    */
/*  Впорядкувати a методом вибору.                        */
/*  Впорядкувати b методом вставок.                       */
/*  Об'єднати масиви у масив c.                           */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

int n;               // Кількість елементів масиву a
int a[MAX_SIZE];     // Перший масив
int m;               // Кількість елементів масиву b
int b[MAX_SIZE];     // Другий масив
int c[MAX_SIZE * 2]; // Злитий масив з першого і другого

void read_data(); // Функція для зчитування вхідних даних

void sort_selects(int len, int *arr); // Функція для впорядкування масиву методом вибору
void sort_inserts(int len, int *arr); // Функція для впорядкування масиву методом вставок
void merge_arrays(); // Функція для об'єднання масивів a та b в c

void write_results(); // Функція для виводу результатів

int main() {
	read_data();

	sort_selects(n, a);

	sort_inserts(m, b);

	merge_arrays();

	write_results();

	return 0;
}

// Функція для зчитування вхідних даних
void read_data() {
	cout << "Введіть кількість елементів масиву a (n <= " << MAX_SIZE << "): ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << "  Введіть a[" << i << "] = ";
		cin >> *(a + i);
	}

	cout << "Введіть кількість елементів масиву b (m <= " << MAX_SIZE << "): ";
	cin >> m;

	for (int i = 0; i < m; ++i) {
		cout << "  Введіть b[" << i << "] = ";
		cin >> *(b + i);
	}
}

// Функція для впорядкування масиву методом вибору
void sort_selects(int len, int *arr) {
	for (int i = 0; i < len - 1; ++i) {
		int index = i;

		for (int j = i + 1; j < len; ++j) {
			if (*(arr + j) < *(arr + index)) {
				index = j;
			}
		}
		
		swap(*(arr + i), *(arr + index));
	}
}

// Функція для впорядкування масиву методом вставок
void sort_inserts(int len, int *arr) {
	for (int i = 1; i < len; ++i) {
		int j = 0;

		while (*(arr + i) > *(arr + j) && j < i) {
			++j;
		}

		if (j < i) {
			int u = *(arr + i);

			for (int k = i; k >= j + 1; --k) {
				*(arr + k) = *(arr + k - 1);
			}

			*(arr + j) = u;
		}
	}
}

// Функція для об'єднання масивів a та b в c
void merge_arrays() {
	for (int i = 0; i < n; ++i) {
		*(c + i) = *(a + i);
	}
	for (int i = 0; i < m; ++i) {
		*(c + n + i) = *(b + i);
	}
}

// Функція для виводу результатів
void write_results() {
	cout << "Вихідний масив:" << endl << " ";

	for (int i = 0; i < n + m; ++i) {
		cout << " " << *(c + i);
	}

	cout << endl;
}
