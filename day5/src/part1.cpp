#include <iostream>
#include <vector>
#include <stack>

#include "shared.h"

using namespace std;

int main() {
	vector<stack<char>> stacks = read_in_stacks();
	vector<Move> moves = read_in_moves();

	for (auto m: moves) {
		for (int i = m.size; i > 0; i--) {
			const char temp = stacks[m.from - 1].top();
			stacks[m.from - 1].pop();
			stacks[m.to - 1].push(temp);
		}
	}

	for (auto s: stacks) cout << s.top();
	return 0;
}
