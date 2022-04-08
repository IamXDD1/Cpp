#pragma once
#include <vector>
#include <string>

class Diary {
public:
	static std::vector<std::string> date;
	static void NewDay(std::string day) {
		date.push_back(day);
	}
};

