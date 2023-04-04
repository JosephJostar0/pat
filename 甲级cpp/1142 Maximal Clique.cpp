#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 201
int Nv, Ne, G[MAXN][MAXN], M;
std::vector<int> vec, temp, table[MAXN];
int main() {
    scanf("%d%d", &Nv, &Ne);
    for (int i = 0; i < Ne; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = 1;
        table[u].push_back(v), table[v].push_back(u);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int K, flag = 1, u;
        scanf("%d%d", &K, &u);
        vec = table[u];
        for (int j = 1; j < K; j++) {
            scanf("%d", &u);
            if (flag) {
                auto it = std::find(vec.begin(), vec.end(), u);
                if (it == vec.end()) {
                    flag = 0;
                    continue;
                }
                temp = vec;
                vec.clear();
                for (auto node : temp)
                    if (G[node][u])
                        vec.push_back(node);
            }
        }
        if (!flag)
            printf("Not a Clique\n");
        else
            printf("%s\n", vec.empty() ? "Yes" : "Not Maximal");
    }
    return 0;
}
