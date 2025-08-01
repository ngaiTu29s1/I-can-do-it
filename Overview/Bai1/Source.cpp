#include <iostream>
#include <fstream>

int main() {
	std::ifstream inFile("input.txt");
	if (!inFile) {
		std::cerr << "Can't open this file\n";
		return 1;
	}
	int n = 0;
	while (inFile >> n) {
		if (n == 42) break;
		std::cout << n << std::endl;
	}
	inFile.close();
	system("pause");
	return 0;
}
