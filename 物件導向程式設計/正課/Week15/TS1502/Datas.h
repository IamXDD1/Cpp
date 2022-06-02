#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Datas {
	vector<pair<pair<string, string>, int>> books; // <title, author>, edition
public:
	Datas() {};

	void Insert(string title, string author, int edition);
	void Delete_Edition(string title, string author, int edition);
	void Delete_Book(string title, string author);
	void Find_Book(string title, string author);
	void Find_Author(string author);
	void Sort_by_Title();
	void Sort_by_Author();

	struct cmp_title {
		bool operator() (const pair<string, string>& a, const pair<string, string>& b) const {
			if (a.first != b.first) return a.first < b.first;
			else return a.second < b.second;
			return false;
		}
	};

	struct cmp_author {
		bool operator() (const pair<string, string>& a, const pair<string, string>& b) const {
			if (a.second != b.second) return a.second < b.second;
			else return a.first < b.first;
			return false;
		}
	};
};


