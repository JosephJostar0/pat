#include <algorithm>
#include <iostream>
#include <vector>
#define MAXM 102
#define MAXN 10002
std::vector<int> v;
int dp[MAXN][MAXM], take[MAXN][MAXM];
int DP(int n, int m) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int temp = 0;
            if (j >= v[i])
                temp = dp[i - 1][j - v[i]] + v[i];
            if (dp[i - 1][j] > temp)
                dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = temp;
                take[i][j] = 1;
            }
        }
    return dp[n][m];
}

void outAns(int n, int m) {
    std::vector<int> out;
    while (m) {
        while (!take[n][m])
            n--;
        out.push_back(v[n]);
        m -= v[n], n--;
    }
    printf("%d", out[0]);
    for (int i = 1; i < out.size(); i++)
        printf(" %d", out[i]);
}

int main() {
    int N, M, i;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        if (t <= M)
            v.push_back(t);
    }
    std::sort(v.begin(), v.end(), std::greater<int>());
    v.insert(v.begin(), 0);

    int ans = DP(v.size() - 1, M);
    if (ans != M)
        printf("No Solution");
    else
        outAns(v.size() - 1, M);
    return 0;
}
