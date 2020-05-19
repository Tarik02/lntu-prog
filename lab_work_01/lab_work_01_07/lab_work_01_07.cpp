/************************************************************/
/* lab_work_01_07                                           */
/* Given: the length of side of the triangle;               */
/* It is necessary to calculate:                            */
/* S = a * a * SQRT3 / 4                                    */
/* r = a * SQRT3 / 6                                        */
/* R = a * SQRT3 / 3                                        */
/*         Use the C++-language                             */
/************************************************************/

#include <iostream>

using namespace std;

#define SQRT3 1.73205f

int main() {
	float a, S, r, R;

	// Entering input data:
	cout << "Enter the length of side of the triangle: ";
	cin >> a;

	// Calculating the results:
	S = a * a * SQRT3 / 4;
	r = a * SQRT3 / 6;
	R = a * SQRT3 / 3;

	// Printing the results:
	cout << "S = " << S << endl;
	cout << "r = " << r << endl;
	cout << "R = " << R << endl;

	return 0;
}
