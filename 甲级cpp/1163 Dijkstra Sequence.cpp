#include <iostream>
#define MAXN 1001
#define MAXM 100001
#define INF 0xbadbeef
int N, M, seq[MAXN];
int G[MAXN][MAXN], visit[MAXN], dis[MAXN];
bool Dijkstra(int root) {
    std::fill(dis, dis + N + 1, INF);
    std::fill(visit, visit + N + 1, 0);
    dis[root] = 0;
    for (int i = 0; i < N; i++) {
        int u, MIN = INF;
        for (int j = 1; j <= N; j++)
            if (!visit[j] && visit[j] < INF) {
                if (dis[j] < MIN)
                    MIN = dis[j], u = j;
                else if (dis[j] == MIN)
                    if (j == seq[i])
                        u = j;
            }
        if (MIN == INF)
            return false;
        visit[u] = 1;
        if (u != seq[i])
            return false;
        for (int v = 1; v <= N; v++)
            if (!visit[v] && G[u][v])
                if (dis[v] > dis[u] + G[u][v])
                    dis[v] = dis[u] + G[u][v];
    }
    return true;
}

int main() {
    int i, j, K;
    scanf("%d%d", &N, &M);
    for (i = 0; i < M; i++) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        G[u][v] = G[v][u] = t;
    }
    scanf("%d", &K);
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++)
            scanf("%d", seq + j);
        if (Dijkstra(seq[0]))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
