#include <iostream>
#define MAXN 202
#define MAXL 10001
int fav[MAXN], seq[MAXL];
int dp[MAXN][MAXL];
int main() {
    int N, M, L, i, j;
    scanf("%d%d", &N, &M);
    for (i = 1; i <= M; i++)
        scanf("%d", fav + i);
    scanf("%d", &L);
    for (i = 1; i <= L; i++)
        scanf("%d", seq + i);
    for (i = 1; i <= M; i++)
        for (j = 1; j <= L; j++) {
            int top = std::max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = std::max(top, dp[i - 1][j - 1]);
            if (fav[i] == seq[j])
                dp[i][j]++;
        }
    printf("%d", dp[M][L]);
    return 0;
}
