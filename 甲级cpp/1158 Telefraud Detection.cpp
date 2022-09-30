#include <iostream>
#define MAXN 1001
int G[MAXN][MAXN], dad[MAXN];
int ans[MAXN], num;
int findDad(int x) {
    while (dad[x] != x)
        x = dad[x];
    return x;
}

void makeGroup(int x, int y) {
    int fx = findDad(x), fy = findDad(y);
    if (fx < fy)
        dad[fy] = fx;
    else
        dad[fx] = fy;
}

int main() {
    int K, N, M, i;
    scanf("%d%d%d", &K, &N, &M);
    for (i = 1; i <= 1000; i++)
        dad[i] = i;
    for (i = 0; i < M; i++) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        G[u][v] += t;
    }
    for (i = 1; i <= N; i++) {
        int call = 0, back = 0;
        for (int j = 1; j <= N; j++)
            if (G[i][j] && G[i][j] <= 5) {
                call++;
                if (G[j][i])
                    back++;
            }
        if (call > K && call >= back * 5) {
            for (int j = 0; j < num; j++)
                if (G[i][ans[j]] && G[ans[j]][i])
                    makeGroup(i, ans[j]);
            ans[num++] = i;
        }
    }
    if (!num) {
        printf("None");
        return 0;
    }
    for (i = 0; i < num; i++)
        if (dad[ans[i]] == ans[i]) {
            printf("%d", ans[i]);
            for (int j = i + 1; j < num; j++)
                if (findDad(ans[j]) == ans[i])
                    printf(" %d", ans[j]);
            printf("\n");
        }
    return 0;
}
