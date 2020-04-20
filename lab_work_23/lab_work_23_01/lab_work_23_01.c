/**********************************************************/
/*                                                        */
/*  lab_work_23_01                                        */
/*  Мова: C                                               */
/*                                                        */
/*  Формування i сортування масиву структур.              */
/*  Завдання. Сформувати масив з kst структур з такими    */
/* полями: прiзвище; iм'я; група; номер студентського     */
/* квитка; середнiй бал. Впорядкувати цей масив за        */
/* спаданням значень середнього балу. Вивести на друк     */
/* впорядкований масив.                                   */
/*                                                        */
/**********************************************************/

#include <stdio.h>

#define MAX_COUNT 25

typedef struct student {
	char name[200];
	char group[100];
	long number;
	double rating;
} student_t;

int main() {
	student_t students[MAX_COUNT];
	int n;

	printf("Введіть кількість студентів: ");
	scanf("%d", &n);

	printf("\n");

	for (int i = 0; i < n; ++i) {
		printf("%d. ", 1 + i);

		getchar();

		printf("Прізвище, ім'я: ");
		gets(students[i].name);

		printf("   ");

		printf("Група: ");
		gets(students[i].group);

		printf("   ");

		printf("Номер студентського квитка: ");
		scanf("%ld", &students[i].number);

		printf("   ");

		printf("Середній бал: ");
		scanf("%lf", &students[i].rating);

		printf("\n");
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (students[i].rating < students[j].rating) {
				student_t tmp = students[i];
				students[i] = students[j];
				students[j] = tmp;
			}
		}
	}

	printf("Список студентів:\n");

	for (int i = 0; i < n; ++i) {
		student_t *student = &students[i];

		printf(
			"%2d. %-30.27s %-8s %8ld %8.lf\n",
			i + 1,
			student->name,
			student->group,
			student->number,
			student->rating
		);
	}

	return 0;
}
