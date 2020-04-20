/*************************************************************/
/*                                                           */
/*  lab_work_23_03                                           */
/*  Мова: C                                                  */
/*                                                           */
/*  Завдання. Створити об'єднання number_parts з такими      */
/* полями:                                                   */
/*  - int64_t - довге цiле число;                            */
/*  - lip - структура типу LIP;                              */
/*  - unsigned char bytes[4] - масив з 4-х елементiв.        */
/*                                                           */
/*  Структура LIP має такi поля:                             */
/*  - int32_t low - молодша частина довгого числа;           */
/*  - int32_t high - старша частина довгого числа;           */
/*                                                           */
/*  Використовуючи об'єднання, видiлити обидвi частини і     */
/* довгого числа i розкласти його на байти.                  */
/*                                                           */
/*************************************************************/

#include <stdio.h>
#include <stdint.h>

// Оголошення нового типу даних - структури longint_parts
typedef struct longint_parts {
	int16_t low, high;
} longint_parts_t; // longint_parts_t (LIP) - структура типу longint_parts

// Оголошення об'єднання number_parts
typedef union number_parts {
	int32_t number;
	longint_parts_t lip;
	unsigned char bytes[4];
} number_parts_t;

int main() {
	number_parts_t un = { 0x1a2b3c4dl }; // un - об'єкт-об'єднання типу number_parts

	printf(
		"Кількість пам'яті пiд структуру longint_parts: %d байтiв.\n",
		sizeof(longint_parts_t)
	);

	printf(
		"Кількість пам'яті пiд об'єднання number_parts: %d байтiв.\n",
		sizeof(number_parts_t)
	);

	printf("\n");

	printf("Довге цiле - %#0.10lx\n", un.number);
	printf("Молодше слово - %#0.6x\n", un.lip.low);
	printf("Старше слово - %#0.6x\n", un.lip.high);

	printf("\n");

	printf("Байти:\n");

	for (int i = 0; i < sizeof(un); ++i) {
		printf("  %#2x\n", (unsigned) un.bytes[i]);
	}

	return 0;
}
