#include <iostream>
#include <fstream>
#include <math.h>


int main() {
	std::ifstream inFile("input.txt");
	int n;
	inFile >> n;
	int index = 1;
	int num;
	while (n) {
		inFile >> num;
		std::cout << "#" << index << " " << int(sqrt(num))<< std::endl;
		index++;
		n--;
	}
	system("pause");
	return 0;
}