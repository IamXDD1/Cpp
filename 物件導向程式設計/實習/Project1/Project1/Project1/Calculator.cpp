#include "Calculator.h"

void Calculator::RUN()
{
}

void Calculator::Input()
{
}

bool Calculator::judgeFormat()
{
	//找不到變數
	//非法運算式 /0  0.1!
	//括號不完全
	return false;
}

void Calculator::Output()
{
}

void Calculator::test()
{
	Number A("1.5");
	Number C("abc");

	A = C;

	std::cout << A << '\n';
}
