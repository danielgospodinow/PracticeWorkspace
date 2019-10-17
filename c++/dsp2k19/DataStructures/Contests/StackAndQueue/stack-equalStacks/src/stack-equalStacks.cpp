#include <iostream>
#include <vector>

typedef unsigned int uint;

int getVectorSum(const std::vector<int> &vector) {
	int sum = 0;

	for(int item: vector) {
		sum += item;
	}

	return sum;
}

void updateVector(std::vector<int> &vec, int &vecSum) {
	int lastElement = vec.front();
	vec.erase(vec.begin());

	vecSum -= lastElement;
}

int equalStacks(std::vector<int> h1, std::vector<int> h2, std::vector<int> h3) {
	int h1Sum = getVectorSum(h1);
	int h2Sum = getVectorSum(h2);
	int h3Sum = getVectorSum(h3);

	while(!(h1Sum == h2Sum && h2Sum == h3Sum)) {
		if(h1Sum >= h2Sum && h1Sum >= h3Sum) {
			updateVector(h1, h1Sum);
		} else if(h2Sum >= h1Sum && h2Sum >= h3Sum) {
			updateVector(h2, h2Sum);
		} else if(h3Sum >= h1Sum && h3Sum >= h2Sum) {
			updateVector(h3, h3Sum);
		}
	}

	return h1Sum;
}

int main() {
	std::vector<int> vec1 = { 3, 2, 1, 1, 1 };
	std::vector<int> vec2 = { 4, 3, 2 };
	std::vector<int> vec3 = { 1, 1, 4, 1 };

	std::cout << equalStacks(vec1, vec2, vec3) << std::endl;

	return 0;
}
