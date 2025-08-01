#include <iostream>
#include <fstream>
#include <math.h>

void print(int low, int high) {
	for (int i = low; i <= high; i++) {
		if ((int(sqrt(i)) * int(sqrt(i))) == i) {
			std::cout << i << " ";
		}
	}
}


int main() {
	std::ifstream inFile("input.txt");
	int n;
	inFile >> n;
	int a, b;
	int index = 1;
	while (n) {
		inFile >> a >> b;
		std::cout << "#" << index << " "; print(a, b);
		if (int(sqrt(a)) == int(sqrt(b))) {
			std::cout << "NO NUMBER" << std::endl;
			break;
		}
		std::cout << std::endl;
		index++;
		n--;
	}
	system("pause");
	return 0;
}