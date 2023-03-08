#include <algorithm>
#include <iostream>
#include <string>
bool isPrime(long long x) {
    if (x < 2)
        return false;
    for (long long l = 3; l * l <= x; l += 2)
        if (x % l == 0)
            return false;
    return x % 2 == 1 || x == 2;
}

int main() {
    int L, K, i;
    long long ll;
    std::string str, num;
    std::cin >> L >> K >> str;
    for (i = 0; i <= L - K; i++) {
        num = str.substr(i, K);
        ll = std::stoll(num);
        if (isPrime(ll)) {
            std::cout << num << '\n';
            return 0;
        }
    }
    std::cout << "404\n";
    return 0;
}
