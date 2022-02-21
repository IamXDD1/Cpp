#include <iostream>
#include <string>
#include <iomanip>

int main() {

	float n = 0;
	for (; std::cin >> n;) {
		std::cout << std::fixed << std::setprecision(2);

		if (n < 750) std::cout << n * 0.01;
		else if (n >= 750 && n < 2250) std::cout << 7.5 + (n - 750) * 0.02;
		else if (n >= 2250 && n < 3750) std::cout << 37.5 + (n - 2250) * 0.03;
		else if (n >= 3750 && n < 5250) std::cout << 82.5 + (n - 3750) * 0.04;
		else if (n >= 5250 && n < 7000) std::cout << 142.5 + (n - 5250) * 0.05;
		else if (n >= 7000) std::cout << 230 + (n - 7000) * 0.06;

		std::cout << "\n";
	}

	return 0;
}