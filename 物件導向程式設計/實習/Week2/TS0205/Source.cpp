#include <iostream>
#include <string>
#include <iomanip>

struct BigInt {
	int big_num[10000];
	int len;

	BigInt() {
		for (int i = 0; i < 10000; i++) {
			big_num[i] = -1;
		}
		this->len = 0;
	}
};

BigInt add(BigInt* a, BigInt* b) {
	int temp = 0, i=9999, j=9999, x=9999;
	BigInt Ans;
	Ans.len = a->len;

	for (; a->big_num[i] == -1; --i);
	for (; b->big_num[j] == -1; --j);

	for (; j >= 0; --x, --i, --j) {
		Ans.big_num[x] = a->big_num[i] + b->big_num[j];
		if (Ans.big_num[x] >= 10) {
			Ans.big_num[x] -= 10;
			if (i != 0) a->big_num[i - 1]++;
			else Ans.big_num[x - 1] = 1;
		}
	}

	for (; i >= 0; --i, --x) {
		Ans.big_num[x] = a->big_num[i];
		if (Ans.big_num[x] >= 10) {
			Ans.big_num[x] -= 10;
			if (i != 0) a->big_num[i - 1]++;
			else Ans.big_num[x-1] = 1;
		}
	}

	Ans.len = 9999 - x;
	
	return Ans;
}

int main() {
	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		BigInt NumA, NumB;
		std::string input;
		bool valid = true;

		std::cin >> input;
		NumA.len = input.length();

		for (int i = 0; i < NumA.len; ++i) {
			if (!(input[i] >= '0' && input[i] <= '9')) {
				valid = false;
				break;
			}
			else {
				NumA.big_num[i] = input[i] - '0';
			}
		}

		std::cin >> input;
		NumB.len = input.length();
		if (valid)
		{
			for (int i = 0; i < NumB.len; ++i) {
				if (!(input[i] >= '0' && input[i] <= '9')) {
					valid = false;
					break;
				}
				else {
					NumB.big_num[i] = input[i] - '0';
				}
			}
		}
		if (valid) {
			BigInt Result;
			if (NumA.len > NumB.len) {
				Result = add(&NumA, &NumB);
			}
			else {
				Result = add(&NumB, &NumA);
			}
			
			for (int i = 0; i < 10000; i++) {
				if(Result.big_num[i] != -1)
					std::cout << Result.big_num[i];
			}
			std::cout << '\n';
		}
		else {
			std::cout << "Not a valid number, please try again.\n";
		}
	}

	return 0;
}