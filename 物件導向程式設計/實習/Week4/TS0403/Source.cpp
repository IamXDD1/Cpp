#include <iostream>

int GCD(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else return GCD(b, a % b);
}

int main() {
	int num1, num2;

	for (; std::cin >> num1 >> num2;) {
		if (num1 > num2) std::cout << GCD(num1, num2) << '\n';
		else std::cout << GCD(num2, num1) << '\n';
	}

	return 0;
}