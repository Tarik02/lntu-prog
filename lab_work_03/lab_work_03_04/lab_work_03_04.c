/*******************************************************/
/*                                                     */
/*  lab_work_03_04                                     */
/*  ����: C                                            */
/*                                                     */
/*    ������� ������� ��� �������� �����             */
/*  �������� ���� C.                                   */
/*    ������� ������� ���������� ������ ����� �        */
/*  ��������� ���� � ����� ��������.                  */
/*                                                     */
/*******************************************************/

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {
	int i;

	clrscr();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("\n  ������ �����: ");
	scanf("%d", &i);

	printf("\n  ������ ����� � ����� ��������:");
	printf("\n  - %s : %d",  "%d ", i);
	printf("\n  - %s : %+d", "%+d", i);
	printf("\n  - %s : %d",  "%d ", i);
	printf("\n  - %s : %o",  "%o ", i);
	printf("\n  - %s : %x",  "%x ", i);
	printf("\n  - %s : %X",  "%X ", i);

	float a = 5.0f;
	printf("%4.2f", a);
	printf("%d, %d, %d, %d", -1, 2, 3, 4);

	getch();

    return 0;
}

