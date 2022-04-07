#pragma once
#include <iostream>

class Polynomial {
	double* poly;
	int size;
	int index;
public:
	Polynomial();
	Polynomial(double* param, int size);
	Polynomial(const Polynomial& rhs);
	//~Polynomial();

	int mySize();
	friend double evaluate(const Polynomial& poly, const double& var);

	Polynomial& operator=(const Polynomial& poly);
	double& operator[](const int& index);

	Polynomial operator+(const Polynomial& poly);
	friend Polynomial operator+(const double indexconst, Polynomial& poly);
	Polynomial operator+(const double indexconst);
	
	Polynomial operator-(const Polynomial& poly);
	friend Polynomial operator-(const double indexconst, Polynomial& poly);
	Polynomial operator-(const double indexconst);

	Polynomial operator*(const Polynomial& poly);
	friend Polynomial operator*(const double indexconst, Polynomial& poly);
	Polynomial operator*(const double indexconst);
};