#include <cmath>
#include "Polynomial.h"

Polynomial::Polynomial() : poly(nullptr), size(0), index(0) {};
Polynomial::Polynomial(double* param, int size) : poly(param), size(size), index(0) {};
Polynomial::Polynomial(const Polynomial& rhs) : size(rhs.size), index(rhs.index) {
	poly = new double[rhs.size];

	for (int i = 0; i < rhs.size; i++) {
		poly[i] = rhs.poly[i];
	}
}
//Polynomial::~Polynomial() { delete[] poly; }

int Polynomial::mySize()
{
	int temp = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (poly[i] != 0) {
			temp = i + 1;
			break;
		}
	}
	return temp;
}

double evaluate(const Polynomial& poly, const double& var)
{
	double temp = 0;
	for (int i = 0; i < poly.size; i++) {
		temp += std::pow(var, i) * poly.poly[i];
	}
	return temp;
}

Polynomial& Polynomial::operator=(const Polynomial& poly)
{
	double* temp = new double[poly.size]{};
	for (int i = 0; i < poly.size; i++) {
		temp[i] = poly.poly[i];
	}
	delete[] this->poly;
	this->poly = temp;
	this->size = poly.size;
	return *this;
}

double& Polynomial::operator[](const int& index)  
{
	if (index >= size) {
		double* temp = new double[index+1]{};
		for (int i = 0; i <= index; i++) {
			if (i < size) temp[i] = poly[i];
			else temp[i] = 0;
		}
		
		poly = temp;
		size = index + 1; // ­×§ïsize¤j¤p
	}
	return poly[index];
}

Polynomial Polynomial::operator+(const Polynomial& poly)
{
	int biggerSize = poly.size > this->size ? poly.size : this->size;
	double* temp = new double[biggerSize] {};
	for (int i = 0; i < biggerSize; i++) {
		if (this->size > i) temp[i] += this->poly[i];
		if(poly.size > i) temp[i] += poly.poly[i];
	}
	return Polynomial(temp, biggerSize);
}

Polynomial Polynomial::operator-(const Polynomial& poly)
{
	int biggerSize = poly.size > this->size ? poly.size : this->size;
	double* temp = new double[biggerSize]{};
	for (int i = 0; i < biggerSize; i++) {
		if (this->size > i) temp[i] += this->poly[i];
		if (poly.size > i) temp[i] -= poly.poly[i];
	}
	return Polynomial(temp, biggerSize);
}

Polynomial Polynomial::operator*(const Polynomial& poly)
{
	int biggerSize = poly.size + this->size - 1;
	double* temp = new double[biggerSize] {};
	for (int i = 0; i < poly.size; i++) {
		for (int j = 0; j < this->size; j++) {
			temp[i + j] += this->poly[j] * poly.poly[i];
		}
	}
	return Polynomial(temp, biggerSize);
}

Polynomial operator+(const double indexconst, Polynomial& poly)
{
	double* temp = new double[poly.size]{};
	for (int i = 0; i < poly.size; i++) {
		temp[i] = poly.poly[i];
	}
	temp[0] += indexconst;
	return Polynomial(temp, poly.size);
}

Polynomial Polynomial::operator+(const double indexconst)
{
	double* temp = new double[size]{};
	for (int i = 0; i < size; i++) {
		temp[i] = poly[i];
	}
	temp[0] += indexconst;
	return Polynomial(temp, size);
}

Polynomial operator-(const double indexconst, Polynomial& poly)
{
	double* temp = new double[poly.size]{};
	for (int i = 0; i < poly.size; i++) {
		temp[i] = -poly.poly[i];
	}
	temp[0] += indexconst;
	return Polynomial(temp, poly.size);
}

Polynomial Polynomial::operator-(const double indexconst)
{
	double* temp = new double[size]{};
	for (int i = 0; i < size; i++) {
		temp[i] = poly[i];
	}
	temp[0] -= indexconst;
	return Polynomial(temp, size);
}

Polynomial operator*(const double indexconst, Polynomial& poly)
{
	double* temp = new double[poly.size]{};
	for (int i = 0; i < poly.size; i++) {
		temp[i] = poly.poly[i] * indexconst;
	}
	return Polynomial(temp, poly.size);
}

Polynomial Polynomial::operator*(const double indexconst)
{
	double* temp = new double[size]{};
	for (int i = 0; i < size; i++) {
		temp[i] = poly[i] * indexconst;
	}
	return Polynomial(temp, size);
}