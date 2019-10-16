#include "searchFunctions.h"
#include <iostream>

using namespace std;

void mergeSort(unsigned int numbers[], int i, unsigned int k) {
	
}

void selectionSort(unsigned int moreNums[], int i, unsigned int size) {
	
}

void merge(unsigned int numbers[], int i, int j, unsigned int k) {
	
}

int Merge(unsigned short int numbers[], int i, int j, unsigned short int k) {



   int mergedSize;                            // Size of merged partition

   int mergePos;                              // Position to insert merged number

   int leftPos;                               // Position of elements in left partition

   int rightPos;                              // Position of elements in right partition

   int* mergedNumbers = nullptr;



   int sendBack = 0;



   mergePos = 0;

   mergedSize = k - i + 1;

   leftPos = i;                               // Initialize left partition position

   rightPos = j + 1;                          // Initialize right partition position

   mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array

                                              // for merged numbers

   

   // Add smallest element from left or right partition to merged numbers

   while (leftPos <= j && rightPos <= k) {

      if (numbers[leftPos] < numbers[rightPos]) {

         mergedNumbers[mergePos] = numbers[leftPos];

         ++leftPos;

      }

      else {

         mergedNumbers[mergePos] = numbers[rightPos];

         ++rightPos;

         

      }

      ++mergePos;

      sendBack++;

   }

   

   // If left partition is not empty, add remaining elements to merged numbers

   while (leftPos <= j) {

      mergedNumbers[mergePos] = numbers[leftPos];

      ++leftPos;

      ++mergePos;

      sendBack++;

   }

   

   // If right partition is not empty, add remaining elements to merged numbers

   while (rightPos <= k) {

      mergedNumbers[mergePos] = numbers[rightPos];

      ++rightPos;

      ++mergePos;

      sendBack++;

   }

   

   // Copy merge number back to numbers

   for (mergePos = 0; mergePos < mergedSize; ++mergePos) { 

        numbers[i + mergePos] = mergedNumbers[mergePos];

        sendBack++;  

   }



    return sendBack;



}



int MergeSort(unsigned short int numbers[], int i, unsigned short int k) {



    int j;

    int returnValue = 0;

   

   if (i < k) {

      j = (i + k) / 2;  // Find the midpoint in the partition

      

      // Recursively sort left and right partitions

      returnValue += MergeSort(numbers, i, j);

      returnValue += MergeSort(numbers, j + 1, k);



      // Merge left and right partition in sorted order

      returnValue += Merge(numbers, i, j, k);

   }



    return returnValue;



}



int SelectionSort(unsigned short int numbers[], unsigned short int size) {

   int returnValue = 0;

   int i;

   int j;

   int indexSmallest;

   int temp;      

   

   for (i = 0; i < size - 1; ++i) {

      

      // Find index of smallest remaining element

      indexSmallest = i;

      for (j = i + 1; j < size; ++j) {

         

         if ( numbers[j] < numbers[indexSmallest] ) {

            indexSmallest = j;

         }

         returnValue++;

      }

      

      // Swap numbers[i] and numbers[indexSmallest]

      temp = numbers[i];

      numbers[i] = numbers[indexSmallest];

      numbers[indexSmallest] = temp;

    }



    return returnValue; 



}