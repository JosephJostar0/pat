#include <iostream>
#include <queue>
#define MAXN 10
class Node {
public:
    int childs[2];
    Node() { std::fill(childs, childs + 2, -1); }
} nodes[MAXN];
int  N, isSon[MAXN], flag;
void levelOrder(int root) {
    std::queue<int> q;
    q.push(root);
    while (q.size()) {
        int current = q.front();
        q.pop();
        for (int i = 1; i >= 0; i--)
            if (nodes[current].childs[i] >= 0)
                q.push(nodes[current].childs[i]);
        if (flag)
            printf(" ");
        printf("%d", current);
        flag = 1;
    }
    printf("\n");
}

void postOrder(int root) {
    if (root >= 0) {
        postOrder(nodes[root].childs[1]);
        if (!flag)
            printf(" ");
        printf("%d", root);
        flag = 0;
        postOrder(nodes[root].childs[0]);
    }
}

int main() {
    scanf("%d\n", &N);
    char c[2];
    int  i, temp;
    for (i = 0; i < N; i++) {
        scanf("%c %c\n", c, c + 1);
        for (int j = 0; j < 2; j++)
            if (c[j] != '-') {
                temp               = c[j] - '0';
                nodes[i].childs[j] = temp;
                isSon[temp]        = 1;
            }
    }
    for (i = 0; i < N; i++)
        if (!isSon[i])
            break;
    levelOrder(i);
    postOrder(i);
    return 0;
}
