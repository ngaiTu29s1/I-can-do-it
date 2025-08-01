#include <iostream>
#include <fstream>


void find(const int &n, const int &a, const int &b){
	for (int i = 1; i < n; i++){
		if ((i%a == 0) && (i%b != 0)) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	std::ifstream inFile("input.txt");
	int tc;
	inFile >> tc;
	while (tc){
		int n, a, b;
		inFile >> n >> a >> b;
		find(n, a, b);
		tc--;
	}
	system("pause");
	return 0;
}