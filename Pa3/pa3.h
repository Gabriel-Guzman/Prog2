void remove_from_string( string &str, string chars_to_remove ) {
   for (unsigned int i = 0; i < chars_to_remove.length(); ++i) {
      str.erase(remove(str.begin(), str.end(), chars_to_remove[i]), str.end());
   }
}

bool is_in_string(string str, char to_find) {
	bool found = false;
	for(unsigned int i = 0; i < str.length(); i++){
		if(str[i] == to_find) {
			found = true;
		}
	}

	return found;
}

vector<string> tokenize_string(string str, string delimeters){
	vector<string> tokens;
	string current_token = "";

	stringstream ss;
	string s;
	char c;
	
	for(unsigned int i = 0; i < str.length(); i++){
		c = str[i];
		ss << c;
		ss >> s;

		//cout << current_token << " Before" << endl;


		if(!is_in_string(delimeters, c)) {
			current_token.append(s);
		} else {

			tokens.push_back(current_token);
			//cout << current_token;
			current_token = "";

		}

		if (i + 1 == str.length())
		{
			tokens.push_back(current_token);
			current_token = "";
		}

		ss.clear();//clear any bits set
		ss.str(std::string());

		//cout << current_token << " After" << endl;
	}

	return tokens;
}

bool is_in_vector(vector <string> v, string to_find) {
	return (find(v.begin(), v.end(), to_find) != v.end());
}

int count_in_string(string s, char to_find) {
	return count(s.begin(), s.end(), to_find);
}

//template <typename T>
bool push_to_vector (vector<string> & vec, string to_push)  { 
	bool pushed = false;
	if(!is_in_vector(vec, to_push)){
		pushed = true;
		vec.push_back(to_push);
	}

	return pushed;
} 

bool has_uppercase (string str) {
	bool has_upper = false;
	for (unsigned int i  = 0; i < str.length(); i++){

		if (isupper(str[i])) {
			has_upper = true;

		}
	}

	return has_upper;
}

bool has_digit (string str) {
	bool has_digit = false;
	for (unsigned int i  = 0; i < str.length(); i++){

		if (isdigit(str[i])) {
			has_digit = true;

		}
	}

	return has_digit;

}