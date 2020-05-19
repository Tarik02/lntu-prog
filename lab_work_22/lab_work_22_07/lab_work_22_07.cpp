/***********************************************************/
/*                                                         */
/*  lab_work_22_06                                         */
/*  Мова: C++                                              */
/*                                                         */
/*  Ввести з клавiатури прiзвище та iмя (наприклад,        */
/* Петренко Iван).                                         */
/*  Утворити i надрукувати стрiчку "Привiт, Iван           */
/* Петренко!".                                             */
/*                                                         */
/***********************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string first_name, last_name;

	cout << "Введіть ваше прізвище та ім'я: ";
	cin >> last_name >> first_name;

	string greeting = "Привіт, " + first_name + " " + last_name + "!";

	cout << greeting << endl;

	return 0;
}
