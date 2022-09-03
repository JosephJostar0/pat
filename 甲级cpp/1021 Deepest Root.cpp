#include <iostream>
#include <queue>
#include <vector>
#define MAXN 10001
int N, top, visit[MAXN];
std::vector<int> v[MAXN], ans;
void BFS(int root) {
    std::queue<int> q;
    q.push(root);
    visit[root] = 1;
    int cnt = 0, temp, last = root, pre, level = 1;
    while (q.size()) {
        temp = q.front(), q.pop();
        cnt++;
        for (auto it = v[temp].begin(); it != v[temp].end(); it++)
            if (!visit[*it])
                visit[*it] = 1, q.push(*it), pre = *it;
        if (temp == last) {
            level++;
            last = pre;
        }
    }
    if (cnt == N) {
        if (level > top) {
            ans.clear();
            top = level;
            ans.push_back(root);
        } else if (level == top)
            ans.push_back(root);
    }
}

bool isTree() {
    int i;
    for (i = 1; i <= N; i++) {
        std::fill(visit, visit + MAXN, 0);
        BFS(i);
        if (top == 0)
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &N);
    int i;
    for (i = 1; i < N; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        v[p].push_back(q);
        v[q].push_back(p);
    }
    if (!isTree()) {
        int cnt = 1;
        for (i = 1; i <= N; i++)
            if (!visit[i])
                BFS(i), cnt++;
        printf("Error: %d components", cnt);
        return 0;
    }
    for (auto it = ans.begin(); it != ans.end(); it++)
        printf("%d\n", *it);
    return 0;
}
