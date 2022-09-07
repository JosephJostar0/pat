#include <cstring>
#include <iostream>
#define MAXV 1011
#define INF 0xbadbeef
int N, M, K, Ds, V;
int G[MAXV][MAXV], dis[MAXV], visit[MAXV];
int ansId = -1;
double ansDis = -1, ansAvg = INF;
int getId(char str[]) {
    int i, len = strlen(str), id = 0;
    for (i = 0; i < len; i++)
        if (str[i] != 'G')
            id = id * 10 + (str[i] - '0');
    if (str[0] == 'G')
        return N + id;
    return id;
}

void isAns(int root) {
    double nowDis = INF, nowAvg = 0;
    int i;
    for (i = 1; i <= N; i++) {
        if (dis[i] > Ds)
            break;
        nowAvg += 1.0 * dis[i];
        if (dis[i] < nowDis)
            nowDis = 1.0 * dis[i];
    }
    if (i <= N)
        return;
    nowAvg /= N;
    if (nowDis > ansDis)
        ansId = root, ansDis = nowDis, ansAvg = nowAvg;
    else if (nowDis == ansDis)
        if (nowAvg < ansAvg)
            ansId = root, ansAvg = nowAvg;
}

void Dij(int root) {
    std::fill(dis, dis + MAXV, INF);
    std::fill(visit, visit + MAXV, 0);
    dis[root] = 0;
    for (int i = 1; i <= V; i++) {
        int MIN = INF, u;
        for (int j = 1; j <= V; j++)
            if (dis[j] < MIN && !visit[j])
                MIN = dis[j], u = j;
        if (MIN == INF)
            break;
        visit[u] = 1;
        for (int v = 1; v <= V; v++)
            if (G[u][v] && !visit[v])
                if (dis[v] > G[u][v] + dis[u])
                    dis[v] = G[u][v] + dis[u];
    }
    isAns(root);
}

int main() {
    scanf("%d%d%d%d", &N, &M, &K, &Ds);
    V = N + M;
    int i, w;
    char c1[5], c2[5];
    for (i = 0; i < K; i++) {
        scanf("%s %s %d", c1, c2, &w);
        int id1 = getId(c1);
        int id2 = getId(c2);
        G[id1][id2] = G[id2][id1] = w;
    }
    for (i = N + 1; i <= V; i++)
        Dij(i);
    if (ansId == -1)
        printf("No Solution\n");
    else {
        printf("G%d\n", ansId - N);
        printf("%.1f %.1f", ansDis, ansAvg);
    }
    return 0;
}
