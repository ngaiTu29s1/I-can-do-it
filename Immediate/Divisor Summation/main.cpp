//1 <= n <= 500000
// In ra tong cac uoc cua n: Khong tinh n
// VD: 20 co uoc 1, 4, 5, 20 => tong 1 + 4 + 5

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#define ll long long

ll func(ll n) {
    std::vector<ll> divisors = {};
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0){
            divisors.push_back(i);
            if (i*i != n)
                divisors.push_back(int(n/i));
            }
    }
    return std::accumulate(divisors.begin(), divisors.end(), 0ll) - n;
}

int main() {
    ll n = 0;
    std::cout << "Number of testcases: "; std::cin >>n;
    while (n != 0) {
        int a = 0;
        std::cout << "Nhap so n: "; std::cin >> a;
        std::cout << "Tong cac uoc la: " << func(a);
        std::cout<< std::endl << "---------------------" << std::endl;
        n--;
    }
    return 0;
}