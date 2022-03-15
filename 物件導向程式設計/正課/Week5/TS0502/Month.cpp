#include "Month.h"
#include <iostream>


Month::Month()
{
	this->month = 1;
}

Month::Month(char first, char second, char third)
{
	if (first = 'F' && second == 'e' && third == 'b') this->month = 2;
	else if (first = 'M' && second == 'a' && third == 'r') this->month = 3;
	else if (first = 'A' && second == 'p' && third == 'r') this->month = 4;
	else if (first = 'M' && second == 'a' && third == 'y') this->month = 5;
	else if (first = 'J' && second == 'u' && third == 'n') this->month = 6;
	else if (first = 'J' && second == 'u' && third == 'l') this->month = 7;
	else if (first = 'A' && second == 'u' && third == 'g') this->month = 8;
	else if (first = 'S' && second == 'e' && third == 'p') this->month = 9;
	else if (first = 'O' && second == 'c' && third == 't') this->month = 10;
	else if (first = 'N' && second == 'o' && third == 'v') this->month = 11;
	else if (first = 'D' && second == 'e' && third == 'c') this->month = 12;
	else this->month = 1;
}

Month::Month(int monthInt)
{
	if (monthInt >= 2 && monthInt <= 12) this->month = monthInt;
	else this->month = 1;
}


Month::~Month()
{
}

void Month::inputInt()
{
	int monthInt;
	std::cin >> monthInt;
	if (monthInt >= 2 && monthInt <= 12) this->month = monthInt;
	else this->month = 1;
}

void Month::inputStr()
{
	char first ,second, third;
	std::cin >> first >> second >> third;

	if (first = 'F' && second == 'e' && third == 'b') this->month = 2;
	else if (first = 'M' && second == 'a' && third == 'r') this->month = 3;
	else if (first = 'A' && second == 'p' && third == 'r') this->month = 4;
	else if (first = 'M' && second == 'a' && third == 'y') this->month = 5;
	else if (first = 'J' && second == 'u' && third == 'n') this->month = 6;
	else if (first = 'J' && second == 'u' && third == 'l') this->month = 7;
	else if (first = 'A' && second == 'u' && third == 'g') this->month = 8;
	else if (first = 'S' && second == 'e' && third == 'p') this->month = 9;
	else if (first = 'O' && second == 'c' && third == 't') this->month = 10;
	else if (first = 'N' && second == 'o' && third == 'v') this->month = 11;
	else if (first = 'D' && second == 'e' && third == 'c') this->month = 12;
	else this->month = 1;
}

void Month::outputInt()
{
	std::cout << this->month;
}

void Month::outputStr()
{
	switch (this->month) {
		case 2: std::cout << "Feb"; break;
		case 3: std::cout << "Mar"; break;
		case 4: std::cout << "Apr"; break;
		case 5: std::cout << "May"; break;
		case 6: std::cout << "Jun"; break;
		case 7: std::cout << "Jul"; break;
		case 8: std::cout << "Aug"; break;
		case 9: std::cout << "Sep"; break;
		case 10: std::cout << "Oct"; break;
		case 11: std::cout << "Nov"; break;
		case 12: std::cout << "Dec"; break;
		default: std::cout << "Jan";
	}
}

Month Month::nextMonth()
{ 
	return this->month+1;
}
