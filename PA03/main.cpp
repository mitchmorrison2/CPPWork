#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

short int counter = 0;
char wordList[50][20];

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
	
	fstream fIn(fileName); //would be fileName

	char buffer[20];
	
	while (fIn >> buffer) {
		strcpy(wordList[counter], buffer);
		counter++;
	}
}


void alphabetize() {
	
	for (unsigned int u = 0; u < counter; u++) {
		for (unsigned int i = 0; i < strlen(wordList[u]) - 1; i++) {
			for (unsigned int j = i + 1; j < strlen(wordList[u]); j++) {
				if (wordList[u][i] > wordList[u][j]) {
					swap(wordList[u][i], wordList[u][j]); // simply swap the characters
				}
			}
		}
	}
	
	
}



void compareArrays() {
	
	 for (int x = 0; x < counter; x++)
	{
		cout << wordList[x] << endl;
	}
	
	
	for (int a = 0; a < counter; a++) {
		for(int b = 1; b <= counter; b++) {
			if(a == b) break;
			else if (strcmp(wordList[a], wordList[b]) == 0) {
				cout << "Match found at rows " << a+1 << " and " << b+1 << endl;
			} 
		}
	}
	
	
	
	
}

   
            
   

 