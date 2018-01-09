#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate{
public:
	int X, Y;
	Coordinate() : Y(0), X(0) {} 
	Coordinate(int Y, int X) : Y(Y), X(X) {}
	Coordinate operator+(Coordinate rhs);
	Coordinate operator-(Coordinate rhs);
	Coordinate operator=(Coordinate rhs);
};

#endif
