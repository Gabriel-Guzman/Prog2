#pragma once

int ** buildMatrix(int size) {
	int** matrix = new int*[15];
	for (int i = 0; i < 15; ++i)
	{
	   matrix[i] = new int[15];
	}
	return matrix;
}

void sums(int ** matrix, int size) {
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
	std::cout<<std::endl<<std::endl;
}

void printMagicSquare(int ** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			std::cout<<matrix[j][i]<<"\t";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;

	sums(matrix, size);


}

bool checkInput(int input) {
	bool valid = true;

	if (input % 2 != 1 || input < 3 || input > 15) {
		std::cout<<"Input number must be odd and between 3 and 15. inclusive.\nPlease try again: "<<std::endl;
		valid = false;
	}


	return valid;
}
int ** buildMagicSquare(int size) {
	int** matrix = buildMatrix(size);

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
	return matrix;
}

int** horizontalFlip(int ** matrix, int size) {

	int** flipped = buildMatrix(size);
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			flipped[i][j] = -1;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			flipped[j][i] = matrix[size - j - 1][i];
		}
	}	

	return flipped;
}

int** verticalFlip(int ** matrix, int size) {

	int** flipped = buildMatrix(size);
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			flipped[i][j] = -1;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			flipped[j][i] = matrix[j][size - i - 1];
		}
	}	

	return flipped;
}

