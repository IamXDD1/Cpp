#pragma once
#include "Document.h"

class Email : public Document {
public:
	string sender;
	string recipient;
	string title;
	
	Email() : Document() {};
	Email(string txt, string send, string recipe, string T) : Document(txt), sender(send), recipient(recipe), title(T) {};

	virtual string getText() const { return text; }
	string getSender() { return sender; }
	string getRecipient() { return recipient; }
	string getTitle() { return title; }

	Email& operator = (Email s) {
		Document::operator=(s);
		sender = s.sender;
		recipient = s.recipient;
		title = s.title;
		text = s.getText();

		return *this;
	}
};