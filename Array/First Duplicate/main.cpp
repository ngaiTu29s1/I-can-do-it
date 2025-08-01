#include <iostream>
#include <fstream>

int nums[100000] = { 0 };
bool exist[100000] = { false };

int algo(int n) {
	
	for (int i = 0; i < n; i++) {
		if (exist[nums[i]] == true) return nums[i];
		else exist[nums[i]] = true;
	}
	return -1;
}

int main() {
	int tc, n, i = 1;
	std::ifstream inFile("input.txt");
	inFile >> tc;
	while (tc) {
		inFile >> n;
		for (int j = 0; j < n; j++) {
			inFile >> nums[j];
		}

		std::cout << "#" << i << " " << algo(n) << std::endl;
		for (int j = 0; j < n; j++) {
			nums[j] = -1;
			exist[j] = false;
		}
		i++;
		tc--;
	}
	return 0;
}