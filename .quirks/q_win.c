#include "q_win.h"

#include <conio.h>

#undef main

int main(int argc, char **argv) {
	int result = real_main(argc, argv);

	getch();

	return result;
}
