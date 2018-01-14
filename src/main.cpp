#include <ncurses.h>
#include <random>
#include <string>
#include <vector>
#include "Screen.h"
#include "Timer.h"

enum color{
	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
};

int main(){
	Screen screen;
	Timer timer;
	Image dots("../resources/dots.txt", BLACK);
	Image splash("../resources/splash.txt", BLACK);
	Image title("../resources/title.txt", BLACK);
	Image credits("../resources/credits.txt", BLACK);
	Image change("../resources/change.txt", BLACK);
	vector<Image> pyramid;
	for(int i=0; i<18; i++){
		string filename = "../resources/pyramid/" + to_string(i) + ".txt";
		pyramid.push_back(*(new Image(filename, BLUE)));
	}
	vector<Image> numbers;
	for(int i=0; i<11; i++){
		string filename = "../resources/numbers/" + to_string(i) + ".txt";
		numbers.push_back(*(new Image(filename, BLACK)));
	}

	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(500,3000); // guaranteed unbiased
	
	char choice;
	screen.noDelay();
	do{
		erase();
		screen.print(title, *(new Coordinate(28, 65)));
		int i=0; 
		screen.noDelay();
		while(!screen.kbhit()){
			screen.print(pyramid.at(i), *(new Coordinate(5, 65)));
			if(i<pyramid.size()-1) i++;
			else i=0;
			refresh();
			napms(80);
		}
		screen.Delay();
		choice = getch();
		switch(choice){
			case 'a':
				char ch;
				do{
					int sleep = uni(rng);
					dots.color = BLACK;
					screen.print(dots, *(new Coordinate));
					refresh();	
					screen.noDelay(); //Make sure you don't wait for the player to mess up
					int i=0;
					//Change 200- to random number
					while(i < sleep && !screen.kbhit()){
						i++;
						napms(1);
					}
					//If keyboard was hit
					if(screen.kbhit()){
						change.color = RED;
						screen.print(change, *(new Coordinate));
						refresh();
						screen.flushInput();
					}else{
						change.color = BLUE;
						screen.print(change, *(new Coordinate));
						timer.start();
						screen.Delay();
						if(screen.kbhit())
							timer.stop();
						string elapsed = to_string(timer.elapsed().count());
						Coordinate offset;
						clear();
						for(int i=0; i<6; i++){
							int number;
							if(elapsed.at(i) != '.') number = elapsed.at(i) - '0';
							else number = 10;
							screen.print(numbers.at(number), *(new Coordinate(27, 70+offset.X)));
							offset.X += 12;
						}
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
	return 0;
}




