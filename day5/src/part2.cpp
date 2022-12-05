#include <iostream>
#include <vector>
#include <stack>

#include "shared.h"

using namespace std;

int main() {
	vector<stack<char>> stacks = read_in_stacks();
	vector<Move> moves = read_in_moves();

	for (auto m: moves) {
		stack<char> temp {};

		for (int i = m.size; i > 0; i--) {
			temp.push(stacks[m.from - 1].top());
			stacks[m.from - 1].pop();
		}

		while (! temp.empty()) {
			stacks[m.to - 1].push(temp.top());
			temp.pop();
		}

	}

	for (auto s: stacks) cout << s.top();
	return 0;
}
