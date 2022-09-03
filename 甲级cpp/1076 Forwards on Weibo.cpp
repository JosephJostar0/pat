#include <iostream>
#include <queue>
#include <vector>
#define MAXN 1001
int N, L, visit[MAXN];
std::vector<int> v[MAXN];
int BFS(int id) {
    std::queue<int> q;
    std::fill(visit, visit + MAXN, 0);
    visit[id] = 1;
    q.push(id);
    int cnt = 0, level = 0, last = id, pre, temp;
    while (!q.empty()) {
        temp = q.front(), q.pop(), cnt++;
        for (auto it = v[temp].begin(); it != v[temp].end(); it++)
            if (!visit[*it])
                visit[*it] = 1, q.push(*it), pre = *it;
        if (temp == last) {
            last = pre;
            level++;
            if (level > L)
                break;
        }
    }
    return cnt - 1;
}

int main() {
    scanf("%d%d", &N, &L);
    int K, i, t;
    for (i = 1; i <= N; i++) {
        scanf("%d", &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &t);
            v[t].push_back(i);
        }
    }
    scanf("%d", &K);
    for (i = 0; i < K; i++) {
        scanf("%d", &t);
        printf("%d\n", BFS(t));
    }
    return 0;
}
