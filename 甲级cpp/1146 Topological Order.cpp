#include <iostream>
#include <vector>
#define MAXN 1001
#define MAXM 10001
int N, M, level[MAXN], in[MAXN], K, tag, kill[MAXN];
std::vector<int> out[MAXN];
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        in[v]++;
        out[u].push_back(v);
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int flag = 1, node;
        std::fill(kill, kill + MAXN, 0);
        for (int j = 0; j < N; j++) {
            scanf("%d", &node);
            if (kill[node] != in[node])
                flag = 0;
            for (auto it = out[node].begin(); it != out[node].end(); it++)
                kill[*it]++;
        }
        if (!flag) {
            printf("%s%d", tag ? " " : "", i);
            tag = 1;
        }
    }
    return 0;
}
