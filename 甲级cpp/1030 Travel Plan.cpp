#include <iostream>
#define MAXN 501
#define INF 0xbadbeef
int N, M, S, D;
int G[MAXN][MAXN], cost[MAXN][MAXN];
int visit[MAXN], dis[MAXN], weight[MAXN], pre[MAXN];
void Dij(int root = S) {
    std::fill(dis, dis + MAXN, INF);
    dis[root] = 0;
    for (int i = 0; i < N; i++) {
        int MIN = INF, u;
        for (int j = 0; j < N; j++)
            if (dis[j] < MIN && !visit[j])
                MIN = dis[j], u = j;
        if (MIN == INF)
            break;
        visit[u] = 1;
        for (int v = 0; v < N; v++)
            if (G[u][v] && !visit[v]) {
                if (G[u][v] + dis[u] < dis[v]) {
                    dis[v] = dis[u] + G[u][v];
                    pre[v] = u;
                    weight[v] = weight[u] + cost[u][v];
                } else if (G[u][v] + dis[u] == dis[v])
                    if (weight[u] + cost[u][v] < weight[v]) {
                        weight[v] = weight[u] + cost[u][v];
                        pre[v] = u;
                    }
            }
    }
}

void DFS(int root = D) {
    if (root == S) {
        printf("%d", root);
        return;
    }
    DFS(pre[root]);
    printf(" %d", root);
}

int main() {
    scanf("%d%d%d%d", &N, &M, &S, &D);
    int i;
    for (i = 0; i < M; i++) {
        int u, v, w, c;
        scanf("%d%d%d%d", &u, &v, &w, &c);
        G[u][v] = G[v][u] = w;
        cost[u][v] = cost[v][u] = c;
    }
    Dij();
    DFS(D);
    printf(" %d %d", dis[D], weight[D]);
    return 0;
}
