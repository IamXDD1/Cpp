#include <iostream>
#include <string>
#include <vector>
#include <queue>

int main() {
	int m, n;
	for (; std::cin >> m >> n;) {
		std::vector<std::pair<char,char>> translation;
		if (m == 0 && n == 0) break;

		for (int i = 0; i < m; i++) {
			char key, value;
			std::cin >> key >> value;
			translation.push_back({ key,value });
		}
		
		for (int i = 0; i < n; i++) {
			bool success = false;
			std::string word, match;
			std::cin >> word >> match;

			if (word.length() == match.length()) {
				for (int x = 0; x < word.length(); x++) {
					char key = word[x], val = match[x];
					if (key != val) {
						bool find = false;
						bool pushed[26] = {};
						std::queue<char> pending;
						pending.push(key);
						pushed[key - 'a'] = true;
						for (; !pending.empty() && !find; ) {
							for (auto it : translation) {
								if (pending.front() == val) {
									find = true;
									break;
								}
							  	if (it.first == pending.front() && pushed[it.second - 'a'] == false) {
									pending.push(it.second);
									pushed[it.second-'a'] = true;
									if (it.second == val) {
										find = true;
									}
								}
							}
							pending.pop();
						}
						if (!find) break;
					}
					if (x == word.length() - 1) success = true;
				}
			}

			if (success) std::cout << "yes\n";
			else std::cout << "no\n";
		}
	}
	return 0;
}