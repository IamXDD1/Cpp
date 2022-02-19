#include "Point.h"

void Point::Set(int vertical, int horizontal)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
	return;
}

void Point::Move(int x, int y)
{
	this->vertical += x;
	this->horizontal += y;
}
void Point::Rotate()
{
	this->vertical = -this->vertical;

	int temp = this->vertical;
	this->vertical = this->horizontal;
	this->horizontal = temp;
}
