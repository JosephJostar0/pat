#include <algorithm>
#include <iostream>
#include <queue>
#define MAXN 100 + 1
class Node {
public:
    int l, r, data;
} nodes[MAXN];
int N, seq[MAXN], rank;

void inOrder(int id = 0) {
    if (id >= 0) {
        inOrder(nodes[id].l);
        nodes[id].data = seq[rank++];
        inOrder(nodes[id].r);
    }
}

void levelOrder(int root = 0) {
    std::queue<int> q;
    q.push(root);
    int temp, flag = 0;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (flag)
            printf(" ");
        printf("%d", nodes[temp].data);
        flag = 1;
        if (nodes[temp].l >= 0)
            q.push(nodes[temp].l);
        if (nodes[temp].r >= 0)
            q.push(nodes[temp].r);
    }
}

int main() {
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++)
        scanf("%d%d", &nodes[i].l, &nodes[i].r);
    for (i = 0; i < N; i++)
        scanf("%d", seq + i);
    std::sort(seq, seq + N);
    inOrder();
    levelOrder();
    return 0;
}
