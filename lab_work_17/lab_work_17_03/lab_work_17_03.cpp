/**********************************************************/
/*                                                        */
/*  lab_work_17_03                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Дано двовимірний масив a[m][n], eлементи якого є      */
/* дійсьного типу (m стрічок, n стовбців).                */
/*  Необхідно обчислити суми елементів по стрічках у      */
/* вигляді масиву g[m] та суми елементів по стовбцях у    */
/* вигляді масиву v[n]. Результат вивести у вигляді.      */
/* матриці.                                               */
/*  Доступ до елементів масивів здійсьнити за допомогою   */
/* індексів.                                              */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

int m, n, p, q;
double a[MAX_SIZE][MAX_SIZE];
double g[MAX_SIZE], v[MAX_SIZE];

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
	for (int i = 0; i < m; ++i) {
		g[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		v[i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			g[i] += a[i][j];
			v[j] += a[i][j];
		}
	}
}

void print_data() {
	cout << "Результат:";

	for (int i = 0; i < m; ++i) {
		cout << endl << "  ";
		for (int j = 0; j < n; ++j) {
			cout << " " << left << setw(4) << a[i][j];
		}
		cout << " " << left << setw(4) << g[i];
	}

	cout << endl << "  ";
	for (int j = 0; j < n; ++j) {
		cout << " " << left << setw(4) << v[j];
	}

	cout << endl;
}

int main() {
	read_data();

	compute_data();

	print_data();

	return 0;
}
