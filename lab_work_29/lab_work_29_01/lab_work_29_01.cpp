/**************************************************************/
/*                                                            */
/*  lab_work_29_01                                            */
/*  Мова: C++                                                 */
/*                                                            */
/*  Елементарні графічні побудови.                            */
/*  Завдання. Сконструювати клас Graph з такими полями:       */
/* Відкриті елементи класу:                                   */
/* - Graph() - конструктор класу;                             */
/* - ~Graph() - деструктор класу;                             */
/* - void scr(int col) - встановлення кольору фону;           */
/* - void circle(int x, int y, int r, int col, int coll)  -   */
/*   побудова кола;                                           */
/* - void rect(int x, int y, int a, int b) - побудова         */
/*   прямокутника;                                            */
/* - void square(int x, int y, int col) - побудова квадрата;  */
/* - void springArch(int x, int y, int r, int col) - побудова */
/*   спіралі Архімеда;                                        */
/* - void uPascal(int x, int y, int r, int col) - побудова    */
/*   "равлика" Паскаля;                                       */
/* - void xForm(int x, int y, int a, int col) - побудова      */
/*   хрестоподібної фігури;                                   */
/* - void figLiss(int x, int y, int j) - побудова фігур       */
/*   Ліссажу                                                  */
/*  Доступ до елементів класу Graph здійснити за допомогою    */
/* об'єкта ob.                                                */
/*                                                            */
/**************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <graphics.h>

using namespace std;

class Graph {
public:
	// Конструктор класу
	Graph() {
		int gdriver = DETECT, gmode, errorcode;
		initgraph(&gdriver, &gmode, "");
		if ((errorcode = graphresult()) != grOk) {
			cout << "Помилка: " << grapherrormsg(errorcode) << endl;
			exit(1);
		}
		cleardevice();
		sdlbgifast();
	}

	// Деструктор класу
	~Graph() {
		closegraph();
	}

	// Встановлення кольору фону
	void scr(int col);
	// Побудова кола
	void circle(int x, int y, int r, int col, int coll);
	// Побудова прямокутника
	void rect(int x, int y, int a, int b);
	// Побудова квадрата
	void square(int x, int y, int col);
	// Побудова спіралі Архімеда
	void springArch(int x, int y, int R, int col);
	// Побудова равлика Паскаля
	void uPascal(int x, int y, int R, int col);
	// Побудова хрестовидної фігури
	void xForm(int x, int y, int a, int col);
	// Побудова фігур Ліссажу
	void figLiss(int x, int y, int j);
};

void Graph::scr(int col) {
	cleardevice();
	int XMAX = getmaxx();
	int YMAX = getmaxy();

	for (int i = 1; i <= XMAX; ++i) {
		for (int j = 1; j <= YMAX; ++j) {
			putpixel(i, j, col);
		}
	}
}

void Graph::circle(int x, int y, int r, int col, int coll) {
	double al, dal, xx, yy, x1, y1, x2, y2;
	int k = 60; dal = 3.14159 / 2 / k;
	for (int l = 0; l < k; ++l) {
		al = dal * l;
		xx = r * cos(al);
		yy = r * sin(al);
		x1 = x - xx;
		y1 = y + yy;
		x2 = x + xx;
		y2 = y - yy;
		setcolor(col);
		line(x1, y1, x2, y1);
		setcolor(coll);
		line(x1, y2, x2, y2);
	}
}

void Graph::rect(int x, int y, int a, int b) {
	for (int i = 0; i < b; i += 2) {
		rectangle(x - a + i, y - b + i, x + a + i, y + b + i);
	}
}

void Graph::square(int x, int y, int col) {
	for (int m = -1; m < 2; ++m) {
		int k = x + m;
		for (int n = -1; n < 2; ++n) {
			int l = y + n;
			putpixel(k, l, col);
		}
	}
}

void Graph::springArch(int x, int y, int R, int col) {
	double al = 0., r = 0., a = ((double) R) / 40;
	int x1, y1;
	while (r < R) {
		r = a * al;
		x1 = x + r * sin(al);
		y1 = y + r * cos(al);
		putpixel(x1, y1, col);
		al += 0.02;
	}
}

void Graph::uPascal(int x, int y, int R, int col) {
	double al = 0., r, a = R * 1.8;
	int x1, y1;
	while (al < 6.2832) {
		r = R - a * cos(al);
		x1 = x + r * sin(al);
		y1 = y + r * cos(al);
		putpixel(x1, y1, col);
		al += 0.02;
	}
}

void Graph::xForm(int x, int y, int a, int col) {
	double r, al, dal, al2, xx, yy, dd, ddm, pi = 3.14159;
	int x1, y1, x2, y2, k = 90;
	dal = pi / 2 / k;
	dd = dal * 6, ddm = pi / 2 - dd;
	for (int l = 0; l < k - 1; ++l) {
		al = dal * l;
		al2 = 2 * al;
		if (al > dd && al < ddm) {
			r = a / sin(al2);
			xx = r * cos(al);
			yy = r * sin(al);
			x1 = x - xx;
			y1 = y + yy;
			x2 = x + xx;
			y2 = y - yy;
			putpixel(x2, y2, col);
			putpixel(x1, y2, col);
			putpixel(x2, y1, col);
			putpixel(x1, y1, col);
		}
	}
}

void Graph::figLiss(int x, int y, int j) {
	int fx = 50, fy = 70;
	double f = 0.3;
	int XMAX = getmaxx();
	int YMAX = getmaxy();
	int xx, yy, t, Ax = XMAX * 0.4, Ay = YMAX * 0.4;
	x = XMAX * 0.5;
	y = YMAX * 0.5;
	double dt, pi = 3.14159, pi2 = pi * 2;
	for (int i = 15; i >= 0; --i) {
		t = 0;
		cout << i;
		while (!kbhit()) {
			t++;
			dt = t * 0.00005;
			xx = x + Ax * cos(pi2 * fx * dt);
			yy = y + Ay * cos(pi2 * fy * dt + pi * f * i);
			if (i != 0) {
				j = i;
			} else {
				j++;
				if (j == 16) {
					j = 1;
				}
			};
			putpixel(xx, yy, j);
		}
	}
}


int main() {
	int x1, y1;
	float x, y, xe1, xe2, ye;
	Graph ob;
	int xasp, yasp;

	int XMAX = getmaxx();
	int YMAX = getmaxy();
	int COLORMAX = getmaxcolor() + 1;

	getaspectratio(&xasp, &yasp);
	double RATIO = (double)xasp / (double)yasp;

	x = XMAX / 2;
	y = YMAX / 2;

	moveto(3, 6);

	cout << "SCREEN: X = 0 - " << XMAX << endl;
	cout << "        Y = 0 - " << YMAX << endl;
	cout << "COLORS:     0 - " << COLORMAX - 1 << endl;
	cout << "          X/Y = " << RATIO << endl;
	getevent();

	ob.scr(3);
	xe1 = x + 30;
	xe2 = x - 30;
	ye = y - 20;
	setcolor(7);
	circle(x, y, 90);
	ob.circle(xe1, ye, 5, 9, 0);
	ob.circle(xe2, ye, 5, 9, 0);
	setcolor(4);
	arc(x, y + 90, 40, 140, 75);
	outtextxy(300, 100, "Gloomy:");
	refresh();
	getevent();

	ob.scr(6);
	setcolor(7);
	circle(x, y, 90);
	ob.circle(xe1, ye, 5, 9, 11);
	ob.circle(xe2, ye, 5, 9, 11);
	setcolor(4);
	line(xe2, 270, xe1, 270);
	outtextxy(300, 100, "Surprised:");
	refresh();
	getevent();

	ob.scr(18);
	setcolor(14);
	circle(x, y, 90);
	ob.circle(xe1, ye, 5, 9, 11);
	ob.circle(xe2, ye, 5, 9, 0);
	setcolor(4);
	arc(x, y, 200, 340, 50);
	outtextxy(300, 100, "Funny:");
	refresh();
	getevent();

	ob.scr(6);
	setcolor(10);
	ob.rect(300, 200, 40, 40);
	refresh();
	getevent();

	ob.scr(3);
	setcolor(7);
	ob.square(300, 200, 5);
	refresh();
	getevent();

	ob.scr(18);
	setcolor(12);
	ob.springArch(300, 200, 150, 5);
	refresh();
	getevent();

	ob.scr(3);
	setcolor(10);
	ob.uPascal(300, 200, 150, 5);
	refresh();
	getevent();

	ob.scr(18);
	setcolor(14);
	ob.xForm(300, 200, 50, 14);
	refresh();
	getevent();

	ob.scr(3);
	setcolor(10);
	ob.figLiss(100, 100, 5);
	refresh();
	getevent();

	return 0;
}
