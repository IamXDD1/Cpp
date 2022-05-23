#pragma once
#include <cmath>

template<typename Type>
double absoluteValue(Type a, Type b) {
	if (b > a) return b - a;
	else return a - b;
}