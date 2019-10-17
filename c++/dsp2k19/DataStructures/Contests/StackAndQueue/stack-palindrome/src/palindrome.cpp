#include <iostream>
#include <string>
#include <vector>
#include <stack>

typedef unsigned int uint;

bool isPalindrome(std::string string) {
	std::stack<char> chars;

	for(char c: string) {
		chars.push(c);
	}

	for(uint i=0; i<string.length() / 2; ++i) {
		char currentChar = string.at(i);
		char lastChar = chars.top();

		chars.pop();

		if(currentChar != lastChar) {
			return false;
		}
	}

	return true;
}

int main() {
	std::cout << isPalindrome("gegimigeg") << std::endl;

	return 0;
}
