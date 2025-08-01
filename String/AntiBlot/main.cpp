#include <iostream>
#include <fstream>
#include <string>

bool pureNumber(const std::string& s) {
	if (s.empty()) { // Xử lý trường hợp chuỗi rỗng
		return false;
	}
	for (const char& ch : s) {
		if (!isdigit(ch)) { // Sử dụng isdigit() để kiểm tra ký tự số
			return false;
		}
	}
	return true;
}

int main() {
	std::string str;
	std::ifstream infile("input.txt");
	int n; infile >> n;
	
	while (n) {
		std::string list[6];
		for (int i = 0; i < 5; i++) {
			infile >> list[i];
		}
		int n1, n2, n3;
		if (!pureNumber(list[0])) {
			n2 = stoi(list[2]); n3 = stoi(list[4]);
			std::cout << n3 - n2 << " + " << n2 << " = " << n3 << std::endl;
		}
		else if (!pureNumber(list[2])) {
			n1 = stoi(list[0]); n3 = stoi(list[4]);
			std::cout << n1 << " + " << n3 - n1 << " = " << n3 << std::endl;
		}
		else if (!pureNumber(list[4])) {
			n1 = stoi(list[0]); n2 = stoi(list[2]);
			std::cout << n1 << " + " << n2 << " = " << n1 + n2 << std::endl;
		}
		n--;
		
	}
	system("pause");
	return 0;
}