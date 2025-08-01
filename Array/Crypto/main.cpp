#include <iostream>
#include <fstream>

int nums[1000000] = {0};

int ins_nums[100000] = {0};

void insert(int x, int y, int N) {
	for (int i = N - 1; i >= x; i--) {
		nums[i + y] = nums[i];
	}
	for (int i = x; i < x + y; i++) {
		nums[i] = ins_nums[i - x];
	}
}


void remove(int x, int y) {
	for (int i = x; i < x + y; i++) {
		nums[i] = nums[i + y];
	}
}

int main() {
	std::ifstream inFile("input.txt");
	int N, M, x, y, s;
	char cmd;
	for (int tc = 1; tc <= 10; tc++){
		// dong 1 dong 2
		inFile >> N;
		for (int i = 0; i < N; i++) {
			nums[i] = 0;
			inFile >> nums[i];
		}

		// dong 3
		inFile >> M;
		// dong 4
		for (int j = 0; j < M; j++) {
			inFile >> cmd;
			if (cmd == 'I') {
				inFile >> x >> y;
				for (int idx = 0; idx < y; idx++) {
					inFile >> ins_nums[idx];
				}
				insert(x, y, N);
				N += y;
			}

			else if (cmd == 'D') {
				inFile >> x >> y;
				remove(x, y);
				N -= y;
			}
		}

		std::cout << "#" << tc << " ";
		for (int k = 0; k < 10; k++) {
			std::cout << nums[k] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}