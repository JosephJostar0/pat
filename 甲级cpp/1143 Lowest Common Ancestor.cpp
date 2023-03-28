#include <algorithm>
#include <iostream>
#include <unordered_map>
#define MAXN 10001
int M, N, preorder[MAXN], inorder[MAXN], tag, root;
std::unordered_map<int, int> exist, indexs;
std::unordered_map<int, std::pair<int, int>> my_tree;
int make_tree(int l = 0, int r = N) {
    if (l == r)
        return tag;
    int value = preorder[root++];
    int rid = indexs[value];
    int lson = make_tree(l, rid);
    int rson = make_tree(rid + 1, r);
    my_tree[value] = std::make_pair(lson, rson);
    return value;
}

void find_lca(int u, int v) {
    int temp = preorder[0];
    while (u != temp && v != temp) {
        if (u < temp && v < temp)
            temp = my_tree[temp].first;
        else if (u > temp && v > temp)
            temp = my_tree[temp].second;
        else {
            printf("LCA of %d and %d is %d.\n", u, v, temp);
            return;
        }
    }
    printf("%d is an ancestor of %d.\n", temp, temp == u ? v : u);
}

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", preorder + i);
        inorder[i] = preorder[i];
        exist[preorder[i]] = 1;
        while (exist[tag])
            tag++;
    }
    std::sort(inorder, inorder + N);
    for (int i = 0; i < N; i++)
        indexs[inorder[i]] = i;
    make_tree();
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
        find_lca(u, v);
    }
    return 0;
}
