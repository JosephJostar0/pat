#include <stdio.h>
#include <string.h>
#define MAXN 1002
int dp[MAXN][MAXN]; // dp记录的信息是,从i到j是否是回文串
int main() {
    char s[MAXN];
    gets(s);
    int i, j, size = strlen(s), ans = 1;
    for (i = 0; s[i]; i++) {
        dp[i][i] = 1;
        if (s[i] == s[i + 1])
            dp[i][i + 1] = 1, ans = 2;
    }
    for (i = 2; i < size; i++)
        for (j = 0; j < size - i; j++)
            if (s[j] == s[j + i])
                if (dp[j + 1][j + i - 1])
                    dp[j][j + i] = 1, ans = i + 1;
    printf("%d", ans);
    return 0;
}
