#include <iostream>
#include <fstream>

int mat[100][100] = { 0 };

int go(int start, int N) {
	int r = 0, c = start;
	while (r < N){
		if (mat[r][c] == 1) {
			if (c > 0 && mat[r][c - 1]) {
				while (c > 0 && mat[r][c - 1]) c--;
			}
			else if (c < N - 1 && mat[r][c + 1]) {
				while (c < N - 1 && mat[r][c + 1]) c++;
			}
		}
		r++;
	}
	return c;
}

int main() {
	std::ifstream inFile("input.txt");

	int N, B, M;
	int y, x1, x2;

	for (int tc = 1; tc <= 10; tc++) {
		inFile >> N >> B >> M;
		B--;

		// Reset map
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mat[i][j] = 0;

		for (int i = 0; i < M; i++) {
			inFile >> y >> x1 >> y >> x2;
			y--; x1--; x2--;
			for (int j = x1; j <= x2; j++) {
				mat[y][j] = 1;
			}
		}

		// Mark goal
		mat[N - 1][B] = -1;

		int winner = -1;

		for (int i = 0; i < N; i++) {
			if (mat[0][i] == 1 && mat[N - 1][go(i, N)] == -1) {
				winner = i;
				break;
			}
		}

		std::cout << "#" << tc << " " << winner << std::endl;
	}

	return 0;
}
