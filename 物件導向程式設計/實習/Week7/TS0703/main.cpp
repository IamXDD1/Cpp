#include <iostream>
#include <string>
#include <vector>

inline void format(std::vector<std::string>& first, std::vector<std::string>& sec,
	std::vector<std::string>& third, char num);

int main() {
	std::string input;
	for (;std::getline(std::cin, input);) {
		std::vector<std::string> first;
		std::vector<std::string> second;
		std::vector<std::string> third;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] >= '0' && input[i] <= '9') {
				format(first, second, third, input[i]);
			}
		}

		for (int i = 0; i < first.size(); i++) std::cout << first[i];
		std::cout << '\n';
		for (int i = 0; i < second.size(); i++) std::cout << second[i];
		std::cout << '\n';
		for (int i = 0; i < third.size(); i++) std::cout << third[i];
		std::cout << '\n';
	}
	return 0;
}
/*
*_**_**_*
|_|*_||_*
|_|*_|*_|
*/
inline void format(std::vector<std::string>& first, std::vector<std::string>& sec,
	std::vector<std::string>& third, char num) {
	switch (num)
	{
		case '0': first.push_back(" _ "); sec.push_back("| |"); third.push_back("|_|"); break;
		case '1': first.push_back("   "); sec.push_back("  |"); third.push_back("  |"); break;
		case '2': first.push_back(" _ "); sec.push_back(" _|"); third.push_back("|_ "); break;
		case '3': first.push_back(" _ "); sec.push_back(" _|"); third.push_back(" _|"); break;
		case '4': first.push_back("   "); sec.push_back("|_|"); third.push_back("  |"); break;
		case '5': first.push_back(" _ "); sec.push_back("|_ "); third.push_back(" _|"); break;
		case '6': first.push_back(" _ "); sec.push_back("|_ "); third.push_back("|_|"); break;
		case '7': first.push_back(" _ "); sec.push_back("  |"); third.push_back("  |"); break;
		case '8': first.push_back(" _ "); sec.push_back("|_|"); third.push_back("|_|"); break;
		case '9': first.push_back(" _ "); sec.push_back("|_|"); third.push_back(" _|"); break;
	}
}