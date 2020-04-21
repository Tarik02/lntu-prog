/**********************************************************/
/*                                                        */
/*  cr_7                                                  */
/*  Мова: C++                                             */
/*                                                        */
/*  Створити масив структур, що містить задані у варіанті */
/* поля. Протестувати програму за трьома різними наборами */
/* даних.                                                 */
/* 1. № п/п.                                              */
/* 2. Назва санаторію (Нива, Черемош, Лаванда).           */
/* 3. Номер (одномісний, двомісний, тримісний).           */
/* 4. Місто (Моршин, Трускавець).                         */
/* 5. Корпус (1-5).                                       */
/* 6. Прізвище пацієнта.                                  */
/*  Визначити наявність одномісних номерів в Черемоші.    */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct patient_t {
	string sanatory; // назва санаторію
	int section;     // корпус
	int number;      // № кімнати
	int places;      // кількість місць в кімнаті

	string name;     // прізвище та ім'я пацієнта
	string city;     // місто
};

struct patient_t_comp {
	bool operator()(const patient_t *a, const patient_t *b) const {
		return make_tuple(a->sanatory, a->section, a->number, a->name, a->city) < make_tuple(b->sanatory, b->section, b->number, b->name, b->city);
	}
};

map<string, function<void()>> commands;         // доступні команди
set<string> sanatory_names;                     // унікальні назви санаторіїв
set<string> city_names;                         // унікальні назви міст
set<patient_t *, patient_t_comp> patients;      // список пацієнтів

patient_t input_patient(); // функція для зчитування пацієнта
void cmd_help();           // функція для виводу списку команд
void cmd_add();            // функція для додавання нового пацієнта
void cmd_summary();        // функція для виводу висновку
void init_commands();      // функція для ініціалізації команд
void read_commands();      // функція для послідовного зчитування команд
void cleanup();            // функція для очищення пам'яті

int main() {
	init_commands();

	cmd_help();

	read_commands();

	cleanup();

	return 0;
}

// функція для зчитування пацієнта
patient_t input_patient() {
	patient_t result;

	do {
		cout << "  Введіть назву санаторію: ";
		cin >> result.sanatory;

		cout << "  Введіть номер корпусу: ";
		cin >> result.section;

		cout << "  Введіть номер кімнати: ";
		cin >> result.number;

		result.places = 0;
		int used = 0;
		for (const patient_t *other : patients) {
			if (
				result.sanatory == other->sanatory &&
				result.section == other->section &&
				result.number == other->number
			) {
				result.places = other->places;
				++used;
			}
		}

		if (result.places != 0) {
			cout << "  Кількість місць в кімнаті: всього - " << result.places << "; вільно - " << (result.places - used) << endl;
			if (result.places - used >= 0) {
				break;
			} else {
				cout << "  В цій кімнаті немає доступних місць." << endl;
				continue;
			}
		}

		do {
			cout << "  Введіть кількість місць в кімнаті: ";
			cin >> result.places;
		} while (!(result.places > 0));
		break;
	} while (true);

	cin.ignore();

	cout << "  Введіть ім'я пацієнта: ";
	getline(cin, result.name);

	cout << "  Введіть місто: ";
	getline(cin, result.city);

	sanatory_names.insert(result.sanatory);
	city_names.insert(result.city);

	return result;
}

// функція для виводу списку команд
void cmd_help() {
	cout << R"(Доступні команди:
h, help     список команд
a, add      додати пацієнта
s, summary  зробити запит на отримання даних
   exit     завершити роботу програми
)";
}

// функція для додавання нового пацієнта
void cmd_add() {
	patient_t *patient = new patient_t(input_patient());
	patients.insert(patient);
}

// функція для виводу висновку
void cmd_summary() {
	string sanatory;
	int section = -1, room = -1;

	cin.ignore();

	cout << "  Введіть назву санаторію (Enter для загального висновку): ";
	getline(cin, sanatory);

	if (!sanatory.empty()) {
		cout << "  Введіть номер корпусу (-1 для загального висновку): ";
		cin >> section;

		if (section != -1) {
			cout << "  Введіть номер кімнати (-1 для загального висновку): ";
			cin >> room;
		}
	}

	cout << "Висновок:" << endl;

	map<int, int> free;

	const patient_t *prev = nullptr;
	for (const patient_t *p : patients) {
		if (!sanatory.empty() && p->sanatory != sanatory) continue;
		if (section != -1 && p->section != section) continue;
		if (room != -1 && p->number != room) continue;

		bool ch = false;
		if (ch || (ch = prev == nullptr || prev->sanatory != p->sanatory))
			cout << "  Санаторій " << p->sanatory << ":" << endl;
		if (ch || (ch = prev == nullptr || prev->section != p->section))
			cout << "    Корпус " << p->section << ":" << endl;
		if (ch || (ch = prev == nullptr || prev->number != p->number)) {
			cout << "      Кімната " << p->number << " (" << p->places << " місць):" << endl;
			free[p->places] += p->places;
		}
		prev = p;

		--free[p->places];

		cout << "      - " << p->name << " (" << p->city << ")" << endl;
	}

	cout << "З них, вільні місця:" << endl;
	for (const pair<int, int> &it : free) {
		cout << "  у " << it.first << "-місних кімнатах: " << it.second << endl;
	}
}

// функція для ініціалізації команд
void init_commands() {
	commands["h"] = cmd_help;
	commands["help"] = cmd_help;
	commands["a"] = cmd_add;
	commands["add"] = cmd_add;
	commands["s"] = cmd_summary;
	commands["summary"] = cmd_summary;
}

// функція для послідовного зчитування команд
void read_commands() {
	while (true) {
		string cmd;
		
		cout << "> ";
		cin >> cmd;

		if (cmd == "exit") {
			break;
		}

		map<string, function<void()>>::const_iterator it = commands.find(cmd);
		if (it == commands.end()) {
			cout << "Невідома команда. Введіть help щоб отримати список доступних команд." << endl;
			continue;
		}

		it->second();
	}
}

// функція для очищення пам'яті
void cleanup() {
	for (const patient_t *it : patients) {
		delete it;
	}
	patients.clear();
}
