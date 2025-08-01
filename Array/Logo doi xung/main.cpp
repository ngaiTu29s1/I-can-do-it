#include <iostream>
#include <fstream>

int logo[33][33] = { 0 }; // 7: 0 - 6. 1 - 5, 2 - 4

bool algo(int N) {
	int mid = N / 2;
	if (N & 1) {
		for (int i = 1; i <= mid; i++) {
			for (int j = 0; j < N; j++) {
				if (logo[mid - i][j] != logo[mid + i][j]) {
					return false;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= mid; j++) {
				if (logo[i][mid - j] != logo[i][mid + j]) {
					return false;
				}
			}
		}
	}

	else {
		mid -= 1;
		for (int i = 0; i <= mid; i++) {
			for (int j = 0; j < N; j++) {
				if (logo[mid - i][j] != logo[mid + i + 1][j]) {
					return false;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= mid; j++) {
				if (logo[i][j] != logo[i][N-1-j]) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	std::ifstream inFile("input.txt");
	int T, N;
	inFile >> T;
	for (int tc = 1; tc <= T; tc++) {
		inFile >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				inFile >> logo[i][j];
			}
		}

		std::cout << "#" << tc << " " << (algo(N) ? "YES" : "NO") << std::endl;
	}
	return 0;
}