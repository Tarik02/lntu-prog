/**********************************************************/
/*                                                        */
/*  lab_work_16_02                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Впорядкування елементiв масиву методом мiнiмального   */
/* елемента.                                              */
/*  Дано одномiрний масив а, що мiстить n елементiв.      */
/*  Переставити елементи масиву у порядку зростання       */
/* значень. Доступ до елементiв масиву здiйснити за       */
/* допомогою iндексiв.                                    */
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
		cin >> a[i];
	}
}

// Функція для впорядкування масиву
void sort_array() {
	for (int i = 0; i < n - 1; ++i) {
		int index = i;

		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[index]) {
				index = j;
			}
		}
		
		swap(a[i], a[index]);
	}
}

// Функція для виводу масиву
void print_array(const char *prefix) {
	cout << prefix << ":" << endl << " ";
	
	for (int i = 0; i < n; ++i) {
		cout << " " << a[i];
	}

	cout << endl;
}

int main() {
	read_array();

	print_array("Заданий масив до впорядкування");

	sort_array();

	print_array("Заданий масив після впорядкування");

	return 0;
}
