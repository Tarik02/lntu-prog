/**********************************************************/
/*                                                        */
/*  lab_work_17_04                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Дано двовимірний масив a[m][n], eлементи якого є      */
/* дійсьного типу (m стрічок, n стовбців).                */
/*  Необхідно знайти мінімальний та максимальний елементи */
/* масиву та значення їх індексів.                        */
/*  Доступ до елементів масивів здійсьнити за допомогою   */
/* індексів.                                              */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

struct el_t { double val; int i, j; };

int m, n;
double a[MAX_SIZE][MAX_SIZE];
el_t el_min, el_max;

void read_data() {
	cout << "Введіть рядків масиву a (m <= " << MAX_SIZE << "): ";
	cin >> m;

	cout << "Введіть стовбців масиву a (n <= " << MAX_SIZE << "): ";
	cin >> n;

	cout << "Введіть елементи масиву a:" << endl;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << "  a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void compute_data() {
	el_min.i = el_min.j = 0;
	el_min.val = a[0][0];
	el_max.i = el_max.j = 0;
	el_max.val = a[0][0];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			double v = a[i][j];
			if (v < el_min.val) {
				el_min.val = v;
				el_min.i = i;
				el_min.j = j;
			}
			if (v > el_max.val) {
				el_max.val = v;
				el_max.i = i;
				el_max.j = j;
			}
		}
	}
}

void print_data() {
	cout << "Заданий масив:";

	for (int i = 0; i < m; ++i) {
		cout << endl << "  ";
		for (int j = 0; j < n; ++j) {
			cout << " " << left << setw(4) << a[i][j];
		}
	}

	cout << endl;

	cout << "Мiнiмальний елемент масиву: " << el_min.val << endl;
	cout << "  Номер стрiчки: " << el_min.i << endl;
	cout << "  Номер стовбця: " << el_min.j << endl;
	cout << "Максимальний елемент масиву: " << el_max.val << endl;
	cout << "  Номер стрiчки: " << el_max.i << endl;
	cout << "  Номер стовбця: " << el_max.j << endl;
}

int main() {
	read_data();

	compute_data();

	print_data();

	return 0;
}
