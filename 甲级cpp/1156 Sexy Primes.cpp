#include <iostream>
int ans;
bool isPrime(int t) {
    for (int i = 3; i * i <= t; i += 2)
        if (t % i == 0)
            return false;
    return t == 2 || (t > 2 && t % 2);
}

bool isOK(int num) {
    if (isPrime(num)) {
        if (isPrime(num - 6)) {
            ans = num - 6;
            return true;
        }
        if (isPrime(num + 6)) {
            ans = num + 6;
            return true;
        }
    }
    return false;
}

int main() {
    int num, temp;
    scanf("%d", &num);
    temp = num;
    while (!isOK(temp))
        temp++;
    printf("%s\n%d", temp == num ? "Yes" : "No", temp == num ? ans : temp);
    return 0;
}
