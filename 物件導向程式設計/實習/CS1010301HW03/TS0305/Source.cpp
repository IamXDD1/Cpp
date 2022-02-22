#include <iostream>
#include <string>
#include <cmath>

int m, n;

void print_map(char** map) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << map[i][j];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
void draw_square(char** map);
void draw_line(char** map, int x1, int y1, int x2, int y2);
void draw_triangle(char** map);

int main()
{
	std::cin >> m >> n;

	char** map = new char* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new char[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = '*';
		}
	}

	std::string command = "";

	for (; std::cin >> command;) {
		if (command == "EXIT") break;
		else if (command == "S") {
			draw_square(map);
		}
		else if (command == "L") {
			int x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;

			if (x1 < 0 || x2 >= m || y1 < 0 || y2 >= n) std::cout << "Out of range.\n\n";
			else {
				draw_line(map, x1, y1, x2, y2);
				print_map(map);
			}
		}
		else if (command == "T") {
			draw_triangle(map);
		}
	}

	return 0;
}
void draw_square(char** map) {
	int w, x, y;
	std::cin >> w >> x >> y;

	if (x + w > m || y + w > n) {
		std::cout << "Out of range.\n\n";
	}
	else {
		for (int i = 0; i < w; i++) {
			map[y][x + i] = 'X';
			map[y + w-1][x + i] = 'X';
			map[y + i][x] = 'X';
			map[y + i][x + w-1] = 'X';
		}
		print_map(map);
	}
	return;
}
void draw_line(char** map, int x1, int y1, int x2, int y2) {
	if (x2 > x1 && y2 > y1) {
		for (int i = x1, j = y1; i <= x2 && j <= y2; i++, j++) {
			map[j][i] = 'X';
		}
	}
	else if (x2 > x1 && y1 > y2) {
		for (int i = x1, j = y1; i <= x2 && j >= y2; i++, j--) {
			map[j][i] = 'X';
		}
	}
	else if (x1 > x2 && y2 > y1) {
		for (int i = x1, j = y1; i >= x2 && j <= y2; i--, j++) {
			map[j][i] = 'X';
		}
	}
	else if (x1 > x2 && y1 > y2) {
		for (int i = x1, j = y1; i >= x2 && j >= y2; i--, j--) {
			map[j][i] = 'X';
		}
	}
	else if (x1 > x2 && y1 == y2) {
		for (int i = x1, j = y1; i >= x2; i--) {
			map[j][i] = 'X';
		}
	}
	else if (x2 > x1 && y1 == y2) {
		for (int i = x1, j = y1; i <= x2; i++) {
			map[j][i] = 'X';
		}
	}
	else if (x1 == x2 && y1 > y2) {
		for (int i = x1, j = y1; j >= y2; j--) {
			map[j][i] = 'X';
		}
	}
	else if (x2 == x1 && y1 < y2) {
		for (int i = x1, j = y1; j <= y2; j++) {
			map[j][i] = 'X';
		}
	}
	else if (x1 == x2 && y1 == y2) map[y1][x1] = 'X';
	else map[0][0] = 'E';

	return;
}
void draw_triangle(char** map) {
	int w, x, y;
	std::string dir = "";
	std::cin >> w >> x >> y >> dir;

	w--;
	if (x < m && y < n && x >= 0 && y >= 0) {
		if (dir == "LU") {
			if(x - w < 0 || y - w < 0) std::cout << "Out of range.\n\n";
			else {
				draw_line(map, x, y, x - w, y);
				draw_line(map, x, y, x, y - w);
				draw_line(map, x - w, y, x, y - w);
				print_map(map);
			}
		}
		else if (dir == "LD") {
			if (x - w < 0 || y + w >= n) std::cout << "Out of range.\n\n";
			else {
				draw_line(map, x, y, x - w, y);
				draw_line(map, x, y, x, y + w);
				draw_line(map, x - w, y, x, y + w);
				print_map(map);
			}
		}
		else if (dir == "RU") {
			if (x + w >= m || y - w < 0) std::cout << "Out of range.\n\n";
			else {
				draw_line(map, x, y, x + w, y);
				draw_line(map, x, y, x, y - w);
				draw_line(map, x + w, y, x, y - w);
				print_map(map);
			}
		}
		else if (dir == "RD") {
			if (x + w >= m || y + w >= n) std::cout << "Out of range.\n\n";
			else {
				draw_line(map, x, y, x + w, y);
				draw_line(map, x, y, x, y + w);
				draw_line(map, x + w, y, x, y + w);
				print_map(map);
			}
		}
	}
	else std::cout << "Out of range.\n\n";
	return;
}