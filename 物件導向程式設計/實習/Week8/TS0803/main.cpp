#include <iostream>
#include <string>
#include <cmath>
#include <vector>

void set(int*& memory, const int& size);
void get(int*& memory, const int& size);
unsigned long long int stringToInt(std::string s)//沒有 long long 會少輸出 ， 有 long long 輸出亂碼
{
	unsigned long long int n = 0;
	unsigned long long int c = 1;
	unsigned long long int temp = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		temp += (s[i] - '0') * c;
		if (n > temp) break;
		else {
			c *= 10;
			n = temp;
		}
	}
	return n;
}
int main() {
	int size;
	for (; std::cin >> size;) {
		int* memory = new int[size] {};

		int numOfCmd;
		std::cin >> numOfCmd;

		for (int i = 0; i < numOfCmd; i++) {
			std::string cmd;
			std::cin >> cmd;

			if (cmd == "Set") set(memory, size);
			else if (cmd == "Get") get(memory, size);
		}

		delete[] memory;
	}
	return 0;
}

void set(int*& memory, const int& size) {
	int pos;
	std::string type;
	std::cin >> pos >> type;
	std::cin.get();
	std::string setString;
	std::getline(std::cin, setString);

	if (type == "String") {
		for (int i = 0; i <= setString.size(); i++) {
			if (pos + i >= size || pos + i < 0) {
				std::cout << "Violation Access.\n";
				return;
			}
			else if (i == setString.size()) memory[pos + i] = 0;
			else memory[pos + i] = static_cast<int>(setString[i]);
		}
	}
	else if (type == "char") {
		int setChar = std::stoi(setString);
		if (pos >= size || pos < 0) { std::cout << "Violation Access.\n"; return; }

		memory[pos] = setChar;
	}
	else if (type == "int") { //============ num too long =================
		unsigned long long int setInt = stringToInt(setString);
		
		for (int i = 0; i < 4; i++) {
			if (pos+i >= size || pos+i < 0) { std::cout << "Violation Access.\n"; return; }
			else {
				memory[pos + i] = setInt % 256;
				setInt /= 256;
			}
		}
		
	}
	else if (type == "short") {
		int setShort = std::stoi(setString);

		for (int i = 0; i < 2; i++) {
			if (pos+i >= size || pos < 0) { std::cout << "Violation Access.\n"; return; }
			else {
				memory[pos + i] = setShort % 256;
				setShort /= 256;
			}
		}
	}
}
void get(int*& memory, const int& size) {
	int pos;
	std::string type;
	std::cin >> pos >> type;

	if (type == "String") {
		if (pos >= size || pos < 0) { std::cout << "Violation Access.\n"; return; }
		for (int i = pos; i < size && memory[i] != 0; i++) {
			std::cout << static_cast<char>(memory[i]);
		}
		std::cout << '\n';
	}
	else if (type == "char") {
		if (pos >= size || pos < 0) { std::cout << "Violation Access.\n"; return; }
		if (memory[pos] < 128) std::cout << static_cast<char>(memory[pos]) << '\n';
		else std::cout << static_cast<char>(memory[pos]) << '\n';
	}
	//==
	else if (type == "int") {
		int temp = 0;
		for (int i = 0; i < 4; i++) {
			if (pos + 4 >= size || pos < 0) { std::cout << "Violation Access.\n"; return; }
			else temp += memory[pos + i] * std::pow(256, i);
		}
		std::cout << temp << '\n';
	}
	else if (type == "short") {
		int temp = 0;
		for (int i = 0; i < 2; i++) {
			if (pos + i >= size || pos < 0) { std::cout << "Violation Access.\n"; return; }
			else temp += memory[pos + i] * std::pow(256, i);
		}
		std::cout << temp << '\n';
	}
}