#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#define MAXN 2001
class Node {
public:
    int l, r;
};
int N, pre[MAXN], in[MAXN], current, cut, out;
std::unordered_map<int, Node> T;
std::unordered_map<int, int> use;
int getTree(int l = 0, int r = N) {
    if (l >= r)
        return cut;
    int root = pre[current++], margin = l;
    while (margin < r && in[margin] != root)
        margin++;
    int son1 = getTree(l, margin);
    int son2 = getTree(margin + 1, r);
    T[root].l = son1;
    T[root].r = son2;
    return root;
}

void postOrder(int root) {
    if (root != cut) {
        postOrder(T[root].l);
        postOrder(T[root].r);
        if (out)
            printf(" ");
        printf("%d", root);
        out = 1;
    }
}

int getLevel(int root) {
    std::queue<int> q;
    q.push(root);
    int rank = 0, temp, pre, last = root;
    while (q.size()) {
        temp = q.front(), q.pop();
        if (T[temp].l != cut)
            pre = T[temp].l, q.push(pre);
        if (T[temp].r != cut)
            pre = T[temp].r, q.push(pre);
        if (temp == last)
            rank++, last = pre;
    }
    return rank - 1;
}

bool isOne(int root, int rank = 2002) {
    std::queue<int> q;
    q.push(root);
    int level = 0, temp, pre, last = root;
    int cnt = 0, sup;
    while (q.size()) {
        temp = q.front(), q.pop(), cnt++;
        if (T[temp].l != cut)
            pre = T[temp].l, q.push(pre);
        if (T[temp].r != cut)
            pre = T[temp].r, q.push(pre);
        if (temp == last) {
            sup = (int)pow(2, level);
            if (cnt != sup)
                return false;
            level++, cnt = 0, last = pre;
        }
        if (level > rank)
            break;
    }
    return true;
}

bool isTwo(int root) {
    std::queue<int> q;
    q.push(root);
    int level = 0, temp, pre, last = root;
    int my = getLevel(root), tick = 0;
    if (!isOne(root, my - 1))
        return false;
    while (q.size() && level <= my) {
        temp = q.front(), q.pop();
        if (T[temp].l != cut) {
            if (level == my - 1 && tick == 1)
                return false;
            pre = T[temp].l, q.push(pre);
        } else if (level == my - 1)
            tick = 1;

        if (T[temp].r != cut) {
            if (level == my - 1 && tick == 1)
                return false;
            pre = T[temp].r, q.push(pre);
        } else if (level == my - 1)
            tick = 1;
        if (temp == last)
            level++, last = pre;
    }
    return true;
}

bool isThree(int root) {
    int rank = getLevel(root);
    return isOne(root, rank - 1);
}

int main() {
    scanf("%d", &N);
    int i, root;
    for (i = 0; i < N; i++)
        scanf("%d", in + i);
    for (i = 0; i < N; i++)
        scanf("%d", pre + i), use[pre[i]] = 1;
    while (use[cut])
        cut++;
    root = getTree();
    if (isOne(root))
        printf("1\n");
    else if (isTwo(root))
        printf("2\n");
    else if (isThree(root))
        printf("3\n");
    else
        printf("0\n");
    postOrder(root);
    return 0;
}
