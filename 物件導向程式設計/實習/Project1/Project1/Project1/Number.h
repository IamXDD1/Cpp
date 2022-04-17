#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Number {
	string name;
	string num; //Bignum ¥Î vector
	string decimal;
	bool Integer;
	bool negative;
public:
	Number();
	Number(string a);

	inline string getNum() { return num; }
	inline string getDecimal() { return decimal; }

	Number& operator = (Number a);
	Number operator + (Number a);
	Number operator - (Number a);
	Number operator * (Number a);
	Number operator / (Number a);
	Number operator ! ();
	friend std::ostream& operator << (std::ostream& out, Number a);

	string calculate();
};