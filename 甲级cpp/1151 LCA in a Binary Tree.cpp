#include <iostream>
#include <unordered_map>
#include <vector>
#define MAXN 10001
int N, M, pre[MAXN], in[MAXN], temp, root, tag;
std::unordered_map<int, int> map, alter;
std::unordered_map<int, std::pair<int, int>> tree;
int getRoot(int l, int r) {
    if (l > r)
        return tag;
    int current = pre[temp++], index = -1;
    for (index = l; index <= r; index++)
        if (in[index] == current)
            break;
    int left = getRoot(l, index - 1);
    int right = getRoot(index + 1, r);
    tree[current] = std::make_pair(left, right);
    alter[current] = index;
    return current;
}

void getAns(int u, int v) {
    int ans = root;
    while (ans != u && ans != v) {
        int uid = alter[u], vid = alter[v], ansid = alter[ans];
        if (uid < ansid && vid < ansid)
            ans = tree[ans].first;
        else if (uid > ansid && vid > ansid)
            ans = tree[ans].second;
        else {
            printf("LCA of %d and %d is %d.\n", u, v, ans);
            return;
        }
    }
    printf("%d is an ancestor of %d.\n", ans, ans == u ? v : u);
}

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; i++)
        scanf("%d", in + i);
    for (int i = 0; i < N; i++) {
        scanf("%d", pre + i);
        map[pre[i]] = 1;
    }
    while (map[tag])
        tag++;
    root = getRoot(0, N - 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (!map[u] || !map[v]) {
            if (map[u] == map[v])
                printf("ERROR: %d and %d are not found.\n", u, v);
            else
                printf("ERROR: %d is not found.\n", map[u] ? v : u);
            continue;
        }
        getAns(u, v);
    }
    return 0;
}
