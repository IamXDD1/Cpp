#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

template<class T>
class Counter : public map<T, int> {
public:
	vector<pair<T, int>> obj_count;
	Counter() {};
	Counter(vector<T> items) {

		for (int i = 0; i < items.size(); i++) {
			if (this->try_emplace(items[i], 1).second == false) this->at(items[i])++;

			bool find = false;
			for (auto& it : obj_count) {
				if (it.first == items[i]) {
					it.second++;
					find = true;
					break;
				}
			}
			if (!find) obj_count.push_back({ items[i], 1 });
		}
	}

	bool cmp(pair<T, int> a, pair<T, int> b) {
		return a.second > b.second;
	}

	vector<T> most_common();
	vector<T> most_common(int n);

	int total();

	void subtract();
	void subtract(T key);
	void subtract(vector<T> keys);

	Counter<T> operator + (Counter<T> a);
	Counter<T> operator - (Counter<T> a);
	friend Counter<T> operator - (Counter<T> a);
	friend Counter<T> operator + (Counter<T> a) { return a; }
};
