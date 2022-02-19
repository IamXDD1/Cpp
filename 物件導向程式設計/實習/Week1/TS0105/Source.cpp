#include <iostream>
#include <iomanip>

int main() {
	long double PI = 3.14159265358979323846;
	double r = 0;

	for (;std::cin>> r;) {
		std::cout << std::fixed << std::setprecision(6) << r*r*r * 4/3 * PI <<"\n";
	}

	return 0;
}