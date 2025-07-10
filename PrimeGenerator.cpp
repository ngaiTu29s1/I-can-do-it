// 1 <= m <=n <= 1000000000 = 10e9 => long long
// m-n <= 1000000 
// input: dong dau: so luong testcase
// cac dong sau: moi dong 2 so => m va n

#define ll long long

#include <iostream>
#include <vector>
#include <math.h>

bool isPrime(ll a){
    if (a <= 1) return false;
    for (ll i = 2; i < sqrt(a) + 1; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<ll> getPrime(ll n, ll m) {
    std::vector<ll> primes = {};
    for (ll i = n; i <= m; i++) {
        if (isPrime(i)) primes.push_back(i);
    }
    return primes;
}

int main() {
    ll n = 0;
    std::cout << "Number of testcases: ";
    std::cin >> n;
    while (n > 0) {
        ll a = 0, b = 0;
        std::cout << "m = "; std::cin >> a;
        std::cout << "n = "; std::cin >> b;
        std::cout << "Prime numbers in range " 
        << a << " to " << b << " is ";
        std::cout << std::endl;
        std::vector<ll> primes = getPrime(a, b);
        for (ll prime : primes) {
            std::cout << prime << " ";
        }
        std::cout << std::endl;
        std::cout<< "-------------------";
        std::cout << std::endl;
        n--;
    }

    return 0;
}