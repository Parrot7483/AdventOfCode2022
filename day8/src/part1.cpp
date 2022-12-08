#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <tuple>

#include "shared.h"

using namespace std;

int count_visible_trees(const vector<vector<int>>& matrix) {
	set<pair<int,int>> visibles {};
	const auto rows {matrix.size()};
	const auto cols {matrix[0].size()};

	// Left to Right
	for (auto i = 0; i < rows; i++) {
		int max_height {-1};
		for (auto j = 0; j < cols; j++) {
			if (auto tmp_height = matrix[i][j]; tmp_height > max_height) {
				max_height = tmp_height;
				visibles.insert({i, j});
			} 		
		}
	}

	// Right to left
	for (auto i = 0; i < rows; i++) {
		int max_height {-1};
		for (auto j = cols - 1; j >= 0; j--) {
			if (auto tmp_height = matrix[i][j]; tmp_height > max_height) {
				max_height = tmp_height;
				visibles.insert({i, j});
			} 
		}
	}

	// top to bottom
	for (auto i = 0; i < rows; i++) {
		int max_height {-1};
		for (auto j = 0; j < cols; j++) {
			if (auto tmp_height = matrix[j][i]; tmp_height > max_height) {
				max_height = tmp_height;
				visibles.insert({j, i});
			} 
		}
	}

	// bottom to top
	for (auto i = 0; i < rows; i++) {
		int max_height {-1};
		for (auto j = cols - 1; j >= 0; j--) {
			if (auto tmp_height = matrix[j][i]; tmp_height > max_height) {
				max_height = tmp_height;
				visibles.insert({j, i});
			} 
		}
	}

	return visibles.size();
}

int main() {
	vector<vector<int>> matrix = read_in_matrix();
	cout << count_visible_trees(matrix);
	return 0;

}
