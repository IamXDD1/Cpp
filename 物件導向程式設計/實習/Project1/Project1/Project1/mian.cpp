#include <iostream>
#include "Calculator.h"

int main() {
	Calculator Cal;

	while (true)
	{
		try {
			Cal.test();
			//Cal.RUN()
		}
		catch (char const* error) {
			cout << error << '\n';
		}
	}
	std::cout << "Stop running!";

	return 0;
}