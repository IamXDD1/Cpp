#include "PrimeNumber.h"
#include <iostream>

using namespace std;

int main()
{	
	PrimeNumber p1(101), p2(97);	
	PrimeNumber a = ++p1;
	PrimeNumber b = p2++;
	cout << a.get() << endl;
	cout << p1.get() << endl;
	cout << b.get() << endl;
	cout << p2.get() << endl;
	return 0;
}
