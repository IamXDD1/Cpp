#include "Form.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::fstream inFile, outFile;

int alpha[26] = {};
std::string word = "";
std::string file_name = "";

std::vector<std::string> ans;

void Form::SetInputWord(std::string inputWord) { // set input
	word = inputWord;
	return;
}
void Form::ProcessInputWord() { // process input
	for (int i = 0; i < 26; i++) alpha[i] = 0;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] >= 'a' && word[i] <= 'z') {
			alpha[word[i] - 'a']++;
		}
		else if (word[i] >= 'A' && word[i] <= 'Z') {
			alpha[word[i] - 'A']++;
		}
	}
	return;
}
void Form::SetFileName(std::string fileName) { // set file name
	file_name = fileName;
	return;
}
void Form::Load_CompareWord() { // read-in data and compare
	inFile.open(file_name);
	ans.clear();
	std::string temp = "";
	
	for (; inFile >> temp;) {
		bool valid = true;
		int alpha_temp[26] = {};
		for (int i = 0; i < temp.length(); i++) {
			int index = tolower(temp[i]) - 'a';
			if (++alpha_temp[index] > alpha[index]) {
				valid = false;
				break;
			}
		}
		if(valid) ans.push_back(temp);
	}

	inFile.close();
	return;
}
void Form::PrintFoundWords() { // print answers
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << '\n';
	}
}