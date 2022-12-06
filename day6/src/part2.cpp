#include <iostream>

#include "shared.h"

using namespace std;

int main() {
	for (auto line = string(); getline(cin, line); ) {
		cout << find_marker(line, 14) << endl;
	}

	return 0;
}
