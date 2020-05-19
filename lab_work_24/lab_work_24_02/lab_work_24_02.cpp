/*************************************************************/
/*                                                           */
/*  lab_work_24_02                                           */
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

struct client_data_t {
	int number;     // номер рахунку
	char name[100]; // прізвище власника рахунку
	double balance;  // баланс (борг)
};

void io(FILE *f) {
	client_data_t client;

#ifdef _WIN32
	cout << "Ввід даних. Для закінчення вводу натисність Ctrl+Z." << endl;
#else
	cout << "Ввід даних. Для закінчення вводу натисність Ctrl+D." << endl;
#endif

	while (true) {
		cout << "Введіть номер рахунку:" << endl << "> ";
		cin >> client.number;
		if (cin.eof()) break;
		cout << "Введіть прізвище власника:" << endl << "> ";
		cin.ignore();
		cin.getline(client.name, sizeof(client.name));
		if (cin.eof()) break;
		cout << "Введіть баланс рахунку:" << endl << "> ";
		cin >> client.balance;
		if (cin.eof()) break;

		// Пошук позицiї поточного запису у файлi:
		fseek(f, (client.number - 1) * sizeof(client), SEEK_SET);

		// Збереження поточного запису у файлi:
		fwrite(&client, sizeof(client), 1, f);
	}
}

int main() {
	client_data_t client;
	
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

		while (fread(&client, sizeof(client), 1, f) == 1) {
			cout
				<< setw(5) << client.number
				<< setw(20) << client.name
				<< setw(10) << client.balance
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
