#include "ctype.h"
#include "shared.h"

int priority(const char c) {
	if (isupper(c)) 
		return c - 65 + 27;
	else 
		return c - 97 + 1;
}

