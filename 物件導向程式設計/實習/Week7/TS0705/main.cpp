#include <iostream>
#include <string>

void command(std::string& Num1, std::string& Num2);
void sum(std::string& Num1, std::string& Num2);
void add(std::string& Num1, std::string& Num2, std::string& carried);
int index(char c);

int main() {
	int round;
	std::cin >> round;
	std::cout << "COWCULATIONS OUTPUT\n";
	for (int i = 0; i < round; i++) {
		std::string Num1 = "";
		std::string Num2 = "";
		std::cin >> Num1 >> Num2;

		command(Num1, Num2);

		std::string ans;
		std::cin >> ans;
		if (Num2 == ans) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	std::cout << "END OF OUTPUT\n";
	return 0;
}
void command(std::string& Num1, std::string& Num2) {
	char cmd;
	for (int j = 0; j < 3; j++) {
		std::cin >> cmd;

		switch (cmd)
		{
		case 'A': sum(Num1, Num2); break;
		case 'R': Num2.insert(Num2.begin(), 'V'); Num2.pop_back(); break;  //LRAªø«×¤£²Å
		case 'L': Num2.push_back('V'); break;
		case 'N': break;
		}
	}
	for (; Num2.length() != 8;) {
		Num2.insert(Num2.begin(), 'V');
	}
}
void sum(std::string& Num1, std::string& Num2) {
	char table[5][5] = { {'A','V','U','C','D'},
						 {'V','V','U','C','D'},
						 {'U','U','C','D','X'},
						 {'C','C','D','X','Y'},
						 {'D','D','X','Y','Z'} };
	//						   X=VU   Y=UU   Z=CU
	std::string carried = "";
	for (int i = 0; i <= Num2.length(); i++) carried.push_back('N');
	
	int i = Num2.length() - 1;
	for (int j = Num1.length() - 1; i >= 0 && j >= 0; i--, j--) {
		int row = index(Num1[j]), col = index(Num2[i]);
		if (table[col][row] == 'X') {  
			Num2[i] = 'V';
			carried[i] = 'U';
		}
		else if (table[col][row] == 'Y') {
			Num2[i] = 'U';
			carried[i] = 'U';
		}
		else if (table[col][row] == 'Z') {
			Num2[i] = 'C';
			carried[i] = 'U';
		}
		else {
			Num2[i] = table[col][row];
			carried[i] = 'N';
		}

		if (carried[i+1] != 'N') {
			row = index(carried[i+1]);
			col = index(Num2[i]);
			
			if (table[col][row] == 'X') {
				Num2[i] = 'V';
				carried[i] = 'U';
			}
			else if (table[col][row] == 'Y') {
				Num2[i] = 'U';
				carried[i] = 'U';
			}
			else if (table[col][row] == 'Z') {
				Num2[i] = 'C';
				carried[i] = 'U';
			}
			else {
				Num2[i] = table[col][row];
			}
		}
	}
	i++;
	if (carried[0] != 'N') Num2.insert(Num2.begin()+i, carried[0]);
	return;
}
void add(std::string& Num1, std::string& Num2, std::string& carried){
}
int index(char c) {
	switch (c)
	{
		case 'V': return 1;
		case 'U': return 2;
		case 'C': return 3;
		case 'D': return 4;
	}
}