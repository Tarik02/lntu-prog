/************************************************************/
/* lab_work_01_06                                           */
/* Given: the length of side of the triangle;               */
/* It is necessary to calculate:                            */
/* S = a * a * SQRT3 / 4                                    */
/* r = a * SQRT3 / 6                                        */
/* R = a * SQRT3 / 3                                        */
/*         Use the C-language                               */
/************************************************************/

#include <stdio.h>

#define SQRT3 1.73205f

int main() {
	float a, S, r, R;

	// Entering input data:
	printf("Enter the length of side of the triangle: ");
	scanf("%f", &a);

	// Calculating the results:
	S = a * a * SQRT3 / 4;
	r = a * SQRT3 / 6;
	R = a * SQRT3 / 3;

	// Printing the results:
	printf("S = %f\n", S);
	printf("r = %f\n", r);
	printf("R = %f\n", R);

	return 0;
}
