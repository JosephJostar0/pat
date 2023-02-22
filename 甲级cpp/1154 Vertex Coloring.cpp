#include <iostream>
#include <unordered_set>
#include <vector>
#define MAXN 10001
int N, M, K, color[MAXN];
std::vector<int> G[MAXN];
std::unordered_set<int> set;
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        bool flag = true;
        for (int j = 0; j < N; j++) {
            scanf("%d", color + j);
            set.insert(color[j]);
        }
        for (int j = 0; flag && j < N; j++)
            for (auto it = G[j].begin(); it != G[j].end(); it++)
                if (color[j] == color[*it]) {
                    flag = false;
                    break;
                }
        if (flag)
            printf("%d-coloring\n", set.size());
        else
            printf("No\n");
        set.clear();
    }
    return 0;
}
