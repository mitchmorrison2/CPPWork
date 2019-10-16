#include <iostream>

using namespace std;


//creates new array of all multiples of all elements
int *apply_all (int array1[], size_t size1, int array2[], size_t size2);
void printFunction(int *newArrayPtr, int endSize);

int main (void) {

//initializing first and second arrays
int ar1[] {13, 23, 99, 1, 7};
int ar2[] {10, 20, 72};
size_t ar1size = sizeof(ar1) / sizeof(int); 
size_t ar2size = sizeof(ar2) / sizeof(int);
//size of new array
int totalSize = ar1size * ar2size;

int *newArray {nullptr};
newArray = apply_all(ar1, ar1size, ar2, ar2size);
printFunction(newArray, totalSize);

//keep from memory leak
delete [] newArray;

   return 0;
}


int *apply_all (int array1[], size_t size1, int array2[], size_t size2) {
	
	int sizeAll = size1 * size2;
	
	int *newArrayPtr = new int[sizeAll];
	
	int counter = 0;
	for (size_t a = 0; a < size1; a++) {
		for (size_t b = 0; b < size2; b++) {
			int tempVar = array1[a] * array2[b];
			newArrayPtr[counter] = tempVar;
			counter++;
		}
	}
	
	return newArrayPtr;
} 

void printFunction(int *newArrayPtr, int endSize) {
	for (int a = 0; a < endSize; a++) {
		cout << newArrayPtr[a] << endl;
	}
}
