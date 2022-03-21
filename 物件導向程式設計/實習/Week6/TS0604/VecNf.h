#pragma once
#include <iostream>
#include <vector>

class VecNf {
	float* vec;
	int size;
public:
	VecNf();
	VecNf(float* dest, int cnt);
	VecNf(const VecNf& rhs);

	int Size();

	void operator = (VecNf a);
	float& operator [] (int index);
	VecNf operator + (VecNf a);
	VecNf operator - (VecNf a);
	float operator * (VecNf a);
	friend VecNf operator * (float num, VecNf a);
	friend VecNf operator * (VecNf a, float num);
	friend std::ostream& operator<<(std::ostream& out, VecNf v);
};