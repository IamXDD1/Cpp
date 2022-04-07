#include <iostream>
#include <string>
#include "Atoi.h"

using namespace std;

Atoi::Atoi() {
	beTrans = "";
}
Atoi::Atoi(string s) {
	beTrans = s;
}
void Atoi::SetString(string s) {
	beTrans = s;
	return;
}
const string Atoi::GetString(){
	return beTrans;
}
int Atoi::Length() {
	if (beTrans[0] == '-') return beTrans.length() - 1;
	return beTrans.length();
}
bool Atoi::IsDigital() {
	for (int i = 0; i < beTrans.length(); i++) {
		if ((beTrans[i] >= '0' && beTrans[i] <= '9') || (beTrans[i] == '-' && i == 0)) continue;
		else return false;
	}
	return true;
}
int Atoi::StringToInteger() {
	int temp = 0;
	if (beTrans[0] == '-') {
		for (int i = 1; i < beTrans.length(); i++) {
			temp *= 10;
			temp -= beTrans[i] - '0';
		}
	}
	else {
		for (int i = 0; i < beTrans.length(); i++) {
			temp *= 10;
			temp += beTrans[i] - '0';
		}
	}
	return temp;
}