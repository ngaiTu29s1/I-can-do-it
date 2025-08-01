#include <iostream>
#include <fstream>

int rev(int num) {
	int reved = 0;
	while (num != 0) {
		int temp = num % 10;
		reved *= 10;
		reved += temp;
		num = num / 10;
	}
	return reved;
}

int main() {
	std::ifstream inFile("input.txt");
	int n;
	inFile >> n;
	while (n) {
		int a, b, rSum;
		inFile >> a >> b;
		int rA = rev(a), rB = rev(b);
		rSum = rA + rB;
		std::cout << rev(rSum) << std::endl;
		n--;
	}
	system("pause");
}