#include <iostream>
#include <string>
#include <vector>
#include <cmath>
//DP like LCS
//如果兩個 char 不相同，則對角跳轉+1，否則為0
void Levenshtein(int** DP, std::string& changed, std::string& cmp);

int min(int num1, int& num2, int& num3) {
	if (num1 > num2) num1 = num2;
	if (num1 > num3) num1 = num3;
	return num1;
}

int main() {
	std::string changed, cmp;
	for (; std::getline(std::cin, changed);) {
		std::getline(std::cin, cmp);
		
		int** DP = new int* [changed.size()+1];
		for (int i = 0; i <= changed.size(); i++) {
			DP[i] = new int[cmp.size()+1];
		}
		
		Levenshtein(DP, changed, cmp);
		
		for (int i = 0; i <= changed.size(); i++) {
			delete[] DP[i];
		}
		delete[] DP;
	}
	return 0;
}

void Levenshtein(int** DP, std::string& changed, std::string& cmp) {
	for (int i = 0; i <= changed.size(); i++) DP[i][0] = i;
	for (int i = 0; i <= cmp.size(); i++) DP[0][i] = i;

	for (int i = 1; i <= changed.size(); i++) {
		for (int j = 1; j <= cmp.size(); j++) {
			DP[i][j] = min(DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]);
			if (changed[i - 1] != cmp[j - 1]) {
				DP[i][j]++;
			}
			else {
				if (DP[i][j] != DP[i - 1][j - 1]) DP[i][j]++;
			}
		}
	}

	std::cout << DP[changed.size()][cmp.size()] << '\n';
}