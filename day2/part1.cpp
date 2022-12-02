#include <iostream>
#include <unordered_map>

using namespace std;

enum class Move {Rock, Paper, Scissors};

int play_round(const Move op_choi, const Move my_choi) {
	int result {0};

	if (op_choi == my_choi) {
		result += 3;
	} else if (op_choi == Move::Rock && my_choi == Move::Paper 
		|| op_choi == Move::Paper && my_choi == Move::Scissors 
		|| op_choi == Move::Scissors && my_choi == Move::Rock) 
	{
		result += 6;
	}

	if (my_choi == Move::Rock)
		result += 1;
	else if (my_choi == Move::Paper)
		result += 2;
	else 
		result += 3;

	return result;
}

int main() {
	const unordered_map<char,Move> opponent_choises {{'A', Move::Rock}, 
													 {'B', Move::Paper}, 
													 {'C', Move::Scissors}};
	
	const unordered_map<char,Move> my_choises {{'X', Move::Rock}, 
											   {'Y', Move::Paper}, 
											   {'Z', Move::Scissors}};

	unsigned int result {0};
	for (auto line = string(); getline(cin, line); ) {
		result += play_round(opponent_choises.at(line[0]), my_choises.at(line[2]));
	}

	cout << result;
	return 0;
}
