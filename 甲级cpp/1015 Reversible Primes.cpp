#include <iostream>
using namespace std;
bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int N, D, alter;
    while (true) {
        alter = 0;
        cin >> N >> D;
        if (N < 0)
            break;
        if (!isPrime(N)) {
            cout << "No\n";
            continue;
        }
        while (N > 0) {
            alter *= D;
            alter += N % D;
            N /= D;
        }
        if (isPrime(alter))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
