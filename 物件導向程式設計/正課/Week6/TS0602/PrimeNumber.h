#include <cmath>
#include <iostream>

short form[10001] = {};

short find_PrimeNum(int n) {
	bool prime = true;
	for (int i = 2; i <= std::sqrt(n); i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	if (prime) return 1;
	else return -1;
}

class PrimeNumber {
public:
	int value;
	int get() {
		return value;
	}
	PrimeNumber() {
		value = 1;
	}
	PrimeNumber(int _value) {
		value = _value;
		for (int i = 2; i <= _value; i++) {
			if (form[i] == 0) form[i] = find_PrimeNum(i);
		}
		form[0] = form[1] = -1;
	}
	PrimeNumber & operator++() {
		for (int i = value + 1; true ; i++) {
			if (form[i] == -1) continue;
			else if (form[i] == 0) form[i] = find_PrimeNum(i);

			if (form[i] == 1) {
				this->value = i;
				break;
			}
		}

		return *this;
	}
	PrimeNumber operator++(int) {
		int val = this->value;

		for (int i = value + 1; true ; i++) {
			if (form[i] == -1) continue;
			else if (form[i] == 0) form[i] = find_PrimeNum(i);
			
			if (form[i] == 1) {
				this->value = i;
				break;
			}
		}

		return val;
	}
	PrimeNumber& operator--() {
		if (value == 2) {
			value = 1;
			return *this;
		}

		for (int i = value - 1; i > 1; i--) {
			if (form[i] == -1) continue;
			else if (form[i] == 0) form[i] = find_PrimeNum(i);

			if (form[i] == 1) {
				this->value = i;
				break;
			}
		}

		return *this;
	}
	PrimeNumber operator--(int) {
		int val = this->value;
		if (value == 2) return 1;

		for (int i = value-1; i > 1; i--) {
			if (form[i] == -1) continue;
			else if (form[i] == 0) form[i] = find_PrimeNum(i);

			if (form[i] == 1) {
				this->value = i;
				break;
			}
		}

		return val;
	}
};