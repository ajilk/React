#include "Screen.h"

Screen::Screen(){
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	use_default_colors();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLUE);
	init_pair(2, COLOR_RED, COLOR_RED);
}

bool Screen::kbhit(){
	int ch = getch();
	if(ch != ERR){
		ungetch(ch);
		return true;
	}else
		return false;
}

void Screen::flushInput(){
	noDelay();
	int ch;
	do{
		ch = getch();
	}while(ch != ERR);
	Delay();
}

void Screen::print(Image img, Coordinate start){
	vector<char> image = img.getImage();
	Coordinate pos(0,0);
	for(int i=0; i<image.size(); i++){
		char ch = image.at(i);	
		switch(ch){
			case '\n': 
				pos.X=0; 
				pos.Y++; 
				break;
			case ' ': 
				mvprintw(start.Y+pos.Y, start.X+pos.X, "%c", ch); 
				pos.X++; 
				break;
			default:
				attron(COLOR_PAIR(img.color)); 
				mvprintw(start.Y+pos.Y, start.X+pos.X, "%c", ch); pos.X++;
				attroff(COLOR_PAIR(img.color)); 
				break;
		}
	}
}

Screen::~Screen(){
	refresh();
	Delay();
	getch();
	clear();
	refresh();
	endwin();
}
