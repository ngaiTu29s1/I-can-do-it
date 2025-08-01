#include <iostream>
#include <fstream>
#include <string>

int nums[100000] = { 0 };

// chuyen tung so [x, y] sang dang chuoi => duyet tung ky tu va dem xem co du m so dep khong

bool qualify(std::string s, int m, int n) {
	int cnt = 0;
	for (char ch : s) {
		for (int i = 0; i < n; i++) {
			if ((ch - '0') == nums[i]) {
				cnt++;
			}
		}
	}
	return cnt >= m;
}

int algo(int x, int y, int n, int m) {
	int cnt = 0;
	for (int i = x; i <= y; i++) {
		if (qualify(std::to_string(i), m, n)){
			cnt++;
		}
	}
	return cnt;
}

int main() {
	std::ifstream inFile("input.txt");
	int tc = 0, i = 1, n, m, x, y;
	inFile >> tc;
	while (tc) {
		inFile >> n >> m;
		for (int j = 0; j < n; j++) {
			inFile >> nums[j];
		}
		inFile >> x >> y;
		std::cout << "#" << i << " " << algo(x, y, n, m) << std::endl;
		i++;
		tc--;
	}
	return 0;
}