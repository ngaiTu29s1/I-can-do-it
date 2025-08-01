#include <iostream>
#include <fstream>

void algo(int base, int hat){
	int res = 1;
	while (hat--) {
		res *= base;
	}
	std::cout << res << std::endl;
}

int main() {
	std::ifstream inFile("input.txt");
	int tc = 0, base = 0, hat = 0, i = 1;
	inFile >> tc;
	while (tc--) {
		inFile >> base >> hat;
		std::cout << "#" << i << " ";
		algo(base, hat);
		i++;
	}
	system("pause");
	return 0;
}
