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
			draw_line(map, x1, y1, x2, y2);
			print_map(map);
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
		std::cout << "Out of range\n";
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
	
	


	return;
}
void draw_triangle(char** map) {
	int w, x, y;
	std::string dir = "";
	std::cin >> w >> x >> y >> dir;

	if (dir == "LU") {
		int temp = std::sqrt(w * w / 2);
		if(x - temp < 0|| y - temp < 0) std::cout << "Out of range\n";
		else {
			draw_line(map, x, y, x - temp, y);
			draw_line(map, x, y, x, y - temp);
			draw_line(map, x - temp, y, x, y - temp);
			print_map(map);
		}
	}
	else if (dir == "LD") {
		int temp = std::sqrt(w * w / 2);
		if (x - temp < 0 || y + temp > n) std::cout << "Out of range\n";
		else {
			draw_line(map, x, y, x - temp, y);
			draw_line(map, x, y, x, y + temp);
			draw_line(map, x - temp, y, x, y + temp);
			print_map(map);
		}
	}
	else if (dir == "RU") {
		int temp = std::sqrt(w * w / 2);
		if (x + temp < 0 || y - temp < 0) std::cout << "Out of range\n";
		else {
			draw_line(map, x, y, x + temp, y);
			draw_line(map, x, y, x, y - temp);
			draw_line(map, x + temp, y, x, y - temp);
			print_map(map);
		}
	}
	else if (dir == "RD") {
		int temp = std::sqrt(w * w / 2);
		if (x + temp < 0 || y + temp < 0) std::cout << "Out of range\n";
		else {
			draw_line(map, x, y, x + temp, y);
			draw_line(map, x, y, x, y + temp);
			draw_line(map, x + temp, y, x, y + temp);
			print_map(map);
		}
	}
	return;
}