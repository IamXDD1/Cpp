#pragma once
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include "Diary.h"
class Creature {
protected:
	std::string status;
	std::vector<std::string> log;
	std::map<std::string, int> bodyPart;
	std::string cname;
	std::string curr_body;
	int day_index;
public:
	Creature(std::string name);
	Creature(std::string name, Creature base);

	void updateDay();
	void PrintStatus();
	void PrintLog();

	Creature& operator[](std::string body);
	Creature& operator=(int num);
	Creature& operator+=(int num);
	Creature& operator-=(int num);
};