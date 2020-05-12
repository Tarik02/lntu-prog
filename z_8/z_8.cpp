/**************************************************************/
/*                                                            */
/*  z_8                                                       */
/*  Мова: C++                                                 */
/*                                                            */
/*  Скласти програму, яка вводить масив структур з            */
/* інформацією про поїзди:                                    */
/*  1. Номер поїзда.                                          */
/*  2. Пункт відправлення.                                    */
/*  3. Пункт прибуття.                                        */
/*  4. Час відправлення.                                      */
/*  5. Час прибуття.                                          */
/*  Визначити який поїзд у дорозі буде найдовший час.          */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

struct Train {
	int number;
	char source[128];
	char dest[128];
	int departure;
	int arrival;
};

Train input_train() {
	Train train;
	cout << "  Введіть номер поїзда:" << endl << "  > ";
	cin >> train.number;
	cout << "  Введіть пункт відправення:" << endl << "  > ";
	cin.ignore();
	cin.getline(train.source, sizeof(train.source));
	cout << "  Введіть пункт прибуття:" << endl << "  > ";
	cin.getline(train.dest, sizeof(train.dest));
	cout << "  Введіть час відправлення:" << endl << "  > ";
	cin >> train.departure;
	cout << "  Введіть час прибуття:" << endl << "  > ";
	cin >> train.arrival;
	return train;
}

void output_traint(const Train &train) {
	cout << "Поїзд №" << train.number << ":" << endl;
	cout << "  пункт відправлення: " << train.source << endl;
	cout << "  пункт прибуття: " << train.dest << endl;
	cout << "  час відправлення: " << train.departure << endl;
	cout << "  час прибуття: " << train.arrival << endl;
	cout << "  час у дорозі: " << train.arrival - train.departure << endl;
}

int main() {
	int n;
	
	cout << "Введіть кількість поїздів:" << endl << "> ";
	cin >> n;

	Train *trains = new Train[n];

	for (int i = 0; i < n; ++i) {
		cout << "Введіть поїзд " << i << ":" << endl;
		trains[i] = input_train();
	}

	Train *best = &trains[0];
	for (int i = 1; i < n; ++i) {
		Train *cur = &trains[i];
		if (best->arrival - best->departure < cur->arrival - cur->departure) {
			best = cur;
		}
	}

	cout << "Поїзд, який проведе найдовше часу у дорозі:" << endl;
	output_traint(*best);

	delete[] trains;

	return 0;
}
