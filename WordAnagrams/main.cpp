#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

short int counter = 0;
char wordList[50][20];

//3 functions to open, read, and alphabetize the words in file
void openFile();
void compareArrays();
void alphabetize();

int main()
{
	openFile();
	alphabetize();
	compareArrays();
	return 0;
}


void openFile() {
	cout << "What is the file name? ";
	char fileName[20] = {}; //file.txt
	cin.getline(fileName, 20);
	
	fstream fIn(fileName); 

	char buffer[20];
	
	while (fIn >> buffer) { //read in and copy over to ensure null terminated char
		strcpy(wordList[counter], buffer); 
		counter++;
	}
}


void alphabetize() { //sort each row into alphabetical order to then use strcmp
	
	for (unsigned int u = 0; u < counter; u++) {
		for (unsigned int i = 0; i < strlen(wordList[u]) - 1; i++) {
			for (unsigned int j = i + 1; j < strlen(wordList[u]); j++) {
				if (wordList[u][i] > wordList[u][j]) {  //ASCII code values
					swap(wordList[u][i], wordList[u][j]); // simply swap the characters
				}
			}
		}
	}	
}

void compareArrays() {
	
	 for (int x = 0; x < counter; x++)
	{
		cout << x+1 << ". " << wordList[x] << endl; //print out all rows (as given by input) of words in alphabetical order
	}
	
	for (int a = 0; a < counter; a++) {
		for(int b = 1; b <= counter; b++) {
			if(a == b) break;
			else if (strcmp(wordList[a], wordList[b]) == 0) { //evaluates to true
				cout << "Duplicate found at rows " << a+1 << " and " << b+1 << endl;  //display rows matches were found at
			} 
		}
	}	
}

   
            
   

 
