#include <iostream>
#include <fstream>



int pw[8] = {0};// pw chuan
int pwt[8] = { 0 };

int algo(int N) {
	int res = -1;
	int wrong = 0;

	for (int i = 0; i < N; i++) {
		if (pw[i] == pwt[i]) continue;

		wrong++;
		if (wrong > 1) return -1;

		int correct = pw[i];
		int typed = pwt[i];

		if (correct == 1) {
			if (typed != 2 && typed != 4) return -1;
		}
		else if (correct == 2) {
			if (typed != 1 && typed != 3 && typed != 5) return -1;
		}
		else if (correct == 3) {
			if (typed != 2 && typed != 6) return -1;
		}
		else if (correct == 4) {
			if (typed != 1 && typed != 5 && typed != 7) return -1;
		}
		else if (correct == 5) {
			if (typed != 2 && typed != 4 && typed != 6 && typed != 8) return -1;
		}
		else if (correct == 6) {
			if (typed != 3 && typed != 5 && typed != 9) return -1;
		}
		else if (correct == 7) {
			if (typed != 4 && typed != 8) return -1;
		}
		else if (correct == 8) {
			if (typed != 5 && typed != 7 && typed != 9 && typed != 0) return -1;
		}
		else if (correct == 9) {
			if (typed != 6 && typed != 8) return -1;
		}
		else if (correct == 0) {
			if (typed != 8) return -1;
		}
		else {
			return -1;
		}

		res = i;
	}

	return res + 1;
}


int main() {
	int tc, N;
	std::cin >> tc;
	for (int i = 1; i <= tc; i++) {
		std::cin >> N;
		for (int j = 0; j < N; j++) {
			std::cin >> pw[j];
		}
		for (int j = 0; j < N; j++) {
			std::cin >> pwt[j];
		}
		std::cout << "#" << i << " " << algo(N) << std::endl;
	}

	return 0;
}