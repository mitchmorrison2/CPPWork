
#include <iostream>
#include <cstring>
#include <string.h>


using namespace std;

int *apply_all (int array1[], size_t size1, int array2[], size_t size2);
void printFunction(int *newArrayPtr, int endSize);
int returnandcheckstack(int n);

int counter = 0;

int main (void) {
//   char string[] = "differentword";
//   char temp;
//
//   int i, j;
//   int n = strlen(string);
//
//   printf("String before sorting - %s \n", string);
//   
//   for (i = 0; i < n-1; i++) {
//      for (j = i+1; j < n; j++) {
//         if (string[i] > string[j]) {
//            temp = string[i];
//            string[i] = string[j];
//            string[j] = temp;
//         }
//      }
//   }
//   
//   printf("String after sorting  - %s \n", string);

//int arrayPrac[4] {1, 2, 3, 4};
//cout << arrayPrac << endl;
//
//int *array_ptr {arrayPrac};
//cout << array_ptr << endl;
//
//
//cout << *array_ptr << endl;
//
//
//vector<string> stooges {"Larry", "Moe", "Curly"};
//
//for (int i = 0; i < 3; i++) {
//	stooges[i] = "Funny";
//	cout << stooges[i] << endl;
//}

//vector<string> *str_ptr {nullptr};
//
//vector<string> parts {"Wheels", "Frame", "Headlights"};
//for (int x = 0; x < 3; x++) {
//	cout << parts[x]<< endl;
//	
//} 
//
//str_ptr = parts;
//cout << *str_ptr;

//
//int ar1[] {13, 23, 99, 1, 7};
//int ar2[] {10, 20, 72};
//size_t ar1size = sizeof(ar1) / sizeof(int); 
//size_t ar2size = sizeof(ar2) / sizeof(int);
//int totalSize = ar1size * ar2size;
//
//int *newArray {nullptr};
//newArray = apply_all(ar1, ar1size, ar2, ar2size);
//printFunction(newArray, totalSize);
//
//delete [] newArray;

//	returnandcheckstack(10);
//	cout << "Function was called " << counter << " times";

char data[6][10];
data[0] == "Sam";
data[1] == "Robert";
data[2] == "Mark";
data[3] =="Jason";
data[4] == "Alex";
data[5] == "Karen"; 
printf(*data[2]);
   return 0;
}


//int *apply_all (int array1[], size_t size1, int array2[], size_t size2) {
//	
//	int sizeAll = size1 * size2;
//	
//	int *newArrayPtr = new int[sizeAll];
//	
//	int counter = 0;
//	for (size_t a = 0; a < size1; a++) {
//		for (size_t b = 0; b < size2; b++) {
//			int tempVar = array1[a] * array2[b];
//			newArrayPtr[counter] = tempVar;
//			counter++;
//		}
//	}
//	
//	return newArrayPtr;
//} 
//
//void printFunction(int *newArrayPtr, int endSize) {
//	for (int a = 0; a < endSize; a++) {
//		cout << newArrayPtr[a] << endl;
//	}
//}

int returnandcheckstack(int n) {
		int y = n*returnandcheckstack(n-1);
		++counter;
		return y;
	}