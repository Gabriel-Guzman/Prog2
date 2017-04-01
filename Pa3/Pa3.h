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

bool is_in_vector(vector <string> v, string to_find) {
	return (find(v.begin(), v.end(), "(") != v.end());
}

int count_in_string(string s, char to_find) {
	size_t n = std::count(s.begin(), s.end(), to_find);
}

vector<string> split_string(string s, string delimeter){
	//TODO make split string func

}