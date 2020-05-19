/**********************************************************/
/*                                                        */
/*  lab_work_17_02                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Дано масив a[m][n], всi eлементи якого є цiлого типу  */
/* і рiзнi за величиною, та масив b[p][q], всi елементи   */
/* якого є дiйсного типу i рiзнi за величиною.            */
/*  Необхiдно ввести та надрукувати значення всiх         */
/* елементiв масиву а[m][n], виконуючи доступ через       */
/* вказівники. Ввести та надрукувати значення всіх        */
/* елементів масиву b[p][q], виконуючи доступ через       */
/* індекси.                                               */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

int m, n, p, q;
int a[MAX_SIZE][MAX_SIZE];
double b[MAX_SIZE][MAX_SIZE];

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

	cout << "Введіть рядків масиву b (p <= " << MAX_SIZE << "): ";
	cin >> p;

	cout << "Введіть стовбців масиву b (q <= " << MAX_SIZE << "): ";
	cin >> q;

	cout << "Введіть елементи масиву b:" << endl;

	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < q; ++j) {
			cout << "  b[" << i << "][" << j << "] = ";
			cin >> b[i][j];
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

	for (int i = 0; i < p; ++i) {
		cout << endl << "  ";
		for (int j = 0; j < q; ++j) {
			cout << " " << left << setw(4) << b[i][j];
		}
	}

	cout << endl;
}

int main() {
	read_data();

	print_data();

	return 0;
}
