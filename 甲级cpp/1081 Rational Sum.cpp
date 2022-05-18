#include <iostream>
long long gcd(long long a, long long b) {
    long long c = a % b;
    while (c) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main() {
    int       N, i;
    long long son1, son2, mother1, mother2, divided;
    scanf("%d", &N);
    scanf("%lld/%lld", &son1, &mother1);
    for (i = 1; i < N; i++) {
        scanf("%lld/%lld", &son2, &mother2);
        son1 *= mother2;
        son2 *= mother1;
        son1 += son2;
        mother1 *= mother2;
        divided = gcd(son1, mother1);
        son1 /= divided;
        mother1 /= divided;
    }
    son2 = son1 / mother1;
    son1 %= mother1;
    if (son2 && son1)
        printf("%lld %lld/%lld\n", son2, son1, mother1);
    else if (son2)
        printf("%lld\n", son2);
    else if (son1)
        printf("%lld/%lld\n", son1, mother1);
    else
        printf("0\n");
    return 0;
}
