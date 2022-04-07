//FormWord-inputmain1.cpp
#include"Form.h"

int main()
{
	Form form1;
	form1.SetInputWord("SWIMING 123 M"); // set input
	form1.ProcessInputWord(); // process input
	form1.SetFileName("words.txt"); // set file name
	form1.Load_CompareWord(); // read-in data and compare
	form1.PrintFoundWords(); // print answers

	form1.SetInputWord("AABBCC"); // set input
	form1.ProcessInputWord();
	form1.Load_CompareWord(); // read-in data and compare
	form1.PrintFoundWords();
	return 0;
}