#include <iostream>
#include <iomanip>
#include <string>
int main() {
	std::string input = "";
	for (;std::cin>> input;) {
		std::cout << std::setw(10) << input << "\n";
	}

	return 0;
}