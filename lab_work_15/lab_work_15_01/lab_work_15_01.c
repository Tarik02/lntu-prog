/*******************************************************/
/*                                                     */
/*  lab_work_15_01                                     */
/*  Мова: C                                            */
/*                                                     */
/*  Смисл імені масиву одновимірного масиву.           */
/*                                                     */
/*******************************************************/

#include <stdio.h>

int main() {
	char array[5] = {'A', 'L', 'P', 'H', 'A'};

	printf("    array    = %p\n", array);

	printf("\n");

	printf("    array[0] = %p\n", &array[0]);
	printf("    array[1] = %p\n", &array[1]);
	printf("    array[2] = %p\n", &array[2]);

	printf("\n");

	printf("    &array    = %p\n", &array);
	printf("    &array[1] = %p\n", &array[1]);
	printf("    &array[2] = %p\n", &array[2]);

	printf("\n");

	printf("    *array    = %c\n", *array);
	printf("    *(array+1)= %c\n", *(array + 1));
	printf("    *(array+2)= %c\n", *(array + 2));

	return 0;
}
