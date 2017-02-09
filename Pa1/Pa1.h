#pragma once

void sums(int matrix[15][15], int size) {
	int sum;
	std::cout<<"Sums of every row:\t";
	for (int i = 0; i < size; i++) {
		sum = 0;
		for(int j = 0; j < size; j++) {
			sum += matrix[j][i];
		}
		std::cout<<sum<<"\t";
	}
	std::cout<<std::endl;

	std::cout<<"Sums of every column: \t";
	for (int i = 0; i < size; i++) {
		sum = 0;
		for(int j = 0; j < size; j++) {
			sum += matrix[i][j];
		}
		std::cout<<sum<<"\t";
	}
	std::cout<<std::endl;

	std::cout<<"Sums of both diagonals:\t";

	sum = 0;
	for (int i = 0; i < size; i ++) {
		sum += matrix[i][i];
	}
	std::cout<<sum<<"\t";

	sum = 0;
	for (int i = 0; i < size; i ++) {
		sum += matrix[i][size - 1 - i];
	}
	std::cout<<sum<<"\t";
	std::cout<<std::endl;
}

void printMagicSquare(int matrix[15][15], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			std::cout<<matrix[j][i]<<"\t";
		}
		std::cout<<std::endl;
	}

}

bool checkInput(int input) {
	bool valid = true;

	if (input % 2 != 1 || input < 3 || input > 15) {
		std::cout<<"Input number must be odd and between 3 and 15. inclusive.\nPlease try again: "<<std::endl;
		valid = false;
	}


	return valid;
}
void buildMagicSquare(int size) {
	int matrix[15][15];

	for (int i = 0 ; i < 15 ; i ++ ) {
		for ( int j = 0 ; j < 15 ; j++ ) {
			matrix[i][j] = -1; //I will be using -1 to indicate an empty slot
		}
	}

	int currentX = (size + 1) / 2 - 1;
	int currentY = 0;
	int counter  = 1;

	while(true) {
		if (matrix[currentX][currentY] != -1) {
			printMagicSquare(matrix, size);
			break;
		}

		matrix[currentX][currentY] = counter;

		if ( currentX == size - 1 && currentY == 0 ) {
			currentY += 1;
		}
		else if ( currentY == 0 ) {
			currentY = size - 1;
			currentX += 1;
		}
		else if ( currentX == size - 1) {
			currentY -= 1;
			currentX = 0;
		}
		else {
			if (matrix[ currentX + 1 ][ currentY - 1 ] == -1) {
				currentX += 1;
				currentY -= 1;
			} else {
				currentY += 1;
			}
		}
		counter++;
	}
	sums(matrix, size);
}
