#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>

using namespace std;

const string cd_cmd_pref {"$ cd "};
const string ls_cmd {"$ ls"};
const string dir_list_pref {"dir "};

bool is_cd_cmd(const string& line) {
	return 0 == strncmp(line.c_str(), cd_cmd_pref.c_str(), cd_cmd_pref.size());
}

string get_dir_name(const string& line) {
	if (! is_cd_cmd(line))
		throw invalid_argument("Line is not a change directory command");

	return string(line.begin() + 5, line.end());
}

bool is_dir_list(const string& line) {
	return 0 == strncmp(line.c_str(), dir_list_pref.c_str(), dir_list_pref.size());
}

int get_file_size(const string& line) {
	string size = line.substr(0, line.find(" "));
	return stoi(size);
}

bool is_ls_cmd(const string& line) {
	return 0 == strncmp(line.c_str(), ls_cmd.c_str(), ls_cmd.size());
}

int iterate_filesys(vector<pair<string, unsigned int>>& dirs, const vector<string>& input, vector<string>::iterator& it) {
	const string dir_name = get_dir_name(*it++);
	if (! is_ls_cmd(*it++)) throw logic_error("Excpected a list cmd");

	unsigned int size {0};

	for ( ; it < input.end(); it++) {
		if (is_ls_cmd(*it))
			throw logic_error("Unexpected ls cmd");

		if (is_cd_cmd(*it) && ".." == get_dir_name(*it))
			break;
		
		if (is_cd_cmd(*it))
			size += iterate_filesys(dirs, input, it);
		else if (! is_dir_list(*it))
			size += get_file_size(*it);
	}

	dirs.push_back({dir_name, size});
	return size;
}

vector<pair<string, unsigned int>> get_dirs(vector<string>& input) {
	vector<pair<string, unsigned int>> dirs {};
	vector<string>::iterator it = input.begin(); 	
	iterate_filesys(dirs, input, it);
	return dirs;
}

int main() {
	vector<string> input; 

	for (auto line = string(); getline(cin, line); ) input.push_back(line);

	vector<pair<string, unsigned int>> dirs = get_dirs(input);
	sort(dirs.begin(), dirs.end(), [](const auto& left, const auto& right){ return left.second < right.second; });

	unsigned int sum {0};
	for (const auto& pair: dirs) {
		if (pair.second <= 100000)
			sum += pair.second;
	}

	unsigned int root_size = dirs.back().second;
	unsigned int free_space = 70000000 - root_size;
	unsigned int to_free = 30000000 - free_space;
	cout << "sum: " << sum << endl;

	for (const auto& pair: dirs) {
		if (pair.second >= to_free) {
			cout << "size delete dir: " << pair.second; 
			break;
		} 
	}

	return 0;
}
