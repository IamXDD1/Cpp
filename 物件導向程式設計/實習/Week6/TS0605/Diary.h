#pragma once
#include <string>
#include <vector>
class Diary {
	static std::string date;
public:
	static int date_index;
	static std::vector<std::string> full_date;
	static void NewDay(std::string day);
};