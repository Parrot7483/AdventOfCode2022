#include <iostream>
#include <fmt/core.h>

#include "shared.h"

using namespace std;

int main() {
	for (auto [i, line] = tuple{0, string()}; getline(cin, line); i++) {
		cout << fmt::format("{} - {}", hello(i), line) << endl;
	}

	return 0;
}
