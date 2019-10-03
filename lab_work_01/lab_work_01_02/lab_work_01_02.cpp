/************************************************************/
/* lab_work_01_02                                           */
/* Given: the straight circular cylinder;                   */
/*        r - the radius of the cylinder;                   */
/*        h - the height of the cylinder.                   */
/* It is necessary to calculate:                            */
/* sb=2*pi*r*h - the square of cylinder lateral surface;    */
/* sp=sb+2*pi*r*r*h - the total square of cylinder surface; */
/* v=pi*r*r*h - the volume of cylinder.                     */
/*         Use the C++ language                             */
/************************************************************/

//Preprocessor directives:
#include <iostream.h>
#include <conio.h>
#define pi 3.14159

int main() {
	float r, h, sb, sp, v;
	clrscr();

	//Entering of give radius and height values
	cout << "\n Enter the value of cylinder base radius!";
	cin >> r;
	cout << "\n Enter the value of cylinder height!";
	cin >> h;

	//Calculating of cylidner three parameters:
	sb = 2*pi*r*h;       //square of cylinder lateral surface
	sp = sb+2*pi*r*r*h;  //total square of cylinder surface
	v = pi*r*r*h;        //volume of cylinder

	//Printing of cylidner three parameters
	cout << "\n  Square of cylinder lateral surface sb=" << sb << endl;
	cout << "\n  Square of cylinder total surface sp=" << sp << endl;
	cout << "\n  Volume of cylinder lateral v=" << v << endl;

	getch();
	return 0;
}


