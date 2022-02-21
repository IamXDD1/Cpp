#include <iostream>
#include <cmath>

int main()
{
	int input;
	for (; std::cin >> input;) {
		int k = (input - 1900) / 10;
		double temp = std::pow(2, k + 2);

		int count = 0;
		double N = 0;

		for (; N < temp; N += log2(++count));

		std::cout << count-1 << '\n';
	}
	
	return 0;
}