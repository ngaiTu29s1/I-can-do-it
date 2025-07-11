// cho 1 array xap sep lon xon
// hoi co cach nao lay cac so ra, tung so ra mot
// va xep theo thu tu tu be den lon
// tra ve "yes" or  "no"
// link https://codesoeasy.weebly.com/home/street-parade

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

bool possible(std::vector<int> vec) {
    int len = vec.size();
    int need = 1;
    std::stack<int> st;
    for (int i = 0; i < len; i++) {
        if (vec[i] == need) {
            need++;
            while (!st.empty() && st.top() == need) {
                st.pop();
                need++;
            }
        } else {
            st.push(vec[i]);
        }
    }
    while (!st.empty()) {
        if (st.top() == need) {
            st.pop();
            need++;
        } else {
            return false;
        }
    }
    return true;
}


int main() {
    std::cout << possible(std::vector{4, 1, 3, 2}) << std::endl;
    std::cout << possible(std::vector{1, 2, 3, 4, 5}) << std::endl;
    std::cout << possible(std::vector{2, 1, 3, 4, 5}) << std::endl;
    std::cout << possible(std::vector{5, 1, 2, 4, 3}) << std::endl;
    return 0;
}