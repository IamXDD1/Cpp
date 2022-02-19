#include <iostream>
#include <algorithm>
#include <vector>

bool fn_cmp(std::pair<int, int> a, std::pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	int num;
	std::vector<std::pair<int,int>> number;

	for (; std::cin >> num;) {
		bool found = false;
		for (std::vector<std::pair<int, int>>::iterator iter = number.begin(); iter != number.end(); iter++) {
			if (iter->first == num) {
				iter->second++;
				found = true;
			}
		}
		if (found == false) number.push_back({ num, 1 });
	}

	std::sort(number.begin(), number.end(), fn_cmp);

	std::cout << "N\tcount\n";
	for (int i = 0; i < number.size(); i++) {
		std::cout << number[i].first << '\t' << number[i].second << '\n';
	}

	return 0;
}