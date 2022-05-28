#include "Month.h"



Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	if (first == 'J' && second == 'a' && third == 'n') month = 1;
	else if (first == 'F' && second == 'e' && third == 'b') month = 2;
	else if (first == 'M' && second == 'a' && third == 'r') month = 3;
	else if (first == 'A' && second == 'p' && third == 'r') month = 4;
	else if (first == 'M' && second == 'a' && third == 'y') month = 5;
	else if (first == 'J' && second == 'u' && third == 'n') month = 6;
	else if (first == 'J' && second == 'u' && third == 'l') month = 7;
	else if (first == 'A' && second == 'u' && third == 'g') month = 8;
	else if (first == 'S' && second == 'e' && third == 'p') month = 9;
	else if (first == 'O' && second == 'c' && third == 't') month = 10;
	else if (first == 'N' && second == 'o' && third == 'v') month = 11;
	else if (first == 'D' && second == 'e' && third == 'c') month = 12;
	else month = 1;
}

Month::Month(int monthInt)
{
	if (monthInt < 1 || monthInt > 12) monthInt = 1;

	month = monthInt;
}

Month::~Month()
{
}

void Month::inputInt()
{
	int num;
	cin >> num;

	if (num < 1 || num > 12) num = 1;

	month = num;
}

void Month::inputStr()
{
	char first, sec, third;
	cin >> first >> sec >> third;
	if (first == 'J' && sec == 'a' && third == 'n') month = 1;
	else if (first == 'F' && sec == 'e' && third == 'b') month = 2;
	else if (first == 'M' && sec == 'a' && third == 'r') month = 3;
	else if (first == 'A' && sec == 'p' && third == 'r') month = 4;
	else if (first == 'M' && sec == 'a' && third == 'y') month = 5;
	else if (first == 'J' && sec == 'u' && third == 'n') month = 6;
	else if (first == 'J' && sec == 'u' && third == 'l') month = 7;
	else if (first == 'A' && sec == 'u' && third == 'g') month = 8;
	else if (first == 'S' && sec == 'e' && third == 'p') month = 9;
	else if (first == 'O' && sec == 'c' && third == 't') month = 10;
	else if (first == 'N' && sec == 'o' && third == 'v') month = 11;
	else if (first == 'D' && sec == 'e' && third == 'c') month = 12;
	else month = 1;
}

void Month::outputInt()
{
	cout << month;
}

void Month::outputStr()
{
	switch (month)
	{
	case 1: cout << "Jan" ; break;
	case 2: cout << "Feb" ; break;
	case 3: cout << "Mar" ; break;
	case 4: cout << "Apr" ; break;
	case 5: cout << "May" ; break;
	case 6: cout << "Jun" ; break;
	case 7: cout << "Jul" ; break;
	case 8: cout << "Aug" ; break;
	case 9: cout << "Sep" ; break;
	case 10: cout << "Oct"; break;
	case 11: cout << "Nov"; break;
	case 12: cout << "Dec"; break;
	default:
		break;
	}
}

Month Month::nextMonth()
{
	return Month(month + 1);
}
