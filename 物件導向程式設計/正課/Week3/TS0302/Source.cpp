#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

std::fstream grade, output;

int main() {
	grade.open("grade.txt", std::ios::in);
	output.open("grades.Output", std::ios::out);

	int num;
	int count[6] = {};

	for (; grade >> num;) {
		count[num]++;
	}

	for (int i = 0; i < 6; i++) {
		output << count[i] << " grade(s) of " << i << '\n';
	}

	grade.close();
	output.close();

	return 0;
}