﻿/*******************************************************/
/*                                                     */
/*  lab_work_02_04                                     */
/*  Мова: C++                                          */
/*                                                     */
/*    Дано: x, y, z - змінні дійсьного типу.           */
/*    Обчислити значення виразів a=f1(x, y, z) та      */
/*  b = f2(x, y, z). Вивести на друк вхідні велечини і */
/*  результати обчислень, у тому числі значення        */
/*  проміжних величин, у вигляді таблиці.              */
/*                                                     */
/*******************************************************/

#include <iostream>
#include <math.h>
#include <conio.h>
#include <windows.h>

#define pi 3.14159f
#define e 2.71828f

using namespace std;

int main() {
    float x, y, z;
    float a1, a2, a3, a4, a5, a6, a;
    float b1, b2, b3, b4, b5, b6, b;

    clrscr();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Ввід заданих величин:
    cout << "  Введіть значення трьох дійсьних змінних (x, y, z):" << endl << "    ";
    cin >> x >> y >> z;

    // Обчислення виразу a:
    a1 = log(1 + fabs(x * y * z));
    a2 = pow(sin(z), 2);
    a3 = pi + a2 - 4.01 * y + a1;
    a4 = pow(e, -x / 2);
    a5 = sqrt(25.05 + a4 + 0.1*y*y + z*z);
    a6 = atan(z / 4) + a5;
    a = pow(sin(a3 / a6), 2);

    // Обчислення виразу b:
    b1 = (2*x - 3.4) / (pow(y, 2) + 1);
    b2 = 1.0 / 3 + pow(cos(x + y), 2);
    b3 = 2*z - pow(x, 2);
    b4 = 1 + fabs(x - y);
    b5 = 4.9 * pow(b2 * b3 / b4, 3);
    b6 = pow(e, -x) * log(2 + fabs(x));
    b = b1 + b5 + b6;

    // Друк результатів у вигляді таблиці:
    cout.precision(5);
    cout << endl << "  Вхідні величини та результати обчислень:";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I             Вхідні  величини:             I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I         x=         I        " << fixed << x << "       I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I         y=         I        " << fixed << y << "       I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I         z=         I        " << fixed << z << "       I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I             Результати обчислень:         I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I  a1=  I   " << fixed << a1
               << "   I   b1=  I   " << fixed << b1 << "   I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I  a2=  I   " << fixed << a2
               << "   I   b2=  I   " << fixed << b2 << "   I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I  a3=  I   " << fixed << a3
               << "   I   b3=  I   " << fixed << b3 << "   I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I  a4=  I   " << fixed << a4
               << "   I   b4=  I   " << fixed << b4 << "   I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I  a5=  I   " << fixed << a5
               << "   I   b5=  I   " << fixed << b5 << "   I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I  a6=  I   " << fixed << a6
               << "   I   b6=  I   " << fixed << b6 << "   I";
    cout << endl << "  I-------------------------------------------I";
    cout << endl << "  I  a =  I   " << fixed << a
               << "   I   b =  I   " << fixed << b << "   I";
    cout << endl << "  I-------------------------------------------I";

    getch();

    return 0;
}
