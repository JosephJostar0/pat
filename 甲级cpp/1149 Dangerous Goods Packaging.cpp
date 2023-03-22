#include <iostream>
#include <unordered_map>
#include <vector>
std::unordered_map<int, std::vector<int>> edge;
std::unordered_map<int, int> conflict;
int N, M;
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 0; i < M; i++) {
        int k, flag = 1;
        scanf("%d", &k);
        conflict.clear();
        for (int j = 0; j < k; j++) {
            int id;
            scanf("%d", &id);
            if (flag) {
                if (conflict[id])
                    flag = 0;
                for (auto it = edge[id].begin(); it != edge[id].end(); it++)
                    conflict[(*it)] = 1;
            }
        }
        printf(flag ? "Yes\n" : "No\n");
    }
    return 0;
}
