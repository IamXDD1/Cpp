#include "VecNf.h"
#include <iostream>
#include <vector>

VecNf::VecNf() : vec(nullptr), size(0) {};
VecNf::VecNf(float* dest, int cnt) : vec(dest), size(cnt) {};
VecNf::VecNf(const VecNf& rhs) {
	this->size = rhs.size;
	float* tempArr = new float[rhs.size];
	for (int i = 0; i < rhs.size; i++) {
		tempArr[i] = rhs.vec[i];
	}
	this->vec = tempArr;
}

int VecNf::Size() { return this->size; }

void VecNf::operator=(VecNf a) {
	std::cout << "ASSIGNMENT!!!\n";
	this->size = a.size;
	float* tempArr = new float[a.size];
	for (int i = 0; i < a.size; i++) {
		tempArr[i] = a.vec[i];
	}
	this->vec = tempArr;
}
float& VecNf::operator[](int index) {
	return vec[index];
}
VecNf VecNf::operator+(VecNf a) {
	if (this->size != a.size) {
		std::cout << "dimensions inconsistent\n";
		return VecNf();
	}
	else {
		float* tempArr = new float[this->size];
		for (int i = 0; i < a.size; i++) {
			tempArr[i] = this->vec[i] + a.vec[i];
		}
		return VecNf(tempArr, this->size);
	}
}
VecNf VecNf::operator-(VecNf a) {
	if (this->size != a.size) {
		std::cout << "dimensions inconsistent\n";
		return VecNf();
	}
	else {
		float* tempArr = new float[this->size];
		for (int i = 0; i < a.size; i++) {
			tempArr[i] = this->vec[i] - a.vec[i];
		}
		return VecNf(tempArr, this->size);
	}
}
float VecNf::operator*(VecNf a) {
	if (this->size != a.size) {
		std::cout << "dimensions inconsistent\n";
		return 0;
	}
	else {
		float temp = 0;
		for (int i = 0; i < this->size; i++) {
			temp += this->vec[i] * a.vec[i];
		}
		return temp;
	}
}
VecNf operator * (float num, VecNf a) {
	float* tempArr = new float[a.size];
	for (int i = 0; i < a.size; i++) {
		tempArr[i] = a.vec[i] * num;
	}
	return VecNf(tempArr, a.size);
}
VecNf operator * (VecNf a, float num) {
	float* tempArr = new float[a.size];
	for (int i = 0; i < a.size; i++) {
		tempArr[i] = a.vec[i] * num;
	}
	return VecNf(tempArr, a.size);
}

std::ostream& operator<<(std::ostream& out, VecNf v) {
	for (int i = 0; i < v.size; i++) {
		out << v[i] << ' ';
	}
	return out;
}

//注意指標型態的賦予 要避免弄在同個位址上 因此要使用new