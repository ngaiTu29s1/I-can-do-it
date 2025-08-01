#include <iostream>
#include <cmath>

void findPerfectSquares(int a, int b, int index) {
	int start = std::ceil(std::sqrt(a));
	int end = std::floor(std::sqrt(b));
	std::cout << "#" << index << " ";

	if (start > end) {
		std::cout << "NO NUMBER";
	}
	else {
		for (int i = start; i <= end; ++i) {
			std::cout << i * i << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		int a, b;
		std::cin >> a >> b;
		findPerfectSquares(a, b, i);
	}
	return 0;
}
