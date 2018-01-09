#include "Screen.h"

Screen::Screen(){
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	use_default_colors();
	start_color();
	nodelay(stdscr, TRUE);
}

bool Screen::kbhit(){
	int ch = getch();
	if(ch != ERR){
		ungetch(ch);
		return true;
	}else
		return false;
}

void Screen::print(Image img, Coordinate start){
	vector<char> image = img.getImage();
	int color = img.getColor();
	Coordinate pos(0,0);
	for(int i=0; i<image.size(); i++){
		char ch = image.at(i);	
		switch(ch){
			case '\n': 
				pos.X=0; 
				pos.Y++; 
				break;
			case ' ': 
//				mvprintw(start.Y+pos.Y, start.X+pos.X, "%c", ch); 
				pos.X++; 
				break;
			default:
				attron(COLOR_PAIR(color)); 
				mvprintw(start.Y+pos.Y, start.X+pos.X, "%c", ch); pos.X++;
				attroff(COLOR_PAIR(color)); 
				break;
		}
	}
}

Screen::~Screen(){
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}
