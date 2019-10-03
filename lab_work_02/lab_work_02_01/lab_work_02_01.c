﻿/*******************************************************/
/*                                                     */
/*  lab_work_02_01                                     */
/*  Мова: C                                            */
/*                                                     */
/*    Бібліотека арифметичних функцій C/C++.           */
/*    Дано: x, y, z - змінні дійсьного типу.           */
/*    Обчислити значення виразів a=f1(x, y, z) та      */
/*  b = f2(x, y, z). Вивести на друк вхідні велечини і */
/*  результати обчислень, у тому числі значення        */
/*  проміжних величин, у вигляді таблиці.              */
/*                                                     */
/*******************************************************/

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

#define pi 3.14159f

int main() {
    float x, y, z;
    float a1, a2, a3, a4, a5, a;
    float b1, b2, b3, b4, b5, b;

	clrscr();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Ввід заданих величин:
    printf("  Введіть значення трьох дійсьних змінних:\n   ");
    scanf("%f%f%f", &x, &y, &z);

    // Обчислення виразу a:
    a1 = y / (2 + y * y + fabs(y * z));
    a2 = acos(a1);
    a3 = pi + x * x + pow(sin(y * z), 2);
    a4 = pow(a3, 1 / 2);
    a5 = log10(2 / (x * x + y * y + 1));
    a = a2 * (a4 - a5);

    // Обчислення виразу b:
    b1 = exp(-3 * x * x + y / 3 - z);
    b2 = pow(tan(x), 2);
    b3 = b2 / (1 + sin(pi * y / 2));
    b4 = pow(b3, 1 / 3);
    b5 = (x + y + z) / (x * y * z);
    b = b1 + b4 - pow(b5, 2);

    // Друк результатів у вигляді таблиці:
    printf("\n  Вхідні величини та результати обчислень:");
    printf("\n  I-------------------------------------------I");
    printf("\n  I             Вхідні  величини:             I");
    printf("\n  I-------------------------------------------I");
    printf("\n  I         x=         I        %5.2f         I", x);
    printf("\n  I-------------------------------------------I");
    printf("\n  I         y=         I        %5.2f         I", y);
    printf("\n  I-------------------------------------------I");
    printf("\n  I         z=         I        %5.2f         I", z);
    printf("\n  I-------------------------------------------I");
    printf("\n  I             Результати обчислень:         I");
    printf("\n  I-------------------------------------------I");
    printf("\n  I  a1=  I    %5.2f   I    b1=  I   %5.2f    I", a1, b1);
    printf("\n  I-------------------------------------------I");
    printf("\n  I  a2=  I    %5.2f   I    b2=  I   %5.2f    I", a2, b2);
    printf("\n  I-------------------------------------------I");
    printf("\n  I  a3=  I    %5.2f   I    b3=  I   %5.2f    I", a3, b3);
    printf("\n  I-------------------------------------------I");
    printf("\n  I  a4=  I    %5.2f   I    b4=  I   %5.2f    I", a4, b4);
    printf("\n  I-------------------------------------------I");
    printf("\n  I  a5=  I    %5.2f   I    b5=  I   %5.2f    I", a5, b5);
    printf("\n  I-------------------------------------------I");
    printf("\n  I  a =  I    %5.2f   I    b =  I   %5.2f    I", a, b);
    printf("\n  I-------------------------------------------I");

    getch();

    return 0;
}
