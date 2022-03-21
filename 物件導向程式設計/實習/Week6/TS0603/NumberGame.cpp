#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "NumberGame.h"

std::fstream inFile;

std::unordered_map<int, bool> map;

void findNum(std::string num, int index, bool multiple, int found) {
	if (index > 0)
	{
		if (multiple) found *= num[index] - '0';

		findNum(num, index-1, true, found);
		findNum(num, index-1, false, found);

		return;
	}
	else {
		if (multiple) found *= num[index] - '0';
		map[found] = true;
		return;
	}
}

void NumberGame::SetInput(int num) {
	number = num;
	return;
}
void NumberGame::ProcessInput() {
	str_num = std::to_string(number);

	findNum(str_num, str_num.length()-1, true, 1);
	findNum(str_num, str_num.length()-1, false, 1);

	bool checkOne = false;
	for (int i = 0; i < str_num.length(); i++) {
		if (str_num[i] == '1') {
			checkOne = true;
			break;
		}
	}
	if (!checkOne) map[1] = false;
	return;
}
void NumberGame::SetFileName(std::string name) {
	FileName = name;
	return;
}
void NumberGame::LoadNumberList() {
	inFile.open(FileName);

	int temp = 0;
	for (; inFile >> temp;) {
		if(map[temp] == true) validNum.push_back(temp);
	}

	inFile.close();
	return;
}
void NumberGame::PrintAllValid() {
	for (int i = 0; i < validNum.size(); i++) {
		std::cout << validNum[i] << '\n';
	}
	return;
}
void NumberGame::Reset() {
	FileName = "";
	validNum.clear();
	str_num = "";
	number = 0;
	map.clear();
	return;
}