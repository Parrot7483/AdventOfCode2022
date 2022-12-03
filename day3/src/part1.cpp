#include <iostream>
#include <string>
#include <algorithm>

#include "shared.h"

using namespace std;

int main() {
	int sum {0};

	for (auto line = string(); getline(cin, line); ) {
		string left = line.substr(0, line.length() / 2);
		string right = line.substr(line.length() / 2);
		
		sort(left.begin(), left.end());
		sort(right.begin(), right.end());

		string inter;
		set_intersection(left.begin(), left.end(), right.begin(), right.end(), back_inserter(inter));
		const char common_elem = inter[0];

		sum += priority(common_elem);
	}

	cout << sum;

	return 0;
}
