#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	std::string str;

	for (; std::cin >> str;) {
		
		double temp = std::sqrt(str.length());
		int n = static_cast<int>(temp);
		if (temp - n > 0) {
			++n;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i + j * n < str.length()) std::cout << str[i + j * n];
			}
			std::cout << '\n';
		}
	}
	

	return 0;
}