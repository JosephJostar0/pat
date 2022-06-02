#include <iostream>
#include <map>
std::map<long long, long long> factor;

int main() {
    long long N, i, num;
    scanf("%lld", &N);
    num = N;
    for (i = 2; i <= N; i++) {
        while (N % i == 0) {
            N /= i;
            factor[i]++;
        }
    }
    if (num == 1)
        factor[num]++;
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
