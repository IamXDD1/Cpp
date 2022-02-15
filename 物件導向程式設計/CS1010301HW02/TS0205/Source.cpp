#include <iostream>
#include <string>
#include <iomanip>

struct BigInt {
	std::string num;
};//????

BigInt add(BigInt*& a, BigInt*& b) {
	int temp = 0;
	BigInt Ans;
	int j = a->num.length() - 1;
	for (int i = b->num.length()-1; i >= 0; i--, j--) {
		temp = a->num[j] - '0' + b->num[i] - '0';
		if (temp >= 10) {
			temp -= 10;
			if (j - 1 >= 0) a->num[j - 1]++;
			else Ans.num = "1";
		}
		a->num[j] = temp + '0';
	}
	for (; j >= 0; j--) {
		temp = a->num[j] - '0';
		if (temp >= 10) {
			temp -= 10;
			if (j - 1 >= 0) a->num[j - 1]++;
			else Ans.num = "1";
		}
		a->num[j] = temp + '0';
	}
	Ans.num += a->num;
	return Ans;
}

int main() {
	int n = 0;
	std::cin >> n;

	for (unsigned int i = 0; i < n; i++) {
		BigInt* NumA = new BigInt;
		BigInt* NumB = new BigInt;
		bool validA = true;
		bool validB = true;

		std::cin >> NumA->num >> NumB->num;

		for (int i = 0, j = 0; i < NumA->num.length() || j < NumB->num.length(); ) {
			if (i >= NumA->num.length() || (NumA->num[i] >= '0' && NumA->num[i] <= '9')) {
				++i;
			}
			else {
				validA = false;
				++i;

			}

			if (j >= NumB->num.length() || (NumB->num[j] >= '0' && NumB->num[j] <= '9')) {
				++j;
			}
			else {
				validB = false;
				++j;
			}
		}

		if (validA && validB) {
			BigInt Result;
			if (NumA->num.length() > NumB->num.length()) {
				Result = add(NumA, NumB);
			}
			else {
				Result = add(NumB, NumA);
			}
			std::cout << Result.num << '\n';
		}
		else {
			std::cout << "Not a valid number, please try again.\n";
		}

		delete NumA;
		delete NumB;
	}

	return 0;
}