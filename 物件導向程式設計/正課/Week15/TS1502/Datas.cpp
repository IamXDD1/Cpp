#include "Datas.h"

void Datas::Insert(string title, string author, int edition)
{
	bool find = false;
	for (auto& it : books) {
		if (title == it.first.first && author == it.first.second && edition == it.second) {
			cout << "Datum already exist.\n";
			find = true;
			break;
		}
	}
	if (!find) {
		books.push_back({ {title, author}, edition });
		cout << "Insert " << author << "'s " << title << ", Edition: " << edition << ".\n";
	}
}

void Datas::Delete_Edition(string title, string author, int edition)
{
	bool find = false;
	int index = 0;
	for (auto& it : books) {
		if (title == it.first.first && author == it.first.second && edition == it.second) {
			cout << "Delete " << author << "'s " << title << ", Edition: " << edition << ".\n";
			books.erase(books.begin() + index);
			find = true;
			break;
		}
		index++;
	}
	if (!find) {
		cout << "Datum doesn't exist.\n";
	}
}

void Datas::Delete_Book(string title, string author)
{
	bool find = false;
	vector<pair<pair<string, string>, int>>::iterator it;
	for (it = books.begin(); it != books.end(); it++) {
		if (title == it->first.first && author == it->first.second) {
			cout << "Delete " << author << "'s " << title << ".\n";
			it--;
			books.erase(it+1);
			find = true;
		}
	}
	if (!find) {
		cout << "Book doesn't exist.\n";
	}
}

void Datas::Find_Book(string title, string author)
{
	vector<int> find;
	vector<pair<pair<string, string>, int>>::iterator it;
	for (it = books.begin(); it != books.end(); it++) {
		if (title == it->first.first && author == it->first.second) {
			find.push_back(it->second);
		}
	}
	if (find.size() == 0) {
		cout << "Book doesn't exist.\n";
	}
	else {
		cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: ";
		sort(find.begin(), find.end());
		for (int i = 0; i < find.size(); i++) {
			cout << find[i];
			if (i != find.size() - 1) cout << ", ";
		}
		cout << '\n';
	}
}

void Datas::Find_Author(string author)
{
	map<string, int> find;
	vector<pair<pair<string, string>, int>>::iterator it;
	for (it = books.begin(); it != books.end(); it++) {
		if (author == it->first.second) {
			find[it->first.first] = it->second;
		}
	}
	if (find.empty()) {
		cout << "No book found.\n";
	}
	else {
		cout << author << "'s Books: ";
		for (map<string, int>::iterator it = find.begin(); it != find.end();) {
			cout << it->first;
			if (++it != find.end()) cout << ", ";
		}
		cout << '\n';
	}
}

void Datas::Sort_by_Title()
{
	map<pair<string, string>, vector<int>, cmp_title> datas;

	for (auto& it : books) {
		datas[{it.first.first, it.first.second}].push_back(it.second);
	}

	for (auto& it : datas) {
		if (it.second.size() > 0) {
			cout << "Title: " << it.first.first << "\tAuthor: " << it.first.second << "\tEdition: ";
			for (int i = 0; i < it.second.size(); i++) {
				cout << it.second[i];
				if (i != it.second.size() - 1) cout << ", ";
			}
			cout << '\n';
		}
	}
}

void Datas::Sort_by_Author()
{
	map<pair<string, string>, vector<int>, cmp_author> datas;

	for (auto& it : books) {
		datas[{it.first.first, it.first.second}].push_back(it.second);
	}

	for (auto& it : datas) {
		if (it.second.size() > 0) {
			cout << "Title: " << it.first.first << "\tAuthor: " << it.first.second << "\tEdition: ";
			for (int i = 0; i < it.second.size(); i++) {
				cout << it.second[i];
				if (i != it.second.size() - 1) cout << ", ";
			}
			cout << '\n';
		}
	}
}