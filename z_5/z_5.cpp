#include <iostream>
#include <iomanip>

using namespace std;

char a;
int b;
float c;
double d;

void print_bin(void *ptr, int size) {
	for (int i = size - 1; i >= 0; --i) {
		int byte = *(((char *) ptr) + i);

		for (int j = 7; j >= 0; --j) {
			cout << ((byte >> j) & 0x1);
		}
		
		cout << " ";
	}

	cout << endl;
}

void read_input() {
	cout << "Введіть a (char): ";
	cin >> a;

	cout << "Введіть b (int): ";
	cin >> b;

	cout << "Введіть c (float): ";
	cin >> c;

	cout << "Введіть d (double): ";
	cin >> d;
}

void write_output() {
	cout << "Адреса a: " << ((void *) &a) << endl;
	cout << "  Двійковий вигляд a: ";
	print_bin(&a, sizeof(a));

	cout << "Адреса b: " << ((void *) &b) << endl;
	cout << "  Двійковий вигляд b: ";
	print_bin(&b, sizeof(b));

	cout << "Адреса c: " << ((void *) &c) << endl;
	cout << "  Двійковий вигляд c: ";
	print_bin(&c, sizeof(c));

	cout << "Адреса d: " << ((void *) &d) << endl;
	cout << "  Двійковий вигляд d: ";
	print_bin(&d, sizeof(d));
}

int main() {
	read_input();

	cout << endl;

	write_output();

	return 0;
}
