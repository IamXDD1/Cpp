#include "Datas.h"

void judgeTitle(string& title);
void judgeAuthor(string& author);
void judgeEdition(int& num);

int main() {
	Datas data;
	string str;
	for (; getline(cin, str);)
	{
		try {
			stringstream ss(str);
		
			string cmd;
			ss >> cmd;
			if (cmd == "Insert") {
				string title = "", author = "";
				int edition = -1;
				getline(ss, title, '"');
				getline(ss, title, '"');
				getline(ss, author, '"');
				getline(ss, author, '"');
				ss >> edition;
				judgeTitle(title);
				judgeAuthor(author);
				judgeEdition(edition);
				data.Insert(title, author, edition);
			}
			else if (cmd == "Delete") {
				ss >> cmd;
				if (cmd == "Edition") {
					string title = "", author = "";
					int edition = -1;
					getline(ss, title, '"');
					getline(ss, title, '"');
					getline(ss, author, '"');
					getline(ss, author, '"');
					ss >> edition;
					judgeTitle(title);
					judgeAuthor(author);
					judgeEdition(edition);
					data.Delete_Edition(title, author, edition);
				}
				else if (cmd == "Book") {
					string title = "", author = "";
					getline(ss, title, '"');
					getline(ss, title, '"');
					getline(ss, author, '"');
					getline(ss, author, '"');
					judgeTitle(title);
					judgeAuthor(author);
					data.Delete_Book(title, author);
				}
				else throw "Incomplete Command.";
			}
			else if (cmd == "Find") {
				ss >> cmd;
				if (cmd == "Book") {
					string title = "", author = "";
					getline(ss, title, '"');
					getline(ss, title, '"');
					getline(ss, author, '"');
					getline(ss, author, '"');
					judgeTitle(title);
					judgeAuthor(author);
					data.Find_Book(title, author);
				}
				else if (cmd == "Author") {
					string author = "";
					getline(ss, author, '"');
					getline(ss, author, '"');
					judgeAuthor(author);
					data.Find_Author(author);
				}
				else throw "Incomplete Command.";
			}
			else if (cmd == "Sort") {
				ss >> cmd;
				if (cmd == "by") {
					ss >> cmd;
					if (cmd == "Title") {
						data.Sort_by_Title();
					}
					else if (cmd == "Author") {
						data.Sort_by_Author();
					}
					else throw "Incomplete Command.";
				}
				else throw "Incomplete Command.";
			}
			else {
				throw "Unknown Command.";
			}
		}
		catch (const char* error) {
			cout << error << '\n';
		}
	}

	return 0;
}

void judgeTitle(string& title) {
	if (title.length() <= 0) {
		throw "Incomplete Command.";
	}
}
void judgeAuthor(string& author) {
	if (author.length() <= 0) {
		throw "Incomplete Command.";
	}
}
void judgeEdition(int& num) {
	if (num == -1) throw "Incomplete Command.";
}