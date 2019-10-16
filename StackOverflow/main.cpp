#include <iostream>


int findMax(int anyNumber);

int main(int argc, char **argv)
{
	findMax(0);
	return 0;
}

int findMax(int anyNumber) {
		std::cout << anyNumber << std::endl;
        return findMax(++anyNumber);
}
