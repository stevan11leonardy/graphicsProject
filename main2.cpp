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
	int j = 0;
	for (int i = 0; i < 12; i += 1) {
		char str[3]; 
		j++;
		
		outtextxy(51 * (i + 1) + (i * 45) + 45 / 2, 565, "Bulan-");
		outtextxy(51 * (i + 1) + (i * 45) + 45 / 2 + 45, 565, itoa(j, str, 10));
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
	
	int thickness = 15;

	setcolor(LIGHTBLUE);
	
	for (int i = thickness; i >= 0; i--) {
		rectangle(xBar + i, yBar - i, xBar + 45 + i, 549 - i);
		floodfill(xBar + i + 1, yBar + i + 1, LIGHTBLUE);
	}
	
	setcolor(BLUE);
	rectangle(xBar, yBar, xBar + 45, 549);
	
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(xBar + 1, yBar + 1, BLUE);	
	
	setcolor(WHITE);
	char str[3];
	outtextxy(xBar + 45 / 2, yBar - 35, itoa(y, str, 10));	
}

void initChart() {
	int xInit = 51;
	int yInit = 550;
	
	int data[12];
	
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		cout<< "Jumlah penjualan bulan ke-" << i + 1 << " = ";
		cin >> data[i];
	}
	
	initwindow(WINDOW_W, WINDOW_H);
	
	initContainer();
		
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		createBar(xInit * (i + 1) + (i * 45), data[i]);
	}
}

main() {
	initChart();
	
	getch();
}
