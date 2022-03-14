#include<iostream>
#include <string>

bool validBoard(char board[][9]) {
	for (int i = 0, y = 0, x = 0; i < 9; i++, x+=3) {
		bool row[9] = {};
		bool col[9] = {};
		bool square[9] = {};

		for (int j = 0; j < 9; j++) {
			if (row[board[i][j] - '1']) return false;
			row[board[i][j] - '1'] = true;
		}
		for (int j = 0; j < 9; j++) {
			if (col[board[j][i] - '1']) return false;
			col[board[j][i] - '1'] = true;
		}
		for (int  j=0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (square[board[y + j][x + k] - '1']) return false;
				square[board[y + j][x + k] - '1'] = true;
			}
		}
		if ((i + 1) % 3 == 0) {
			x = -3;
			y += 3;
		}
	}
	return true;
}

int main() {
	
	for (;;)
	{
		bool cin_eof = false;
		bool valid_num = true;
		char board[9][9] = {};

		char str[50];
		for (int i = 0; i < 9; )
		{
			std::cin.getline(str, 100);

			if (std::cin.eof()) {
				cin_eof = true;
				break;
			}

			if (str[0] == '\0') continue;

			int num_count = 0;
			bool comma = true;
			for (int j = 0; j < strlen(str); j++) {
				if (str[j] == ' ') continue;
				else if ((str[j] >= '1' && str[j] <= '9') && (comma)) {
					num_count++;
					comma = false;
				}
				else if (!((str[j] >= '1' && str[j] <= '9') || str[j] == ',')) {
					valid_num = false;
				}
				else if (comma == false && (str[j] >= '0' && str[j] <= '9')) {
					valid_num = false;
				}
				if (str[j] == ',') {
					if (comma || j == strlen(str)-1) valid_num = false;
					else comma = true;
				}
			}

			for (int j = 0, count = 0; j < strlen(str); j++) {
				if (str[j] >= '0' && str[j] <= '9') {
					board[i][count] = str[j];
					count++;
				}
			}
			i++;
			
		}

		if (cin_eof) break;

		if(valid_num && validBoard(board)) std::cout << "True" << '\n';
		else std::cout << "False" << '\n';
	}
	return 0;
}
