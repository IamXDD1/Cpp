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
	bool judgeFormat(); //�P�_�W�r �Y���ܼƫh��������
	void valToNum();
	void Output();
	void test();
};