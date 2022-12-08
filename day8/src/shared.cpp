#include <iostream>
#include <vector>
#include <string>

#include "shared.h"

vector<int> convert_string_to_vector(const string& input) {
	vector<int> result {};

	for (const char c: input)
		result.push_back(c - '0');
	
	return result;
}

vector<vector<int>> read_in_matrix() {
	vector<vector<int>> input {};

	for (auto line = string(); getline(cin, line); ) {
		input.push_back(convert_string_to_vector(line));
	}
	
	return input;
}

void print_matrix(const vector<vector<int>>& matrix) {
	for (const auto& row: matrix) {
		for (const int i: row) {
			cout << i << " "; 
		}
		cout << endl;
	}
}

