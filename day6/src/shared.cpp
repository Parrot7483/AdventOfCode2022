#include <string>
#include <unordered_set>

#include "shared.h"

bool no_duplicates(const string& input) {
	unordered_set<char> chars {};

	for (const auto c: input) {
		if (chars.contains(c))
			return false;

		chars.insert(c);
	}

	return true;
}

int find_marker(const string& input, const int len) {
	auto ai = input.begin();
	auto bi = input.begin() + len;
	int result {len};

	while (bi != input.end()) {
		if (no_duplicates(string(ai, bi)))
			return result;

		ai++;
		bi++;
		result++;
	}
	
	return -1;
}
