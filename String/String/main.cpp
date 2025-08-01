#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void TonFro(std::string str, int n) {
	int cols = n, rows = str.length() / cols;
	std::vector < std::vector <char>> vec;
	vec.resize(rows);
	for (auto& v : vec) {
		v.resize(cols);
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			char ch = str[i*cols + j];
			if (i & 1) {
				vec[i][cols - j - 1] = ch;
			}
			else {
				vec[i][j] = ch;
			}
		}
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << vec[j][i];
		}
	}
	std::cout << std::endl;
}


int main() {
	std::ifstream inFile("input.txt");
	int n;
	std::string str = {};
	while (inFile >> n) {
		if (n == 0) {
			break;
		}
		inFile >> str;
		TonFro(str, n);
	}
	system("pause");
	return 0;
}