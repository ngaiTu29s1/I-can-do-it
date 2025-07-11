#include <iostream>
#include <vector>
#include <string>

std::string decode(std::string coded, int col) {
    int row = coded.length()/col;
    std::vector<std::vector<char>> mat(row, std::vector<char>(col, 'a'));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            const char ch = coded[i*col + j];
            if ((i & 1) == 0) {
                mat[i][j] = ch;
            }
            else mat[i][col - j - 1] = ch;
        }
    }
    std::string res = "";
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            res += mat[j][i];
        }
    }
    return res;
}

int main() {
    std::cout << decode("toioynnkpheleaigshareconhtomesnlewx", 5) << std::endl << "Hello";
}