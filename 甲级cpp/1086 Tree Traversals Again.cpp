#include <cstring>
#include <iostream>
#include <stack>
#define MAXN 30 + 1
int isSon[MAXN], flag = 0;
class Node {
public:
    int childs[2], size;
    Node() { size = 0, std::fill(childs, childs + 2, 0); }
    void getSon(int son) { childs[size] = son, isSon[son] = 1; }
} nodes[MAXN];
std::stack<int> s;

void postOrder(int dad) {
    if (dad) {
        postOrder(nodes[dad].childs[0]);
        postOrder(nodes[dad].childs[1]);
        if (flag)
            printf(" ");
        printf("%d", dad);
        flag = 1;
    }
}

int main() {
    int  N, current, pre = 0, i;
    char how[8];
    scanf("%d", &N);
    for (i = 0; i < 2 * N; i++) {
        scanf("%s", how);
        if (strcmp(how, "Push") == 0) {
            scanf("%d", &current);
            s.push(current);
            if (pre)
                nodes[pre].getSon(current);
            pre = current;
        } else {
            pre = s.top();
            s.pop();
            nodes[pre].size = 1;
        }
    }
    for (i = 1; i < MAXN; i++)
        if (!isSon[i])
            break;
    postOrder(i);
    return 0;
}
