#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	const unsigned int top_nth {3};

	vector<int> sums {0}; 
	for (auto [i, line] = tuple{0, string()}; getline(cin, line); ) {
		if (0 != line.length()) {
			sums[i] += stoi(line);
		} else {
			sums.push_back(0);
			i++; 
		}
	}

	nth_element(sums.begin(), sums.begin() + top_nth, sums.end(), greater{});

	cout << "max: " << *max_element(sums.begin(), sums.begin() + top_nth) << endl;
	cout << "sum top " << top_nth << ": " << accumulate(sums.begin(), sums.begin() + top_nth, 0) << endl;

	return 0;
}
