#include "q_win.h"

#include <conio.h>
#include <windows.h>

#undef main

int main(int argc, char **argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int result = real_main(argc, argv);

	system("pause");

	return result;
}
