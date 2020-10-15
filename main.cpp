#include<graphics.h>

main() {
	initwindow(600, 800);
	
	line(280, 380, 320, 380); // A - B
	line(320, 380, 320, 350); // B - C
	line(320, 350, 300, 330); // C - D
	line(300, 330, 280, 350); // D - E
	line(280, 350, 280, 380); // E - A
	
	getch();
}
