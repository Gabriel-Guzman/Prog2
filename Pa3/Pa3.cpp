#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#include "Pa3.h"

int main()
{
	stack <string> main_stack;

	cout<<"Please enter the file name."<<endl;

	string file_name;
	getline(cin, file_name);

	ifstream file_input;
	file_input.open(file_name.c_str());

	string temp;
	vector<string> keywords;
	vector<string> errors;
	vector<string> operators;
	vector<string> delimiters;

	bool for_loop = false;

	while(!file_input.eof()){

		file_input >> temp;

		if(temp.compare("FOR") == 0){
			main_stack.push("FOR");
			for_loop = true;

			string indices;
			getline(file_input, indices);

			remove_from_string(indices, " ");

			bool open_parenthesis = (indices[0] == '(');
			int length = indices.length();

			int i;
			if(open_parenthesis) {
				i = 1;
				cout << "NOT MISSING (" << endl;
			} else {
				i = 0;
				if (! is_in_vector(errors, "(")) {
					errors.push_back("(");
					cout << "MISSING (" << endl;
				}
			}

			//Checking for delimiters in the indices
			if(is_in_string(indices, ',')){
				if(!is_in_vector(delimiters, ",")){
					delimiters.push_back(",");
				}
			}

			if (count_in_string(indices, ')') != 1) {
				if(!is_in_vector(errors, ")")){
					delimiters.push_back(")");
				}
			}

			remove_from_string(indices, "()");

			cout << indices;
		}

	}

	file_input.close();

	return 0;
}