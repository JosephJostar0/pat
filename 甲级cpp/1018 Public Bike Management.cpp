#include <algorithm>
#include <iostream>
#include <vector>
#define INF 0Xbadbeef
#define MAXN 501
int Cmax, N, Sp, M, perfect;
int nums[MAXN], G[MAXN][MAXN], visit[MAXN];
int dis[MAXN], take[MAXN];
std::vector<int> pre[MAXN], temp;
class Ans {
public:
    std::vector<int> path;
    int take, back;
    void getValue() {
        path = temp;
        std::reverse(path.begin(), path.end());
        int low = 0, current = 0, need;
        for (auto it = path.begin() + 1; it != path.end(); it++) {
            need = nums[*it] - perfect;
            current += need;
            if (current < 0) {
                low += current;
                current = 0;
            }
        }
        take = -low;
        back = current;
    }
} ans;
std::vector<Ans> v;

void DFS(int root = Sp) {
    if (root == 0) {
        temp.push_back(0);
        ans.getValue();
        v.push_back(ans);
        temp.pop_back();
        return;
    }
    temp.push_back(root);
    for (auto it = pre[root].begin(); it != pre[root].end(); it++)
        DFS(*it);
    temp.pop_back();
}

void Dij(int root = 0) {
    std::fill(dis, dis + MAXN, INF);
    dis[root] = 0;
    for (int i = 0; i <= N; i++) {
        int MIN = INF, u;
        for (int j = 0; j <= N; j++)
            if (dis[j] < MIN && !visit[j])
                MIN = dis[j], u = j;
        if (MIN == INF)
            break;
        visit[u] = 1;
        for (int v = 0; v <= N; v++)
            if (G[u][v] && !visit[v]) {
                if (G[u][v] + dis[u] < dis[v]) {
                    dis[v] = G[u][v] + dis[u];
                    pre[v].clear(), pre[v].push_back(u);
                } else if (G[u][v] + dis[u] == dis[v])
                    pre[v].push_back(u);
            }
    }
}

bool cmp(Ans a, Ans b) {
    if (a.take != b.take)
        return a.take < b.take;
    return a.back < b.back;
}

int main() {
    scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
    perfect = Cmax / 2;
    int i;
    for (i = 1; i <= N; i++)
        scanf("%d", nums + i);
    for (i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        G[x][y] = G[y][x] = z;
    }
    Dij();
    DFS();
    std::sort(v.begin(), v.end(), cmp);
    printf("%d 0", v[0].take);
    for (i = 1; i < v[0].path.size(); i++)
        printf("->%d", v[0].path[i]);
    printf(" %d", v[0].back);
    return 0;
}
