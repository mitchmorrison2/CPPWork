#include "FilesInAndOut.h"
#include <iostream>
#include <fstream>

using namespace std;



FilesInAndOut::FilesInAndOut()
{
}

FilesInAndOut::~FilesInAndOut()
{
}

int main() {
	ofStream fileOut("data.txt");
	if(!fileOut.is_open()) {
		cout << "Hey its not working yo";
	}
	
	for(int s = 0; s <10; s++) {
		cout << "Oh snap I am printing things in a new file";
	}
	
	fileOut.close();
	
	return 0;
	
}

