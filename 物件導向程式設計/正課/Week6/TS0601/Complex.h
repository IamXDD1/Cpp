#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
public:
	double realValue, imaginaryValue;

	Complex() {
		realValue = 0;
		imaginaryValue = 0;
	}
	//~Complex();
	Complex(double r) {
		realValue = r;
		imaginaryValue = 0;
	}
	//~Complex(double r);
	Complex(double r, double i) {
		realValue = r;
		imaginaryValue = i;
	}
	//~Complex(double r, double i);
	double real() { return realValue; }
	double imag() { return imaginaryValue; }
	double norm() { return std::sqrt(realValue * realValue + imaginaryValue * imaginaryValue); }
	friend double real(Complex c) { return c.realValue; }
	friend double imag(Complex c) { return c.imaginaryValue; }
	friend double norm(Complex c) { 
		return std::sqrt(c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue);
	}
	Complex operator+(Complex c) {
		Complex temp;
		temp.imaginaryValue = this->imaginaryValue + c.imaginaryValue;
		temp.realValue = this->realValue + c.realValue;
		
		return temp;
	}
	Complex operator-(Complex c) {
		Complex temp;
		temp.imaginaryValue = this->imaginaryValue - c.imaginaryValue;
		temp.realValue = this->realValue - c.realValue;

		return temp;
	}
	Complex operator*(Complex c) {
		Complex temp;
		temp.imaginaryValue = this->realValue * c.imaginaryValue + this->imaginaryValue * c.realValue;
		temp.realValue = this->realValue * c.realValue - this->imaginaryValue * c.imaginaryValue;

		return temp;
	}
	Complex operator/(Complex c) {
		Complex temp;
		Complex Conjugate;
		Conjugate.realValue = c.realValue;
		Conjugate.imaginaryValue = -c.imaginaryValue;

		double divide = (c * Conjugate).realValue;
		
		temp.realValue = (*this * Conjugate).realValue / divide;
		temp.imaginaryValue = (*this * Conjugate).imaginaryValue / divide;

		return temp;
	}
	friend Complex operator+(double d, Complex c) {
		Complex temp = c;
		temp.realValue += d;
		return temp;
	}
	friend Complex operator-(double d, Complex c) {
		Complex temp = c;
		temp.realValue -= d;
		temp.realValue = -temp.realValue;
		temp.imaginaryValue = -temp.imaginaryValue;
		return temp;
	}
	friend Complex operator*(double d, Complex c) {
		Complex temp(d);
		return temp * c;
	}
	friend Complex operator/(double d, Complex c) {
		Complex temp(d);
		return temp / c;
	}
	friend bool operator==(Complex c1, Complex c2) {
		if (c1.imaginaryValue == c2.imaginaryValue && c1.realValue == c2.realValue) return true;
		else return false;
	}
	friend ostream& operator<<(ostream& strm, const Complex& c) {
		strm << c.realValue << " + " << c.imaginaryValue << "*i";
		return strm;
	}
	friend istream& operator>>(istream &strm,Complex &c) {
		char skip;
		strm >> skip >> skip >> c.realValue >> skip >> c.imaginaryValue >> skip >> skip;
		return strm;
	}
};
