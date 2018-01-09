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
	void print(Image image, Coordinate start); 
	~Screen();
};

#endif
