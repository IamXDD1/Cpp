#pragma once
#include "Document.h"

class File : public Document {
public:
	string pathname;

	File() : Document() {};
	File(string txt, string path) : Document(txt), pathname(path) {};

	void setPathname(string path) {
		pathname = path;
		return;
	}
	string getPathname() { return pathname; }

	virtual string getText() const { return text; }

	File& operator = (File s) {
		Document::operator=(s);
		pathname = s.pathname;
		text = s.getText();

		return *this;
	}
};