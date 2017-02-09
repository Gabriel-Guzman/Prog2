#include <iostream>
#include <string>
#include <limits>
#include "Pa1.h"

int main() {

	int validateSize;

	while (true) {
		std::cout<<"Enter the size of the magic square: ";
		std::cin>>validateSize;
		//Checking if input is an int
		if (std::cin.fail()) {
			std::cin.clear();
  			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input is not a number. Please try again: ";
			std::cin >> validateSize;
		} 

		//Checking if input has an appropriate value
		if (checkInput(validateSize)) {
			buildMagicSquare(validateSize);
		} else {
			continue;
		}

	} 
	return 0;
}