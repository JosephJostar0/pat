#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAXN 201
#define INF 0xbadbeef
int N, K, G[MAXN][MAXN], weight[MAXN], pre[MAXN], route[MAXN];
int visit[MAXN], dis[MAXN], cnt[MAXN], value[MAXN];
string Names[MAXN];
int getIndex(string name) {
    int i;
    for (i = 0; i < N; i++)
        if (Names[i] == name)
            return i;
    return -1;
}

void Dijkstra(int root) {
    fill(visit, visit + N, 0);
    fill(dis, dis + N, INF);
    fill(pre, pre + N, -1);
    dis[root] = 0, value[root] = weight[root], route[root] = 1;
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
                int len = G[u][v] + dis[u];
                int happy = value[u] + weight[v];
                if (len < dis[v]) {
                    dis[v] = len;
                    pre[v] = u;
                    value[v] = happy;
                    cnt[v] = cnt[u] + 1;
                    route[v] = route[u];
                } else if (len == dis[v]) {
                    route[v] += route[u];
                    if (happy > value[v]) {
                        pre[v] = u;
                        value[v] = happy;
                        cnt[v] = cnt[u] + 1;
                    } else if (happy == value[v])
                        if (cnt[v] > cnt[u] + 1) {
                            pre[v] = u;
                            cnt[v] = cnt[u] + 1;
                        }
                }
            }
    }
}

void DFS(int root) {
    if (pre[root] == -1) {
        cout << Names[root];
        return;
    }
    DFS(pre[root]);
    cout << "->" << Names[root];
}

int main() {
    std::ios::sync_with_stdio(false);
    string name, n2, root;
    cin >> N >> K >> root;
    int i, happy;
    Names[0] = root;
    for (i = 1; i < N; i++)
        cin >> Names[i] >> weight[i];
    for (i = 0; i < K; i++) {
        cin >> name >> n2 >> happy;
        int u = getIndex(name);
        int v = getIndex(n2);
        G[u][v] = G[v][u] = happy;
    }
    Dijkstra(getIndex(root));
    int rom = getIndex("ROM");
    cout << route[rom] << ' ' << dis[rom] << ' ' << value[rom] << ' ';
    cout << value[rom] / cnt[rom] << '\n';
    DFS(rom);
    return 0;
}
