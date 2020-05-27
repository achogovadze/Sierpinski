/*
* File: Sierpinski.cpp
* --------------------------
* Name: [TODO: enter name here]
* Section: [TODO: enter section leader here]
* This file is the starter project for the Sierpinski problem
* on Assignment #3.
* [TODO: extend the documentation]
*/

#include <iostream>
#include <math.h>
#include "simpio.h"
#include "gwindow.h"
using namespace std;

void drawTriangle(GWindow &gw, double x, double y, int side, int n);

int main() {
	GWindow gw;
	int side = getInteger("Enter size of the side of a tirangle: ");
	int n = getInteger("Enter fractal order: ");
	double x = gw.getWidth() / 2 - side / 2;
	double y = gw.getHeight() / 2 + side / 2;
	
	drawTriangle(gw, x, y, side, n);
	return 0;
}

// this method draws Sierpinski triangles starting from point "start" with size "size" and "n"-th order
void drawTriangle(GWindow &gw, double x, double y, int side, int n){
	if (n == 0){
		GPoint startPoint(x, y);
		GPoint b = gw.drawPolarLine(startPoint, side, 60);
		GPoint c = gw.drawPolarLine(b, side, -60);
		gw.drawPolarLine(c, side, 180);
	} else {
		double three = 3;
		drawTriangle(gw, x, y, side / 2, n - 1);
		drawTriangle(gw, x + side/4, y - side/2 * sqrt(three) / 2, side / 2, n - 1);
		drawTriangle(gw, x + side/2, y, side / 2, n - 1);
	}
}