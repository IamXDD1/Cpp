#include "PrintCombination.h"
std::vector<std::vector<int>> allAns;
void PrintCombination(int* arr, int size, int down) {
	std::vector<int> ans;
	Combination(arr, size, down, 0, 0, true, ans);
	Combination(arr, size, down, 0, 0, false, ans);

	for (int i = 0; i < allAns.size(); i++) {
		for (int j = 0; j < allAns[i].size(); j++) {
			std::cout << allAns[i][j];
			if (j != allAns[i].size() - 1) std::cout << ' ';
		}
		if (i != allAns.size() - 1) std::cout << '\n';
	}
}
void Combination(int* arr, int size, int down, int index, int count, bool choosed, std::vector<int> ans) {
	if (index < size) {
		if (choosed) {
			ans.push_back(arr[index]);
			count++;
		}
		if (count < down) {
			Combination(arr, size, down, index + 1, count, true, ans);
			Combination(arr, size, down, index + 1, count, false, ans);
		}
		else {
			allAns.push_back(ans);
		}
	}
}