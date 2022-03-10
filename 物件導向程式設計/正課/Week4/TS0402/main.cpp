#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction f1, f2;
	f1.setNumerator(4);
	f1.setDenominator(3);
	f1.getDouble();
	f1.outputReducedFraction();

	f2.setNumerator(3);
	f2.setDenominator(3);
	f2.getDouble();
	f2.outputReducedFraction();

	return 0;
}