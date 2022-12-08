#include <iostream>
#include <vector>
#include <tuple>

#include "shared.h"

using namespace std;

int calc_scenic_score(vector<vector<int>>& matrix, pair<int,int> pos) {
	const auto rows {matrix.size()};
	const auto cols {matrix[0].size()};
	int height = matrix[pos.first][pos.second];

	int result {1};
	int temp_count {0};
	// Look up
	for (auto i {pos.second - 1}; i >= 0; i--) {
		if (matrix[pos.first][i] < height) temp_count++;
		else { 
			temp_count++;
			break;
		}
	}
	result *= temp_count;
	temp_count = 0;

	// Look right
	for (auto i {pos.first + 1}; i < cols; i++) {
		if (matrix[i][pos.second] < height) temp_count++;
		else { 
			temp_count++;
			break;
		}
	}
	result *= temp_count;
	temp_count = 0;

	// Look down
	for (auto i {pos.second + 1}; i < rows; i++) {
	 	if (matrix[pos.first][i] < height) temp_count++;
		else { 
			temp_count++;
			break;
		}
	}
	result *= temp_count;
	temp_count = 0;

	// Look left
	for (auto i {pos.first - 1}; i >= 0; i--) {
		if (matrix[i][pos.second] < height) temp_count++;
		else { 
			temp_count++;
			break;
		}
	}
	result *= temp_count;

	return result;
}

int main() {
	vector<vector<int>> matrix = read_in_matrix();

	const auto rows {matrix.size()};
	const auto cols {matrix[0].size()};

	int result {-1};
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result = max(result, calc_scenic_score(matrix, {i,j}));
		}
	}

	cout << result;
	return 0;
}
