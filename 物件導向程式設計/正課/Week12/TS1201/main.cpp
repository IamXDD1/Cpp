#include <iostream>
#include <sstream>
#include <string>

#define STRING 0
#define CHAR 1
#define SHORT 2
#define INT 3

using namespace std;

void Set(char* Memory, int memorySize, stringstream& ss, int type, int position) {
	unsigned int value = 0;
	string sentence;
	int writecount = 0;
	bool overflow = false;
	switch (type)
	{
	case STRING:
		getline(ss, sentence);
		for (int i = 0; i < sentence.length(); i++) {
			if (position + i < memorySize) Memory[position + i] = sentence[i];
			else throw "Violation Access.";
			//cout << Memory[position + i] << '\n';
		}
		Memory[position + sentence.length()] = '\0';
		break;
	case CHAR: case INT: case SHORT:
		writecount = memorySize - position;
		if (type == CHAR)
			if (writecount >= 1)
				writecount = 1;
			else
				overflow = true;
		else if (type == INT)
			if (writecount >= 4)
				writecount = 4;
			else
				overflow = true;
		else if (type == SHORT)
			if (writecount >= 2)
				writecount = 2;
			else
				overflow = true;

		ss >> value;
		for (int i = 0; i < writecount; i++) {
			Memory[position + i] = value & 0xff;
			value >>= 8;
			// << Memory[position + i] << '\n';
		}

		if (overflow)
			throw "Violation Access.";
	default:
		break;
	}
}
void Get(char* Memory, int memorySize, int type, int position) {
	unsigned int value = 0;
	int readCount = 0;

	if (position >= memorySize) throw "Violation Access.";
	else {
		switch (type)
		{
		case STRING:
			cout << (string)(Memory + position) << '\n';
			break;
		case CHAR: case INT: case SHORT:
			readCount = memorySize - position;

			if (type == CHAR)
				if (readCount >= 1)
					readCount = 1;
				else
					readCount = 0;
			else if (type == INT)
				if (readCount >= 4)
					readCount = 4;
				else
					readCount = 0;
			else if (type == SHORT)
				if (readCount >= 2)
					readCount = 2;
				else
					readCount = 0;

			if (position + readCount > memorySize || readCount == 0) throw "Violation Access.";

			for (int i = 0; i < readCount; i++) {
				value |= (unsigned char)(Memory[position + i]) << (i << 3);
			}
			std::cout << value << '\n';
		default:
			break;
		}
	}
}
void MemoryPointer(char* memory, int memorySize) {
	string cmd;
	int pos;
	getline(cin, cmd);
	stringstream ss(cmd);
	ss >> cmd >> pos;

	if (cmd == "Set") {
		ss >> cmd;
		ss.get();
		if (cmd == "String") Set(memory, memorySize, ss, STRING, pos);
		else if (cmd == "char") Set(memory, memorySize, ss, CHAR, pos);
		else if (cmd == "int") Set(memory, memorySize, ss, INT, pos);
		else if (cmd == "short") Set(memory, memorySize, ss, SHORT, pos);
	}
	else if (cmd == "Get") {
		ss >> cmd;
		if (cmd == "String") Get(memory, memorySize, STRING, pos);
		else if (cmd == "char") Get(memory, memorySize, CHAR, pos);
		else if (cmd == "int") Get(memory, memorySize, INT, pos);
		else if (cmd == "short") Get(memory, memorySize, SHORT, pos);
	}
}

int main() {
	int memorySize, cmdnum;
	std::cin >> memorySize >> cmdnum;
	char* memory = new char[memorySize + 1]{};
	cin.get();
	for (int i = 0; i < cmdnum; i++) {
		try {
			MemoryPointer(memory, memorySize);
		}
		catch (char const* e) {
			std::cout << e << '\n';
		}
	}
	delete[] memory;
	return 0;
}