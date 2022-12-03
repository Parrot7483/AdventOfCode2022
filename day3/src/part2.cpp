#include <iostream>
#include <string>
#include <fmt/core.h>

#include "shared.h"

using namespace std;

string tripple_string_intersection(string a, string b, string c) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());

		string inter_temp;
		set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(inter_temp));

		string result;
		set_intersection(inter_temp.begin(), inter_temp.end(), c.begin(), c.end(), back_inserter(result));
		
		return result;
}

int main() {
	vector<string> input;
	for (auto line = string(); getline(cin, line); ) {
		input.push_back(line);
	}

	int sum {0};
	for (unsigned long i {0}; i < input.size() - 2; i+=3) {
		const char common_char = tripple_string_intersection(input[i], input[i+1], input[i+2])[0];
		sum += priority(common_char);
	}

	cout << sum;

	return 0;
}
