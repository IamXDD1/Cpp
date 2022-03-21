#pragma once
#include <string>
#include <vector>

class NumberGame {
	int number;
	std::string str_num;
	std::string FileName;
	std::vector<int> validNum;
public:
	void SetInput(int);
	void ProcessInput();
	void SetFileName(std::string);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
};