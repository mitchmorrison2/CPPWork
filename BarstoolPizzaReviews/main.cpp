#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>


using namespace std;

void readInLocations();
void questionWhereHeIsAt();
int ranNumber();
void talkToHomeless();

vector<string> pizzaShops;
int index1 = 0;
int index2 = 0;

int main()
{
	
	readInLocations();
	questionWhereHeIsAt();
	talkToHomeless();
	
	return 0;
}


void readInLocations() {
	
	
	fstream fIn("PizzaShops.txt");
	string tempHolder;
	while (getline(fIn, tempHolder)) {
		pizzaShops.push_back(tempHolder);
	}
	fIn.close();
	
	
}

void questionWhereHeIsAt() {
	
	int pizzaShopIndex = ranNumber();
	
	cout << "Alright here we are, we are at " << pizzaShops[pizzaShopIndex] << " we are on the corner of --" << endl; 
	cout << "Francis where the hell are we? Where the f*ck am I?" << endl;  
}

int ranNumber() {
	
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(1, 100);
	int shopNum = distr(eng);
//	cout << "Size shops num: " << sizeShops;
	
	return shopNum;
}

void talkToHomeless() {
	cout << "Old lady: Can I have a slice?" << endl << "Prez: Sure come here it's a pizza review rate it from 0 - 10." <<endl;
	cout << "OL: I'd say it's a 6." << endl;
	cout << "Prez: Alright she gives it a 6, thats a rookie score, lots of those here in Manhattan." << endl;
	cout << "Alright. One bite, everybody knows the rules." <<endl;
	cout << "*5 bites later* This is a 6.4 and i'll tell you why. Too much flop, a bit of grease, nothing special."  << endl;
}
