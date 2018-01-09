#include "Coordinate.h"
Coordinate Coordinate::operator+(Coordinate rhs){ 
		Coordinate result;
		result.Y = this->Y + rhs.Y; 
		result.X = this->X + rhs.X; 
		return result; 
}

Coordinate Coordinate::operator-(Coordinate rhs) { 
		Coordinate result;
		result.Y = this->Y - rhs.Y; 
		result.X = this->X - rhs.X; 
		return result; 
}

Coordinate Coordinate::operator=(Coordinate rhs) { 
		this->Y = rhs.Y; 
		this->X = rhs.X; 
		return *this; 
}

