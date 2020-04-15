/************************************************************/
/* lab_work_01_01                                           */
/* Given: the straight circular cylinder;                   */
/*        r - the radius of the cylinder;                   */
/*        h - the height of the cylinder.                   */
/* It is necessary to calculate:                            */
/* sb=2*pi*r*h - the square of cylinder lateral surface;    */
/* sp=sb+2*pi*r*r*h - the total square of cylinder surface; */
/* v=pi*r*r*h - the volume of cylinder.                     */
/*         Use the C-language                               */
/************************************************************/
//Preprocessor directives:

#include <stdio.h>
#define pi 3.14159

int main() {
	float r, h, sb, sp, v;

	//Entering of give radius and height values
	printf("\n Enter the value of cylinder base radius!");
	scanf("%f", &r);
	printf("\n Enter the value of cylinder height!");
	scanf("%f", &h);

	//Calculating of cylidner three parameters:
	sb = 2*pi*r*h;       //square of cylinder lateral surface
	sp = sb+2*pi*r*r*h;  //total square of cylinder surface
	v = pi*r*r*h;        //volume of cylinder

	//Printing of cylidner three parameters
	printf("\n  Square of cylinder lateral surface sb=%f", sb);
	printf("\n  Square of cylinder total surface sp=%f", sp);
	printf("\n  Volume of cylinder lateral v=%f", v);

	return 0;
}

