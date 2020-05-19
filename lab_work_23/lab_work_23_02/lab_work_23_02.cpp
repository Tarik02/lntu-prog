/*************************************************************/
/*                                                           */
/*  lab_work_23_02                                           */
/*  Мова: C++                                                */
/*                                                           */
/*  Формування масиву структур.                              */
/*  Cтруктура мiстить такi поля: марка, рiк випуску машини,  */
/* цiна машини. Вивести не екран iнформацiю про всi машини i */
/* додатково про тi, цiна яких менша, нiж 3000$.             */
/*                                                           */
/*************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int MAX_COUNT = 100;

struct CarInfo {
	string brand;
	int year, price;
};

vector<CarInfo> cars;

void print_car(const CarInfo &car);

int main() {
	int n;

	cout << "Введіть кількість автомобілів: ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << setw(2) << i + 1 << ". ";
		cin.get();

		CarInfo info;

		cout << "Марка: ";
		getline(cin, info.brand);

		cout << setw(4) << "";

		cout << "Рік випуску: ";
		cin >> info.year;

		cout << setw(4) << "";

		cout << "Ціна в $: ";
		cin >> info.price;

		cars.push_back(info);
	}

	cout << endl;

	cout << "Фiрма пропонує такi автомобілі:" << endl;
	cout
		<< left << setw(20) << "Назва"
		<< left << setw(20) << "Рiк"
		<< left << setw(20) << "Цiна ($)"
		<< endl;

	for (const CarInfo &car : cars) {
		print_car(car);
	}

	cout << endl;


	cout << "З них, дешевші, ніж 3000$:" << endl;

	for (const CarInfo &car : cars) {
		if (car.price >= 3000) {
			continue;
		}

		print_car(car);
	}

	return 0;
}

void print_car(const CarInfo &car) {
	cout
		<< left << setw(20) << car.brand
		<< left << setw(20) << car.year
		<< left << setw(20) << car.price
		<< endl;
}
