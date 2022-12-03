#include "shared.h"

string hello(int i) {
	string result {"hall"};

	for (; i >= 0; i--)
		result += 'o';

	return result;
}
