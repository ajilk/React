#include "Image.h"

Image::Image(string filename, int color) : color(color){
	open(filename);
}

void Image::open(string filename){
	char ch;
	ifstream infile;
	infile.open(filename);
	if(!infile.is_open())
		mvprintw(0,0,"ERROR: Could not open file %s", filename.c_str());
	image.clear();
	while(infile.get(ch))
		image.push_back(ch);	
}
