#include <iostream>
#include <fstream>
#include <vector>

int algo(const int& num) {
	if (num == 0) return 0;
	else if (num % 9 == 0) return 9;
	else return num % 9;
}

int main() {
	std::ifstream inFile("input.txt");
	int tc, number;
	inFile >> tc;
	int index = 1;
	while (tc) {
		inFile >> number;
		std::cout << "#" << index << " " << algo(number) << std::endl;
		index++;
		tc--;
	}
	system("pause");
	return 0;
}