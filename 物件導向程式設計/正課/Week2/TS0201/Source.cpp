#include <iostream>
#include <cmath>

int main() {
	int n;
	for (; std::cin >> n;) {
		double* ip_nums = new double[n];

		double average = 0;
		double standard_deviation = 0;
		double num = 0;

		for (int i = 0; i < n; i++) {
			std::cin >> num;
			ip_nums[i] = num;
			average += num;
		}
		
		average /= n;

		for (int i = 0; i < n; i++) {
			standard_deviation += std::pow(ip_nums[i] - average, 2);
		}

		standard_deviation /= n;

		std::cout << "Average:" << average << "\tStandard deviation:" 
			<< std::sqrt(standard_deviation) << '\n';

		delete[] ip_nums;
	}

	return 0;
}