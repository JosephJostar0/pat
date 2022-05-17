#include <iostream>
int main() {
    double    num;
    int       N, i;
    long long ans = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%lf", &num);
        num *= 1000;
        ans += (long long)num * (N - i) * (i + 1);
    }
    printf("%.2f\n", (double)ans / 1000);
    return 0;
}
