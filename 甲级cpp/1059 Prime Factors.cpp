#include <iostream>
#include <map>
std::map<long long, long long> factor;

int main() {
    long long N, i, num;
    scanf("%lld", &N);
    num = N;
    for (i = 2; i <= N; i++) {
        while (i < N && N % i == 0) {
            N /= i;
            factor[i]++;
        }
    }
    if (N > 1 || num == 1)
        factor[N]++;
    auto it = factor.begin();
    printf("%lld=%lld", num, it->first);
    if (it->second > 1)
        printf("^%lld", it->second);
    for (it++; it != factor.end(); it++) {
        printf("*%lld", it->first);
        if (it->second > 1)
            printf("^%lld", it->second);
    }
    return 0;
}
