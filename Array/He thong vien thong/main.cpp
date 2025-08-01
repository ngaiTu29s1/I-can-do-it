#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char map[101][101];
bool covered[101][101];

void cover(int M, int N, int x, int y, int range) {
    // chính giữa
    covered[x][y] = true;
    // 4 hướng
    for (int d = 1; d <= range; d++) {
        if (x - d >= 0) covered[x - d][y] = true;
        if (x + d < M)  covered[x + d][y] = true;
        if (y - d >= 0) covered[x][y - d] = true;
        if (y + d < N)  covered[x][y + d] = true;
    }
}

int main() {
    ifstream inFile("input.txt");
    int T, M, N;
    inFile >> T;
    for (int tc = 1; tc <= T; tc++) {
        inFile >> M >> N;
        memset(covered, 0, sizeof(covered));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                inFile >> map[i][j];

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (map[i][j] == 'A') cover(M, N, i, j, 1);
                else if (map[i][j] == 'B') cover(M, N, i, j, 2);
                else if (map[i][j] == 'C') cover(M, N, i, j, 3);

        int ans = 0;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (map[i][j] == 'H' && !covered[i][j]) ans++;

        cout << "#" << tc << " " << ans << endl;
    }
    return 0;
}