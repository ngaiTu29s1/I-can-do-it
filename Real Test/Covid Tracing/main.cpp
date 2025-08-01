#include <iostream>
#include <fstream>


int relate[100][100] = { 0 };
bool germ[100] = { false };
bool isF1[100] = { false };

bool germ1[100] = { false };
bool isF2[100] = { false };


void algo(int N, int M) {
	int f1 = 0, f2 = 0;
	for (int i = 0; i < N; i++) {
		if (!germ[i]) continue;
		for (int j = 0; j < N; j++) {
			if (relate[i][j] == 1 && !germ[j] && !isF1[j]) {	
				f1++;
				germ1[j] = true;
				isF1[j] = true;
			}
			}
		}

	for (int i = 0; i < N; i++) {
		if (!germ1[i]) continue;
		for (int j = 0; j < N; j++) {
			if (relate[i][j] == 1 && !germ1[j] && !isF2[j] && !germ[j]) {
				f2++;
				isF2[j] = true;
			}
		}
	}
	std::cout << f1 << " " << f2 << std::endl;
}


int main() {
	std::ifstream inFile("input.txt");
	int T, N, M, f0;
	inFile >> T;
	for (int tc = 1; tc <= T; tc++) {
		// mapping relate
		inFile >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				inFile >> relate[i][j];
			}
		}
		// mapping germ
		for (int i = 0; i < M; i++) {
			inFile >> f0;
			germ[f0 - 1] = true;
		}



		std::cout << "#" << tc << " "; 
		algo(N, M);

		for (int i = 0; i < 100; i++) {
			germ[i] = false;
			germ1[i] = false;
			isF1[i] = false;
			isF2[i] = false;
		}
	}
	return 0;
}