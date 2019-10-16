#include "prac.h"
#include <iostream>
#include <string>


using namespace std;

prac::prac()
{
}

prac::~prac()
{
}

void prac::practice() {
	int takeIn = 2345678;
//	cout << "Enter an int for its palindrome: " << endl;
//	cin >> takeIn;
	string stringInts = "";
	findPalindromeOfInt(takeIn, stringInts);
	cout << stringInts << endl;
}

void prac::findPalindromeOfInt(int x, string& addOn) {

	if (x<10) {
		addOn += x;
		cout << x << endl;
	}
	else if (x%10 > 9) {
		findPalindromeOfInt(x/10, addOn);
	}
}

int prac::clearBit(int num, int i) {
	int mask = ~(1 << i);
	return num & mask;
}

void prac::printNew() {
	int begin = 16;
	cout << begin << endl;
	int end = clearBit(begin, 4);
	cout << end << endl;
}
