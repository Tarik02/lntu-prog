/*******************************************************/
/*                                                     */
/*  lab_work_04_02                                     */
/*  Language: C                                        */
/*                                                     */
/*    Coroutines-functions with values-arguments       */
/*  using C-language constructions.                    */
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

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

#define pi 3.14159f
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
	printf("\n  Input the length of the triangle's side: ");
	scanf("%f", &a);

	// Computing the parameters of the triangle:
	s = square(a);
	r = incircleRadius(a);
	R = excircleRadius(a);

	printf("\n");
	printf("  Square of the triangle s = %f\n", s);
	printf("  Radius of incircle     r = %f\n", r);
	printf("  Radius of excircle     R = %f\n", R);

	getch();

	return 0;
}

//-------------------------------------------------------
// Function computing square of the triangle
float square(float a) {
	return a * a * sqrt3 / 4;
}

float incircleRadius(float a) {
	return a * sqrt3 / 6;
}

float excircleRadius(float a) {
	return a * sqrt3 / 3;
}
