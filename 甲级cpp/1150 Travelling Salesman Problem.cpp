#include <iostream>
#define MAXN 201
#define INF 0xbadbeef
int N, M, K, n, id = 0, cost = INF;
int G[MAXN][MAXN], path[MAXN * MAXN], visit[MAXN];
void f(int turn) {
    int dis = 0, is_simple = 1, is_ts = 1;
    std::fill(visit, visit + MAXN, 0);
    printf("Path %d: ", turn);
    for (int i = 0; i < n - 1; i++) {
        int u = path[i], v = path[i + 1];
        if (G[u][v]) {
            dis += G[u][v];
            if (visit[v])
                is_simple = 0;
            visit[v] = 1;
        } else {
            printf("NA (Not a TS cycle)\n");
            return;
        }
    }
    for (int i = 1; i <= N; i++)
        if (!visit[i]) {
            is_ts = 0;
            break;
        }
    printf("%d ", dis);
    if (is_ts) {
        if (is_simple)
            printf("(TS simple cycle)\n");
        else
            printf("(TS cycle)\n");
        if (dis < cost)
            cost = dis, id = turn;
    } else
        printf("(Not a TS cycle)\n");
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        G[u][v] = G[v][u] = dis;
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
            scanf("%d", path + j);
        f(i + 1);
    }
    printf("Shortest Dist(%d) = %d\n", id, cost);
    return 0;
}
