#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

std::fstream file;

void getHighScores(std::vector<std::string>& name, std::vector<int>& score) {
	
	std::string name_temp;
	int score_temp;

	for (; file >> name_temp >> score_temp;) {
		name.push_back(name_temp);
		score.push_back(score_temp);
	}

	for (int i = 0; i < name.size(); i++) {
		for (int j = i; j < score.size(); j++) {
			if (score[j] > score[i]) {
				std::swap(name[i], name[j]);
				std::swap(score[i], score[j]);
			}
		}
	}
}

int main() {
	file.open("scores.txt", std::ios::in);
	
	std::vector<std::string> names;
	std::vector<int> scores;

	getHighScores(names, scores);

	std::cout << names[0] << "\n" << scores[0] << "\n"
		<< names[1] << "\n" << scores[1] << "\n"
		<< names[2] << "\n" << scores[2] << "\n";

	file.close();
	return 0;
}