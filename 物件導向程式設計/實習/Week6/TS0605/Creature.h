#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Diary.h"

class Creature {
	std::vector<std::string> status;
	std::vector<std::string> log;
	std::map<std::string, int> body;
	std::string name;
	std::string curr_body;
	int index;
public:
	Creature(std::string name);
	Creature(std::string name, Creature a);

	void updatedate();
	void PrintStatus();
	void PrintLog();

	Creature& operator[](std::string bodypart);
	Creature operator=(int num);
	Creature operator+=(int num);
	Creature operator-=(int num);
};
