#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Number.h"

using namespace std;

class Calculator {
	vector<Number*> record;
public:
	void RUN();
	void Input();
	bool judgeFormat(); //判斷名字 若有變數則直接替換
	void valToNum();
	void Output();
	void test();
};