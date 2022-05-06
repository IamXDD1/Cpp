#pragma once
#include <iostream>
#include <string>

using std::string;

class Document {
public:
	string text;

	Document();
	Document(string s) : text(s) {};

	virtual string getText() const { return text; }

	void setText(string set) {
		text = set;
	}
	Document& operator = (Document s) {
		text = s.getText();
		return *this;
	}
};