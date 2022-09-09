#include <iostream>
#define MAXK 10003
int dp[MAXK], l[MAXK];
int main() {
    int K, arr[MAXK], i, top = 1;
    scanf("%d", &K);
    for (i = 1; i <= K; i++) {
        scanf("%d", arr + i);
        l[i] = i, dp[i] = arr[i];
        if (dp[i - 1] > 0)
            dp[i] += dp[i - 1], l[i] = l[i - 1];
        if (dp[top] < dp[i])
            top = i;
    }
    if (dp[top] >= 0)
        printf("%d %d %d", dp[top], arr[l[top]], arr[top]);
    else
        printf("%d %d %d", 0, arr[1], arr[K]);
    return 0;
}
