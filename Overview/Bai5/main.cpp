#include <iostream>
#include <fstream>
#include <math.h>

bool isPrime(const int& a) {
	if (a == 0 || a == 1) return false;
	bool check = true;
	for (int i = 2; i <= int(sqrt(a)); i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return check;
}

void algo(const int & a, const int& b) {
	for (int i = a; i <= b; i++) {
		if (isPrime(i)) {
			std::cout << i << std::endl;	
		}
	}
}

int main() {
	std::ifstream inFile("input.txt");
	int tc;
	inFile >> tc;
	int a, b;
	while (tc)
	{
		inFile >> a >> b;
		algo(a, b);
		std::cout << std::endl;
		tc--;
	}
	system("pause");
}