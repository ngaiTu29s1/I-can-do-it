#include <iostream>
#include <fstream>

int weights[100] = { 0 };

//bubble sort

// 0, 1 -> 1 ::::::::  2, 3 -> 2 :::: 4, 5 -> 3  :: 6, 7 - > 4 :: 8 -> 5

void bbs(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (weights[i] < weights[j]) {
				int temp = weights[i];
				weights[i] = weights[j];
				weights[j] = temp;
			}
		}
	}
}

int algo(int m1, int m2, int n) {
	int price = 0;
	int floor = 1;
	int i = 0;

	while (i < n && (m1 > 0 || m2 > 0)) {
		if (i + 1 < n && m1 > 0 && m2 > 0) {
			price += (weights[i] + weights[i + 1]) * floor;
			i += 2;
			m1--;
			m2--;
		}
		else if (m1 > 0) {
			price += weights[i] * floor;
			i++;
			m1--;
		}
		else if (m2 > 0) {
			price += weights[i] * floor;
			i++;
			m2--;
		}
		floor++;
	}
	return price;
}


int main() {
	std::ifstream inFile("input.txt");
	int tc, i = 1, n, m1, m2;
	inFile >> tc;
	while (tc) {
		inFile >> n >> m1 >> m2;
		for (int j = 0; j < n; j++) {
			inFile >> weights[j];
		}
		bbs(n);
		std::cout << "#" << i << " " << algo(m1, m2, n) << std::endl;

		for (int j = 0; j < n; j++) {
			weights[j] = 0;
		}
		tc--; i++;
	}

	return 0;
}