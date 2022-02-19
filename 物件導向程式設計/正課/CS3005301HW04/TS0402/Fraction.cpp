#include "Fraction.h"
#include <iomanip>

int GCD(int a, int b) {
	if (b == 0) return 0;
	else if (a % b == 0) {
		return b;
	}
	else return GCD(b, a % b);
}

void Fraction::setNumerator(int nu)
{
	this->numerator = nu;
}

void Fraction::setDenominator(int de)
{
	this->denominator = de;
}

void Fraction::getDouble()
{
	double temp = static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
	if(temp - static_cast<int>(temp) >= 0.000001) std::cout << std::fixed << std::setprecision(6);
	std::cout << temp <<'\n';
	std::cout << std::fixed << std::setprecision(0);
}

void Fraction::outputReducedFraction()
{

	int temp = 0; 
	if (this->denominator > this->numerator) temp = GCD(this->denominator, this->numerator);
	else temp = GCD(this->numerator, this->denominator);

	if (temp == 0) {
		std::cout << 0 << '\n';
		return;
	}
	else if (temp == this->denominator) {
		std::cout << this->numerator / this->denominator << '\n';
	}
	else {
		std::cout << this->numerator / temp << "/" << this->denominator / temp << '\n';
	}
}



