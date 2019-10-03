/*******************************************************/
/*                                                     */
/*  lab_work_04_03                                     */
/*  Language: C++                                      */
/*                                                     */
/*    Coroutines-functions with values-arguments       */
/*  using C++-language constructions.                  */
/*    Given: a - length of side of equilateral         */
/*  triangle.                                          */
/*    Compute and print:                               */
/*  s = a * a * SQRT3 / 4 - square of the triangle;    */
/*  r = a * SQRT3 / 6 - radius of inscribed circle;    */
/*  R = a * SQRT3 / 3 - radius of escribed circle;     */
/*    In order to compute values of s, r and R create  */
/*  coroutines-functions with values-arguments.        */
/*                                                     */
/*******************************************************/

#include <iostream>
#include <math.h>
#include <conio.h>
#include <windows.h>
using namespace std;

#define sqrt3 1.73205f

// Prototypes of the functions:
float square(float a);
float incircleRadius(float a);
float excircleRadius(float a);

int main() {
	// Variables and constants definitions:
	float a;   // length of the side
	float s;   // square of the triangle
	float r;   // radius of incircle
	float R;   // radius of excircle

	clrscr();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Reading input:
	cout << "\n  Input the length of the triangle's side: ";
	cin >> a;

	// Computing the parameters of the triangle:
	s = square(a);
	r = incircleRadius(a);
	R = excircleRadius(a);

	// Writing output:
	cout << "\n";
	cout << "  Square of the triangle s = " << s << endl;
	cout << "  Radius of incircle     r = " << r << endl;
	cout << "  Radius of excircle     R = " << R << endl;

	getch();

	return 0;
}

//-------------------------------------------------------
// Function computing square of the triangle
float square(float a) {
	return a * a * sqrt3 / 4;
}

//-------------------------------------------------------
// Function computing radius of incircle of the triangle
float incircleRadius(float a) {
	return a * sqrt3 / 6;
}

//-------------------------------------------------------
// Function computing radius of excircle of the triangle
float excircleRadius(float a) {
	return a * sqrt3 / 3;
}
