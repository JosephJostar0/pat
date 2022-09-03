#include <iostream>
#define MAXN 1000
int N, M, K, visit[MAXN], G[MAXN][MAXN];
void DFS(int id) {
    visit[id] = 1;
    for (int i = 1; i <= N; i++)
        if (G[id][i] && !visit[i])
            DFS(i);
}

int fix(int broke) {
    std::fill(visit, visit + MAXN, 0);
    visit[broke] = 1;
    int core = 0, i;
    for (i = 1; i <= N; i++)
        if (!visit[i]) {
            core++;
            DFS(i);
        }
    return core - 1;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    int i;
    for (i = 0; i < M; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        G[p][q] = G[q][p] = 1;
    }
    for (i = 0; i < K; i++) {
        int broke;
        scanf("%d", &broke);
        printf("%d\n", fix(broke));
    }
    return 0;
}
