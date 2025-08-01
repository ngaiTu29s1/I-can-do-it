#include <iostream>
#include <fstream>

#define MOD 1000007

void algo(int n) {
	long long sum = 0;
	for (long long x = 1; x <= n; x++) {
		long long div = long long(n / x);
		sum += div*x;
	}
	std::cout << sum % MOD << std::endl;
}

int main() {
	std::ifstream inFile("input.txt");
	int T = 0, n = 0;
	inFile >> T;
	while (T) {
		inFile >> n;
		algo(n);
		T--;
	}
	system("pause");
	return 0;
}