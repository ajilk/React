#include <ncurses.h>
#include "Screen.h"
#include "Timer.h"

int main(){
	Screen screen;
	Timer timer;
	timer.start();
	nodelay(stdscr, false);
	getch();
	timer.stop();
	mvprintw(0,0, "%.9f", timer.elapsed().count());
	return 0;
}
