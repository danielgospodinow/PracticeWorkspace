#include <iostream>
#include <stack>
#include <queue>

typedef unsigned int uint;

bool isOpeningBracket(char c) {
	return (c == '{' || c == '[' || c == '(');
}

char getOppositeBracket(char c) {
	switch(c) {
	case ')': return '(';
	case ']': return '[';
	case '}': return '{';
	}

	return '\0';
}

bool isBalanced(std::string brackets) {
	// Keep track of the open brackets in a stack
	std::stack<char> openBrackets;

	// Go through all brackets and check whether it's an opening one,
	// if it is, track it in the stack, if it's not, get the last opening
	// bracket and check if they match. If some pair of an opening and
	// a non-opening bracket missmatch, return false
	for(uint i=0; i<brackets.size(); ++i) {
		char currentBracket = brackets.at(i);

		if(isOpeningBracket(currentBracket)) {
			openBrackets.push(currentBracket);
		} else {
			if(openBrackets.size() <= 0) {
				return false;
			} else {
				char lastOpeningBracket = openBrackets.top();
				openBrackets.pop();

				if(lastOpeningBracket != getOppositeBracket(currentBracket)) {
					return false;
				}
			}
		}
	}

	return openBrackets.size() == 0;
}

int main() {
	std::cout << isBalanced("{[{}(}()]}") << std::endl;
	std::cout << isBalanced("{[{}()]}") << std::endl;
	std::cout << isBalanced("{[]}") << std::endl;
	std::cout << isBalanced("{") << std::endl;

	return 0;
}
