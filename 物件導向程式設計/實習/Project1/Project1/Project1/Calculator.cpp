#include "Calculator.h"

void Calculator::RUN()
{
}

void Calculator::Input()
{
}

bool Calculator::judgeFormat()
{
	//�䤣���ܼ�
	//�D�k�B�⦡ /0  0.1!
	//�A��������
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
