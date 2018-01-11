#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>	//exit()
#include <vector>
#include "Coordinate.h"
#include "Image.h"

class Screen{
public:
	Screen();
	bool kbhit();
	void flushInput();
	void print(Image image, Coordinate start); 
	void Delay() { nodelay(stdscr, false); };
	void noDelay() { nodelay(stdscr, true); };
	~Screen();
};

#endif
