#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

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

	string temp_line;
	int current_loop_depth;
	int max_loop_depth;
	vector<string> keywords;
	vector<string> errors;
	vector<string> ops; //operator is a c++ keyword
	vector<string> delimiters;
	vector<string> identifiers;
	vector<string> constants;


	bool for_loop = false;

	while(getline(file_input, temp_line)){
		cout << temp_line << endl;

		if(has_uppercase(temp_line)) { // all lowercase
			string temp_word;

			istringstream iss(temp_line);
			iss >> temp_word;


			if(temp_word.compare("FOR") == 0){
				main_stack.push("FOR");
				current_loop_depth++;
				for_loop = true;

				string indices;
				getline(iss, indices);

				remove_from_string(indices, " ");

				//Checking for delimiters in the indices
				if(is_in_string(indices, ',')){
					push_to_vector(delimiters, ",");
				}

				if(indices[0] != '('){
					push_to_vector(errors, "(");
				}

				if(indices[indices.length() - 1] != ')'){
					push_to_vector(errors, ")");
				}

				if (count_in_string(indices, ')') != 1) {
					push_to_vector(errors, ")");
				}

				if (count_in_string(indices, '(') != 1) {
					push_to_vector(errors, "(");
				}


				remove_from_string(indices, "()");

				vector<string> tokens = tokenize_string(indices, ",");
				string identifier = tokens[0];
				string constant = tokens[1];
				string op = tokens[2];


				/*for(unsigned int i = 0; i != identifiers.size(); i++) {
	    			cout << "VECTOR DEMO: " << identifiers[i] << endl;
				}*/

			} 

		} else {
			//doesn't have uppercase

		}


	}
	file_input.close();
	return 0;
}