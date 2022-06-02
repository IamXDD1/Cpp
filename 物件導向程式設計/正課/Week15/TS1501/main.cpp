#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main() {
	fstream file("name.txt");

	if (file) {
		string name;
		set<string> costumer;
		for (; getline(file, name);) {
			costumer.emplace(name);
		}
		for (auto& it : costumer) {
			cout << it << '\n';
		}
		file.close();
	}
	return 0;
}