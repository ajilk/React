#ifndef IMAGE_H
#define IMAGE_H

#include <ncurses.h>
#include <vector>
#include <fstream>
using namespace std;

class Image{
private:
	vector<char> image;
	int color;
public:
	Image() :  color(0) {}
	Image(string filename);
	void open(string filename);
	void setColor(int color) { this->color = color; }
	int getColor() { return color; }
	vector<char> getImage() { return image; }
};

#endif
