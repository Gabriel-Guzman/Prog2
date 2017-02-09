#pragma once

bool checkInput(int input) {
	bool valid = true;

	if (input % 2 != 1 || input < 3 || input > 15) {
		std::cout<<"Input number must be odd and between 3 and 15. inclusive.\nPlease try again: "<<std::endl;
		valid = false;
	}


	return valid;
}