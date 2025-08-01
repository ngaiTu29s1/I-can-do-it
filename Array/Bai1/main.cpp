#include <fstream>
#include <iostream>
#include <vector>

int h, w;
int m, n;

void algo(const std::vector<std::vector<char>>& frame, int* res)
{
	for (int winRow = 0; winRow < m; ++winRow) {      
		int top = 1 + winRow * 5;                      

		for (int winCol = 0; winCol < n; ++winCol) {    
			int left = 1 + winCol * 5; 

			int stars = 0;
			for (int r = 0; r < 4; ++r)
				for (int c = 0; c < 4; ++c)
					if (frame[top + r][left + c] == '*')
						++stars;

			res[stars / 4]++;  
		}
	}
}



int main() {
	int res[5] = {0};
	std::vector<std::vector<char>> frame;
	std::ifstream inFile("input.txt");
	int tc;
	inFile >> tc;
	while (tc) {
		inFile >> m >> n;
		h = 5 * m + 1; w = 5 * n + 1;
		frame.resize(h, std::vector<char>(w, '0'));
		// 
		for (auto& row : frame) {
			for (char& ele : row){
				inFile >> ele;
			}
		}

		algo(frame, res);

		tc--;
	}
	inFile.close();
	for (int result : res) {
		std::cout << result;
	}
	system("pause");
}
