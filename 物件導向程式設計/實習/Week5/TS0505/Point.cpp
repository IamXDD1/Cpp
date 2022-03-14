#include <algorithm>
#include "Point.h"

Point::Point() {
	pos[0] = 0;
	pos[1] = 0;
}
Point::~Point() {};
void Point::Set(float x, float y) {
	pos[0] = x;
	pos[1] = y;
	return;
}
void Point::Move(float x, float y) {
	pos[0] += x;
	pos[1] += y;
	return;
}
void Point::Rotate() {
	if (pos[0] != 0) pos[0] = -pos[0];
	std::swap(pos[0], pos[1]);
	return;
}
void Point::Reflect() {
	if (pos[0] != 0) pos[0] = -pos[0];
	if (pos[1] != 0) pos[1] = -pos[1];
	return;
}
float Point::GetHorizontal() {
	return pos[0];
}
float Point::GetVertical() {
	return pos[1];
}