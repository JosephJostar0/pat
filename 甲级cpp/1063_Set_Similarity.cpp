#include <iostream>
#include <set>
#define MAXN 50 + 1
std::set<int> sets[MAXN];
void cmp() {
    int p, q, cnt = 0;
    scanf("%d%d", &p, &q);
    if (sets[q].size() > sets[p].size())
        std::swap(q, p);
    for (auto it = sets[p].begin(); it != sets[p].end(); it++)
        if (sets[q].find(*it) != sets[q].end())
            cnt++;
    printf("%.1f%\n", (double)cnt * 100 / (sets[q].size() + sets[p].size() - cnt));
}

int main() {
    int N, M, K, i, j, t;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &M);
        for (j = 0; j < M; j++) {
            scanf("%d", &t);
            sets[i].insert(t);
        }
    }
    scanf("%d", &K);
    for (t = 0; t < K; t++)
        cmp();
    return 0;
}
