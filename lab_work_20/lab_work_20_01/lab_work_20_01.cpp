/**********************************************************/
/*                                                        */
/*  lab_work_20_01                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Дано матрицю (двовимiрний масив) a[m][n] (m стрiчок,  */
/* n стовпцiв) та матриицю (двовимiрний масив) b[p][q] (p */
/* стрiчок, q стовпцiв). Елементи обох матриць дiйсного   */
/* типу.                                                  */
/*  Необхiдно обчислити елементи матрицi c = a * b, яка є */
/* добутком двох заданих матриць. Результат вивести у     */
/* виглядi матрицi.                                       */
/*  Доступ до елементiв масивiв здiйснити за допомогою    */
/* вказiвникiв.                                           */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

int m, n;
double a[MAX_SIZE][MAX_SIZE];
double b[MAX_SIZE][MAX_SIZE];
double c[MAX_SIZE][MAX_SIZE];

void read_data() {
	cout << "Введіть рядків масиву a (m <= " << MAX_SIZE << "): ";
	cin >> m;

	cout << "Введіть стовбців масиву a (n <= " << MAX_SIZE << "): ";
	cin >> n;

	cout << "Введіть елементи масиву a:" << endl;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << "  a[" << i << "][" << j << "] = ";
			cin >> *(*(a + i) + j);
		}
	}

	cout << "Введіть елементи масиву b:" << endl;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << "  b[" << i << "][" << j << "] = ";
			cin >> *(*(b + i) + j);
		}
	}
}

void compute_data() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			*(*(c + i) + j) = *(*(a + i) + j) * *(*(b + i) + j);
		}
	}
}

void print_data() {
	cout << "Масив a:";

	for (int i = 0; i < m; ++i) {
		cout << endl << "  ";
		for (int j = 0; j < n; ++j) {
			cout << " " << left << setw(4) << *(*(a + i) + j);
		}
	}

	cout << endl;


	cout << "Масив b:";

	for (int i = 0; i < m; ++i) {
		cout << endl << "  ";
		for (int j = 0; j < n; ++j) {
			cout << " " << left << setw(4) << *(*(b + i) + j);
		}
	}

	cout << endl;


	cout << "Масив c:";

	for (int i = 0; i < m; ++i) {
		cout << endl << "  ";
		for (int j = 0; j < n; ++j) {
			cout << " " << left << setw(4) << *(*(c + i) + j);
		}
	}

	cout << endl;
}

int main() {
	read_data();

	compute_data();

	print_data();

	return 0;
}
