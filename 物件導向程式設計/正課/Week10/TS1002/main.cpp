#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void DFS(char grid[4][4], map<pair<int, int>, bool> check, string& word, string tmp, int x, int y, bool& find, int index);

int main() {
	fstream file;
	
	for (;;) {
		file.open("words.txt");
		if (file) {
			char grid[4][4];
			string input;
			for (int i = 0; i < 4; i++) {
				cin >> input;
				for (int j = 0; j < 4; j++) {
					grid[i][j] = input[j];
				}
			}
			if (cin.eof()) break;

			string str;
			for (; file >> str;) {
				bool fAlpha = false;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (grid[i][j] == str[0]) {
							
							bool find = false;
							map<pair<int, int>, bool> check;
							string temp;

							DFS(grid, check, str, temp, j, i, find, 0);
							if (find) {
								cout << str << '\n';
								fAlpha = true;
								break;
							}
						}
					}
					if (fAlpha) break;
				}
			}

			cout << '\n';
			file.close();
		}
	}
		
	return 0;
}
void DFS(char grid[4][4], map<pair<int, int>, bool> check, string& word, string tmp, int x, int y, bool& find, int index){
	//cout << grid[y][x] << " -> ";
	if (find) return;
	if (x < 0 || y < 0 || x >= 4 || y >= 4) return;
	if (check[{y, x}]) return;
	if (grid[y][x] != word[index]) return;

	check[{y, x}] = true;
	tmp += grid[y][x];
	
	if (tmp == word) {
		find = true;
		return;
	}

	DFS(grid, check, word, tmp, x-1, y-1, find, index+1);
	DFS(grid, check, word, tmp, x, y-1, find, index + 1);
	DFS(grid, check, word, tmp, x+1, y-1, find, index + 1);
	DFS(grid, check, word, tmp, x-1, y, find, index + 1);
	DFS(grid, check, word, tmp, x+1, y, find, index + 1);
	DFS(grid, check, word, tmp, x-1, y+1, find, index + 1);
	DFS(grid, check, word, tmp, x, y+1, find, index + 1);
	DFS(grid, check, word, tmp, x+1, y+1, find, index + 1);
	return;
}