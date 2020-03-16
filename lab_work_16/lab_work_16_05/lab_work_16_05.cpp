/**********************************************************/
/*                                                        */
/*  lab_work_16_05                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Впорядкування елементiв масиву методом рекурсії.      */
/* Дано одномiрний масив а, що мiстить n елементiв.       */
/* Переставити елементи масиву у порядку зростання        */
/* значень. Доступ до елементiв масиву здiйснити за       */
/* допомогою вказівників.                                 */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

int n;             // Кількість елементів масиву
float a[MAX_SIZE]; // Масив

// Функція для зчитування масиву
void read_array() {
	cout << "Введіть кількість елементів (n <= " << MAX_SIZE << "): ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << "  Введіть a[" << i << "]: ";
		cin >> *(a + i);
	}
}

// Функція для впорядкування масиву
void sort_array(int l, int r) {
	int b = *(a + (l + r) / 2);
	int i = l, j = r;

	while (i <= j) {
		while (*(a + i) < b) ++i;
		while (*(a + j) > b) --j;

		if (i <= j) {
			if (i != j) {
				swap(*(a + i), *(a + j));
			}

			++i;
			--j;
		}
	}
	
	if (l < j) {
		sort_array(l, j);
	}

	if (i < r) {
		sort_array(i, r);
	}
}

// Функція для виводу масиву
void print_array(const char *prefix) {
	cout << prefix << ":" << endl << " ";
	
	for (int i = 0; i < n; ++i) {
		cout << " " << *(a + i);
	}

	cout << endl;
}

int main() {
	read_array();

	print_array("Заданий масив до впорядкування");

	sort_array(0, n - 1);

	print_array("Заданий масив після впорядкування");

	return 0;
}
