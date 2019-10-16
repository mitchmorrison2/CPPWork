//Program 2

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SearchFunctions.h"

using namespace std;

void readInInfo();
int menuOptions();
void searchFunctions(int choice, vector<string> &name, vector<string> phoneNumbers);

int main() {
	
	readInInfo();
	
	return 0;
}

void readInInfo() {
	vector<string> names;
	vector<string> phoneNumbers;
	
	char fileName[] = "phoneBook.txt";
	ifstream myFile(fileName);
	if (!myFile.is_open()) {
		cerr << "Error opening file";
	}
	while (!myFile.eof()) {
		string name = "";
		string number = "";
		string readIn = "";
		string subReadIn = "";
		
		int i = 0;
		
		getline(myFile, readIn);
		subReadIn = readIn;//essentially creates another readIn to be substringed later
		while(readIn[i] != ','){
			name.push_back(readIn[i]);
			i++;
	}
	if(subReadIn[i] == ',') { //use substring to copy and essentially separate the types of data
		number = subReadIn.substr(i+1); //once the previous while gets i to comma in the string, it puts the substring of everything after the comma into the second readIn variable readIn2
	}  
	if (!myFile.fail()) {
		names.push_back(name);
		phoneNumbers.push_back(number);
	}// end if  
	}//end of while for reading file into vector
	
	myFile.close();//marks the end of reading in the txt file
	
	int choice;
	choice = menuOptions();
	searchFunctions(choice, names, phoneNumbers);
	
} //end method

int menuOptions() {
	
	cout << "Welcome to the SMU Phonebook" << endl << "=====================" << endl;
	cout << "(1) - Find by name (resursive)" << endl;
	cout << "(2) - Find by name (iterative)" << endl;
	cout << "(3) - Find by phone (recursive)" << endl;
	cout << "(4) - Find by phone (iterative)" << endl;
	cout << "(5) - Quit" << endl << endl;
	cout << "Please select an option:  ";
	int choice;
	cin >> choice;
	cin.ignore();
	return choice;
}

void searchFunctions(int choice, vector<string> &names, vector<string> phoneNumbers) {
	
	int index = 0;
	string search = "";
	
	
	if (choice == 5) {
		cout << "Aight, goodbye";
	}
	else if (choice == 1) { //search by name recursion
		cout << "Enter a name: ";
		getline(cin,search);
		index = searchRecursive(names, search);
		if (index == -1) {
			cout << endl << "No match found" << endl;
		}
		else {
			cout << index + 1 << ": " << names[index] << " " << phoneNumbers[index] << endl;
		}
	}
	else if (choice == 2) { //search by name itertive
		cout << "Enter a name: ";
		getline(cin,search);
		index = searchIterative(names, search);
		if (index != -1) {
			cout << index + 1 << ": " << names[index] << " " << phoneNumbers[index] << endl;
		}
		else {
			cout <<"No match found";
		}
	}
	else if (choice == 3) { //search by PN recursive
		cout << "Enter a phone number: ";
		getline(cin,search);
		index = searchRecursive(phoneNumbers, search);
		if (index == -1) {
			cout << endl << "No match found"; 
		}
		else {
			cout << index + 1 << ": " << names[index] << " " << phoneNumbers[index] << endl;
		}
	}
	else if (choice == 4) { //search by PN iterative
		cout << "Enter a phone number: ";
		getline(cin,search);
		index = searchIterative(phoneNumbers, search);
		if (index == -1) {
			cout << endl << "No match found"; 
		}
		else {
			cout << index + 1 << ": " << names[index] << " " << phoneNumbers[index] << endl;
		}
	}
}