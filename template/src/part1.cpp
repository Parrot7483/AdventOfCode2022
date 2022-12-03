#include <iostream>

#include "shared.h"

using namespace std;

int main() {
	for (auto line = string(); getline(cin, line); ) {
		cout << line << endl;
	}

	return 0;
}
