#include <iostream>
#include <iomanip>
int main() {
	long double num;

	for (; std::cin >> num;)
	{
		long double guess = num / 2;
		long double temp = 0;
		long double r = 0;
		do {
			r = num / guess;
			temp = guess;
			guess = (guess + r) / 2;

		} while (temp - guess > 0.01);

		std::cout << std::fixed << std::setprecision(2) << r << '\n';
	}

	


	return 0;
}