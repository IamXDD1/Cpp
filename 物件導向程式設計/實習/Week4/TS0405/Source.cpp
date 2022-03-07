#include <iostream>
#include <algorithm>

int main() {
	int num1, num2;

	for (; std::cin >> num1 >> num2;) {
		std::cout << num1 << ' ' << num2 << ' ';

		int Ans = 0;
		if (num1 > num2) std::swap(num1, num2);

		for (int i = num1; i <= num2; i++) {
			int count = 1;
			int temp = i;
			for (; temp != 1; count++) {
				if (temp % 2 == 0) temp /= 2;
				else temp = temp * 3 + 1;
			}

			if (count > Ans) Ans = count;
		}

		std::cout << Ans << '\n';
	}

	return 0;
}