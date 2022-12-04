#include <iostream>
#include <string>
#include <tuple>
#include <fmt/core.h>

using namespace std;

int main() {
	int result {0}; 
	
	for (auto line = string(); getline(cin, line); ) {
		pair<int,int> a;
		pair<int,int> b;

		sscanf(line.c_str(), "%i-%i,%i-%i", &a.first, &a.second, &b.first, &b.second);

		if ((a.second < b.second && a.second >= b.first) 
			|| (a.second >= b.second && b.second >= a.first))
			result++;

		// cout << fmt::format("{}-{} {}-{}", a.first, a.second, b.first, b.second) << endl;
	}

	cout << result;
	return 0;
}
