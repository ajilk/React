#ifndef IMAGE_H
#define IMAGE_H

#include <ncurses.h>
#include <vector>
#include <fstream>
using namespace std;

class Image{
private:
	vector<char> image;
public:
	int color;
	Image() :  color(0) {}
	Image(string filename, int color);
	void open(string filename);
	vector<char> getImage() { return image; }
};

#endif