#include <iostream>
#include <unordered_map>
#define MAXN 10001
int M, N, order[MAXN];
std::unordered_map<int, int> exist;
int main() {
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", order + i);
        exist[order[i]] = 1;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (!exist[u] || !exist[v]) {
            if (exist[u] == exist[v])
                printf("ERROR: %d and %d are not found.\n", u, v);
            else
                printf("ERROR: %d is not found.\n", exist[u] ? v : u);
            continue;
        }
        for (int j = 0; j < N; j++)
            if ((order[j] >= u && order[j] <= v) || (order[j] <= u && order[j] >= v)) {
                if (order[j] == u || order[j] == v)
                    printf("%d is an ancestor of %d.\n", order[j], order[j] == u ? v : u);
                else
                    printf("LCA of %d and %d is %d.\n", u, v, order[j]);
                break;
            }
    }
    return 0;
}
