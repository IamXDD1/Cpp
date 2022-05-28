#pragma once
#include <iostream>
#include <vector>

using namespace std;

void recursive(vector<int> vec_arr, int* arr, int up, int down, int index, bool choosed) {
	
	if (index < up) {
		if (choosed) vec_arr.push_back(arr[index]);

		if (vec_arr.size() == down) {
			for (int i = 0; i < vec_arr.size(); i++) {
				cout << vec_arr[i];
				if(i != vec_arr.size()-1) cout << ' ';
			}
			cout << '\n';
			return;
		}

		recursive(vec_arr, arr, up, down, index + 1, true);
		recursive(vec_arr, arr, up, down, index + 1, false);
	}
}

void PrintCombination(int* arr, int up, int down) {
	vector<int> vec_arr;
	
	recursive(vec_arr, arr, up, down, 0, true);
	recursive(vec_arr, arr, up, down, 0, false);
}