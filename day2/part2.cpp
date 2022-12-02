#include <iostream>
#include <unordered_map>

using namespace std;

enum class Move {Rock, Paper, Scissors};
enum class Result {Lose, Draw, Win};

Move get_move(const Move op_choi, const Result result) {
	switch(op_choi) {
		case Move::Rock:
			switch(result) {
				case Result::Lose: return Move::Scissors;
				case Result::Draw: return Move::Rock;
				case Result::Win: return Move::Paper;
				default: throw invalid_argument("");
			}
		case Move::Paper:
			switch(result) {
				case Result::Lose: return Move::Rock;
				case Result::Draw: return Move::Paper;
				case Result::Win: return Move::Scissors;
				default: throw invalid_argument("");
			}
		case Move::Scissors:
			switch(result) {
				case Result::Lose: return Move::Paper;
				case Result::Draw: return Move::Scissors;
				case Result::Win: return Move::Rock;
				default: throw invalid_argument("");
			}
		default: throw invalid_argument("");
	}
}

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
	
	const unordered_map<char,Result> result {{'X', Result::Lose}, 
											 {'Y', Result::Draw}, 
											 {'Z', Result::Win}};

	unsigned int total_points {0};
	for (auto line = string(); getline(cin, line); ) {
		const Move my_move = get_move(opponent_choises.at(line[0]), result.at(line[2]));
		total_points += play_round(opponent_choises.at(line[0]), my_move);
	}

	cout << total_points;
	return 0;
}
