#include <iostream>
#include <string>
#include <limits>
#include "pa1.h"

int main() {

	int validateSize;

	while (true) {
		std::cout<<"Enter the size of the magic square or hit CTRL+C to end: ";
		std::cin>>validateSize;
		//Checking if input is an int
		while (std::cin.fail()) { //If the input value from the stream was not an int
			std::cin.clear();
  			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input is not a number. Please try again: ";
			std::cin >> validateSize;
		} 

		//Checking if input has an appropriate value
		if (checkInput(validateSize)) {
			
			std::cout<<"Matrix #1"<<std::endl;			
			int ** matrix = buildMagicSquare(validateSize);
			printMagicSquare(matrix, validateSize); //Instead of permuting, I'm mirroring the square


			std::cout<<"Matrix #2"<<std::endl;
			matrix = horizontalFlip(matrix, validateSize);
			printMagicSquare(matrix, validateSize);

			std::cout<<"Matrix #3"<<std::endl;
			matrix = verticalFlip(matrix, validateSize);
			printMagicSquare(matrix, validateSize);

			std::cout<<"Matrix #4"<<std::endl;
			matrix = horizontalFlip(matrix, validateSize);
			printMagicSquare(matrix, validateSize);
				

		} else {
			continue;
		}

	} 
	return 0;
}