#include <ncurses.h>
#include <random>
#include <string>
#include <vector>
#include "Screen.h"
#include "Timer.h"

int main(){
	Screen screen;
	Timer timer;
	Image dots("../resources/dots.txt", 0);
	Image splash("../resources/splash.txt", 0);
	Image title("../resources/title.txt", 0);
	Image credits("../resources/credits.txt", 0);
	Image change("../resources/change.txt", 0);

	vector<Image> pyramid;
	for(int i=0; i<18; i++){
		string filename = "../resources/pyramid/" + to_string(i) + ".txt";
		pyramid.push_back(*(new Image(filename, 1)));
	}
	

	char choice;
	screen.noDelay();
	do{
		clear();
		screen.print(title, *(new Coordinate(28, 62)));
		int i=0; 
		screen.noDelay();
		while(!screen.kbhit()){
			screen.print(pyramid.at(i), *(new Coordinate(5, 62)));
			if(i<pyramid.size()-1) i++;
			else i=0;
			refresh();
			napms(100);
		}
		screen.Delay();
		choice = getch();
		switch(choice){
			case 'a':
				char ch;
				do{
					dots.color = 0;
					screen.print(dots, *(new Coordinate));
					refresh();	
					screen.noDelay(); //Make sure you don't wait for the player to mess up
					int i=0;
					//Change 200- to random number
					while(i < 2000 && !screen.kbhit()){
						i++;
						napms(1);
					}
					//If keyboard was hit
					if(screen.kbhit()){
						change.color = 2;
						screen.print(change, *(new Coordinate));
						refresh();
						screen.flushInput();
					}else{
						change.color = 1;
						screen.print(change, *(new Coordinate));
						timer.start();
						screen.Delay();
						if(screen.kbhit())
							timer.stop();
						mvprintw(0,0, "%0.5f", timer.elapsed().count());
						ch = getch();
					}
					ch = getch();
				}while(ch != 'q' && ch != 'Q');
				break;	
			default: break;
		}
	}while(choice != 'q' && choice != 'Q');
	clear();
	screen.print(credits, *(new Coordinate(30, 90)));


/*
	timer.start();
	screen.noDelay();
	getch();
	timer.stop();
	screen.Delay();
	mvprintw(0,0, "%.9f", timer.elapsed().count());*/
	return 0;
}




