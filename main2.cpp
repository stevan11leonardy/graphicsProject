#include<graphics.h>
#include <iostream>  
#include<string> 

using namespace std;  

const int WINDOW_W = 1320;
const int WINDOW_H = 650;

void initYAxisLegend() {
	// show y axis legend
	for (int i = 0; i <= 500; i += 50) {
		char str[3]; 
		int j = i;
		
		outtextxy(10, 550 - i, itoa(j, str, 10));	
	}
}

void initXAxisLegend() {
	// show x axis legend
	int j = 13;
	for (int i = 0; i <= 1100; i += 1100 / 11) {
		char str[3]; 
		j--;
		
		outtextxy(1218 - i - 45, 580, "Bulan-");
		outtextxy(1218 - i, 580, itoa(j, str, 10));
	}
}

void initContainer() {
	line(50, 50, 50, 550);
	line(50, 550, 1250, 550);
	
	initYAxisLegend();
	initXAxisLegend();
}

void createBar(int x, int y) {
	int barWidth = 45 / 2;
	
	int xBar = x + barWidth;
	int yBar = 550 - y;
	

	setcolor(LIGHTBLUE);
	
	int thickness = 15;
	
	for (int i = thickness; i >= 0; i--) {
		rectangle(xBar + i, yBar - i, xBar + 45 + i, 549 - i);
		floodfill(xBar + i + 1, yBar + i + 1, LIGHTBLUE);
		
	}
	
	setcolor(BLUE);
	rectangle(xBar, yBar, xBar + 45, 549);
	
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(xBar + 1, yBar + 1, BLUE);
	
//	line(xBar, yBar, xBar + thickness, yBar - thickness);
//	line(xBar + 45, yBar, xBar + 45 + thickness, yBar - thickness);
//	line(xBar + 45, 549, xBar + 45 + thickness, 549 - thickness);
	
//	rectangle(xBar + thickness, yBar - thickness, xBar + 45 + thickness, 549 - thickness);
}

void initChart() {
	int xInit = 51;
	int yInit = 550;
	
	createBar(xInit, 175);
}

main() {
	initwindow(WINDOW_W, WINDOW_H);
	
	initContainer();
	
	initChart();
	
	getch();
}
