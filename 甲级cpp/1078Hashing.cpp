#include <cstring>
#include <iostream>
bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return n > 1;
}

int main() {
    int Msize, N, hash[10008], i, num, step;
    scanf("%d%d", &Msize, &N);
    while (!isPrime(Msize))
        Msize++;
    memset(hash, 0, sizeof(int) * Msize);
    for (i = 0, step = 0; i < N; i++, step = 0) {
        scanf("%d", &num);
        if (i)
            printf(" ");
        while (hash[(num + step * step) % Msize] && step < Msize)
            step++;
        if (step == Msize)
            printf("-");
        else
            printf("%d", (num + step * step) % Msize), hash[(num + step * step) % Msize] = 1;
    }
    return 0;
}
