#include <iostream>
#include <vector>
#define MAXN 501
int N, R, K, M;
int place[MAXN], have[MAXN];
std::vector<std::pair<int, int>> G;
bool check() {
    for (auto it = G.begin(); it != G.end(); it++) {
        int u = (*it).first, v = (*it).second;
        if (place[u] == place[v])
            return false;
    }
    return true;
}

void f() {
    int cnt = 0;
    std::fill(have, have + MAXN, 0);
    for (int i = 1; i <= N; i++) {
        scanf("%d", place + i);
        if (!have[place[i]])
            have[place[i]] = 1, cnt++;
    }
    if (cnt == K) {
        if (check())
            printf("Yes\n");
        else
            printf("No\n");
    } else {
        if (cnt < K)
            printf("Error: Too few species.\n");
        else
            printf("Error: Too many species.\n");
    }
}

int main() {
    scanf("%d%d%d", &N, &R, &K);
    for (int i = 0; i < R; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G.push_back(std::make_pair(u, v));
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        f();
    return 0;
}
