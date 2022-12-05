#include <vector>
#include <stack>

using namespace std;

typedef struct move {
	int from;
	int to;
	int size;
} Move;

vector<stack<char>> read_in_stacks();
vector<Move> read_in_moves();
