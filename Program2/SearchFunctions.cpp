#include <vector>
#include <string>
#include <iostream>

using namespace std;

int searchRecursive(std::vector<std::string> &data, std::string query) {
	
	static int returnValue = 0;
	if (data[returnValue] == query) {
		return returnValue;
	}
	else if (data.size() == returnValue) {
		returnValue = -1;
	}
	else {
		returnValue += 1;
		searchRecursive(data, query);
	}
	return returnValue;
} //end searchRecursive

int searchIterative(std::vector<std::string> &data, std::string query) {
	int returnValue = -1;
	for (int i = 0; i < data.size(); i++) {
		if (query == data[i]) {
			returnValue = i;
			break;
		}
	}
	return returnValue;
} //end serachItertive


//how does the system know if we are looking for name PN??