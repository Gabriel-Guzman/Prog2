#include <iostream>
#include <stack>
#include <string>
#include <fstream>

int main()
{
	std::stack <std::string> main_stack;

	std::string file_name;
	std::getline(std::cin, file_name);

	std::ifstream file_input;
	file_input.open(file_name.c_str());

	std::string temp;
	while(!file_input.eof){
		file_input >> temp;
		main_stack.push_back(temp);
	}

	return 0;
}