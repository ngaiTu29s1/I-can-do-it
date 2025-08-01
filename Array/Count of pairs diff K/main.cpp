#include <iostream>
#include <fstream>

using ll = long long;

int nums[1000] = { 0 };

int main() {
	std::ifstream inFile("input.txt");
	int T, N, K, cnt;
	inFile >> T;
	for (int tc = 0; tc < T; tc++) {
		cnt = 0;
		inFile >> N >> K;
		for (int i = 0; i < N; i++) {
			inFile >> nums[i];
		}
		for (int i = 0; i < N-1; i++) {
			for (int j = i + 1; j < N; j++) {
				if ((nums[j] == nums[i] - K) || (nums[i] == nums[j] - K)) {
					cnt++;
				}
			}
		}
		std::cout << cnt << std::endl;
	}
	return 0;
}