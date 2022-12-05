#include <iostream>
#include <string>

#include "shared.h"

vector<stack<char>> read_in_stacks() {
	vector<string> stacks_input {};
	for (auto line = string(); getline(cin, line) && line.length() != 0; ) {
		stacks_input.push_back(line);
	}
	stacks_input.erase(stacks_input.end() - 1);

	vector<stack<char>> stacks(stacks_input[0].length() / 3);
	for (auto it = stacks_input.rbegin(); it != stacks_input.rend(); it++) {
		for (unsigned int i {0}; i < stacks.size() && (1 + (i * 4)) < (*it).length(); i++) {
			const char c = (*it).at(1 + (i * 4));
			if (c != ' ') stacks[i].push(c);
		}
	}

	return stacks;
}


vector<Move> read_in_moves() {
	vector<Move> moves {};

	for (auto line = string(); getline(cin, line); ) {
		Move m; 
		sscanf(line.c_str(), "move %i from %i to %i", &m.size, &m.from, &m.to);
		moves.push_back(m);
	}

	return moves;
}
