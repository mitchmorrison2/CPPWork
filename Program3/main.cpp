#include <stdio.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include "searchFunctions.h"

int main()
{
	ofstream mitchfile;
	mitchfile.open("Program3.csv");
	mitchfile << "This is a csv file with 2 columns, 1 for each style of sorting";
	if (!mitchfile.is_open()) {
		cerr << "File not opening";
		return -1;
	}
	
	unsigned int n = 2;
	
	while (n <= 100) {
		
		int s = 0, m = 0;
		
		for (int i = 0; i < 10000; i++) {
			unsigned int numbers[100];
			unsigned int moreNums[100];
			unsigned int size = n;
			
			for (int counter = n-1; counter >= 0; counter--) { //going down in size to last element
				srand(time(0)); //declaration for rand generator
				numbers[n] = (rand() % 1000) + 1; //ran num between 1 and 1000
				moreNums[n] = numbers[n]; //creating duplicate null-term c string array
			}
			
			s = selectionSort(numbers, size);
			m = mergeSort(moreNums, 0, size-1);
			
		} //end 10000 trials
		
		mitchfile << n << "," << s << "," << m << endl;
		n++;
		
	} //end while loop
	
	return 0;
}
