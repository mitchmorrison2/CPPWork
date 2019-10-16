#include <stdio.h>
#include <iostream>
#include "person.h"

using namespace std;

int main()
{
	
	
//	cout << "Start of program. Create size of each array: " << endl;
//	
//	
//	int size;
//	cin >> size;
//	int *ptr1 = new int[size];
//	cout << "Ptr1 = " << ptr1 << endl;
//	int *ptr2 = new int [size+1];
//	cout << "Ptr2 = " << ptr2 << endl;
//	
//	int *ptr3 = new int[size+3];
//	cout << "Ptr3 = " << ptr3 << endl;
//	
//	int **ptrToPtr[] {};
//	ptrToPtr[0] = &ptr1;
//	ptrToPtr[1] = &ptr2;
//	ptrToPtr[2] = &ptr3;
//	
//	cout << "ptrToPtr = " << ptrToPtr << endl;
//	
//	ptr1[size-1] = 23;
//	cout << "ptr1["<< size-1 << "]: " <<ptr1[size-1] << endl;
//	
//	delete ptr1, ptr2, ptr3, ptrToPtr;
//
//	
//	
//	int a[3] = {13, 21, 35};
//	int* p = a;
//	cout << sizeof a << '\n'  // prints size of array
//				<< sizeof p << '\n'; // prints size of a pointer
//	for(int n: a) {          // okay: arrays can be used in range-for loops
//	std::cout << n << ' '; // prints elements of the array
//	}
//	 for(int n: p) {       // error: no range for looping on a pointer
//		cout << '\n' << n; // arrays and pointers share the same semantics
//		<< *a << '\n' // prints the first element
//		<< *p << '\n' // same
//		<< *(a + 1) << ' ' << a[1] << '\n'  // prints the second element twice
//		<< *(p + 1) << ' ' << p[1] << '\n'; // same
	
	Person p;
	
	Person p2("Mitchell", 18);
	
	cout << p2.getName() << endl;
	cout << p.getName() << endl;
	
	p = p2 + 3; //p2.operator+(3)
	cout << p.getName() << endl;
	cout << p.getAge() << endl;
	
	cout << "p2" << endl;
	cout << p2.getName() << endl;
	cout << p2.getAge() << endl;
	
	
	
return 0;
}


