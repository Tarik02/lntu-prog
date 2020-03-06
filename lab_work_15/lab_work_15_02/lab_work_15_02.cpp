/**********************************************************/
/*                                                        */
/*  lab_work_15_02                                        */
/*  Мова: C++                                             */
/*                                                        */
/*  Дано масив a(a[1],a[2],...,a[m]), елементи якого є    */
/* цілого типу і різні за величиною, та масив             */
/* b(b[1],b[2],...b[n]), елементи якого є дійсьного типу  */
/* і різні за величиною.                                  */
/*  Необхідно: ввести значення всіх елементів масиву a[m] */
/* та надрукувати їх за допомогою доступу за індексами;   */
/* ввести значення всіх елементів масиву b[n] та          */
/* надрукувати їх за допомогою доступу за вказівниками.   */
/*                                                        */
/**********************************************************/

#include <iostream>

using namespace std;

int i, n, m;
int a[100];
float b[150];

// Ввід кількості елементів масиву
int readCount(char array, char variable) {
	cout << "Введіть кількість елеметів "  << variable << " масиву " << array << ": ";

	int c;
	cin >> c;
	return c;
}

// Ввід значень елементів масиву
template<class T>
void readElements(T *array, int count, char arrayName) {
	for (i = 0; i < count; ++i) {
		cout << "  Введіть " << arrayName << "[" << i << "]: ";
		cin >> array[i];
	}
}

template<class T>
void writeElements(const T *array, int count, char arrayName) {
	cout << "Заданий масив " << arrayName << ":" << endl;
	for (i = 0; i < count; ++i) {
		cout << array[i] << endl;
	}
}

void skipLine() {
	cout << endl;
}

int main() {
	// Ввід кількості елементів n масиву a:
	n = readCount('a', 'n');

	// Ввід значень елементів масиву a:
	readElements(a, n, 'a');

	skipLine();

	// Вивід елементів масиву a:
	writeElements(a, n, 'a');


	skipLine();


	// Ввід кількості елементів m масиву a:
	m = readCount('b', 'm');

	// Ввід значень елементів масиву b:
	readElements(b, m, 'b');

	skipLine();

	// Вивід елементів масиву b:
	writeElements(b, n, 'b');

	return 0;
}
