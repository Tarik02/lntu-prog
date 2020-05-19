/*************************************************************/
/*                                                           */
/*  lab_work_24_01                                           */
/*  Мова: C++                                                */
/*                                                           */
/*  Робота з файлом послідовного доступу.                    */
/*  Створити файл послідовного доступу clients.dat,          */
/* передбачивши три режими роботи з ним:                     */
/* - створення i запис даних;                                */
/* - зчитування та друк даних;                               */
/* - дозапис даних у кiнець файла.                           */
/*  Файл має мiстити записи з такими полями:                 */
/* - номер рахунку;                                          */
/* - прiзвище власника;                                      */
/* - борг.                                                   */
/*                                                           */
/*************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

void io(FILE *f) {
	int number;     // номер рахунку
	char name[100]; // прізвище власника рахунку
	double balance;  // баланс (борг)

#ifdef _WIN32
	cout << "Ввід даних. Для закінчення вводу натисність Ctrl+Z." << endl;
#else
	cout << "Ввід даних. Для закінчення вводу натисність Ctrl+D." << endl;
#endif

	while (true) {
		cout << "Введіть номер рахунку:" << endl << "> ";
		cin >> number;
		if (cin.eof()) break;
		cout << "Введіть прізвище власника:" << endl << "> ";
		cin.ignore();
		cin.getline(name, sizeof(name));
		if (cin.eof()) break;
		cout << "Введіть баланс рахунку:" << endl << "> ";
		cin >> balance;
		if (cin.eof()) break;

		fprintf(f, "%d %s %.2lf\n", number, name, balance);
	}
}

int main() {
	int number;     // номер рахунку
	char name[100]; // прізвище власника рахунку
	double balance;  // баланс (борг)
	
	int mode;       // режим роботи з файлом

	FILE *f;        // вказiвник на файл clients.dat

	// Вибiр режиму роботи з файлом:
	cout << "Введіть:" << endl;
	cout << "  0, якщо хочете створити i записати данi у файл;" << endl;
	cout << "  1, якщо хочете зчитати данi з файлу;" << endl;
	cout << "  2, якщо хочете дозаписати данi у файл." << endl;

	cout << "> ";
	cin >> mode;

	switch (mode) {
	case 0: // Вiдкриття файла для створення i запису даних.
		f = fopen("clients.dat", "w");
		if (f == NULL) {
			cout << "Файл неможливо відкрити!" << endl;
			return -1;
		}

		io(f);

		fclose(f);
		break;

	case 1: // Вiдкриття файла для читання даних:
		f = fopen("clients.dat", "r");
		if (f == NULL) {
			cout << "Файл неможливо відкрити!" << endl;
			return -1;
		}

		cout
			<< setw(5) << "#"
			<< setw(20) << "Власник"
			<< setw(10) << "Баланс"
			<< endl;

		while (fscanf(f, "%d%s%lf", &number, name, &balance) == 3) {
			cout
				<< setw(5) << number
				<< setw(20) << name
				<< setw(10) << balance
				<< endl;
		}

		fclose(f);
		break;

	case 2: // Вiдкриття файла для дозапису даних:
		f = fopen("clients.dat", "a");
		if (f == NULL) {
			cout << "Файл неможливо відкрити!" << endl;
			return -1;
		}

		io(f);

		fclose(f);
		break;
	}

	return 0;
}
