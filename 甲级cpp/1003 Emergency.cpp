#include <iostream>
#define INF 0Xbadbeef
#define MAXN 500
int N, M, c1, c2, num;
int weight[MAXN], G[MAXN][MAXN], visit[MAXN], dis[MAXN];
int value[MAXN], cnt[MAXN];
void Dij(int root = c1) {
    std::fill(dis, dis + N, INF);
    dis[root] = 0, cnt[root] = 1, value[root] = weight[root];
    for (int i = 0; i < N; i++) {
        int MIN = INF, u;
        for (int j = 0; j < N; j++)
            if (dis[j] < MIN && !visit[j])
                MIN = dis[j], u = j;
        if (MIN == INF)
            break;
        visit[u] = 1;
        for (int v = 0; v < N; v++)
            if (G[u][v] != INF && !visit[v]) {
                if (dis[u] + G[u][v] < dis[v]) {
                    dis[v] = dis[u] + G[u][v];
                    value[v] = weight[v] + value[u];
                    cnt[v] = cnt[u];
                } else if (dis[u] + G[u][v] == dis[v]) {
                    cnt[v] += cnt[u];
                    if (value[v] < weight[v] + value[u])
                        value[v] = weight[v] + value[u];
                }
            }
    }
}

int main() {
    std::fill(G[0], G[0] + MAXN * MAXN, INF);
    scanf("%d%d%d%d", &N, &M, &c1, &c2);
    int i;
    for (i = 0; i < N; i++)
        scanf("%d", weight + i);
    for (i = 0; i < M; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        scanf("%d", &G[p][q]);
        G[q][p] = G[p][q];
    }
    Dij();
    printf("%d %d", cnt[c2], value[c2]);
    return 0;
}
