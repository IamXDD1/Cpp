#include <iostream>

int main() {
	unsigned long long int sec = 0;
	unsigned long long int min = 0;
	unsigned long long int hour = 0;

	for (; std::cin >> sec;)
	{
		min = sec / 60;
		sec %= 60;

		hour = min / 60;
		min %= 60;

		std::cout << hour << " hours " << min << " minutes and " << sec << " seconds\n";
	}
	



	return 0;
}