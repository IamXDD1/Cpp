#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	long double X;
	int M;
	int N;
	char C;
	for (; std::cin >> X >> M >> N;)
	{
		C = getchar();
		C = getchar();
		X = static_cast<long double>(static_cast<long long int>(X * std::pow(10, N))) / std::pow(10, N);

		if (X < 0) M--;
		if (N > 0) M--;
		M -= N;

		for (int temp = static_cast<int>(X); temp != 0; temp /= 10, M--);

		for (; M > 0; M--) std::cout << C;
		std::cout << std::fixed << std::setprecision(N) << X <<"\n";
	}


	return 0;
}