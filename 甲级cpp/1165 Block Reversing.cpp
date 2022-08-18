#include <iostream>
#include <stack>
#include <vector>
#define MAXN 1000000
class Node {
public:
    int data, next;
} nodes[MAXN];
int main() {
    int temp, N, K, i, flag = 0;
    std::vector<int> v;
    std::stack<std::vector<int>> s;
    scanf("%d%d%d", &temp, &N, &K);
    for (i = 0; i < N; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        nodes[x].data = y;
        nodes[x].next = z;
    }
    while (temp != -1) {
        v.push_back(temp);
        temp = nodes[temp].next;
        if (v.size() == K)
            s.push(v), v.clear();
    }
    s.push(v);
    while (!s.empty()) {
        v = s.top();
        s.pop();
        for (i = 0; i < v.size(); i++) {
            if (flag)
                printf("%05d\n", v[i]);
            printf("%05d %d ", v[i], nodes[v[i]].data);
            flag = 1;
        }
    }
    printf("-1");
    return 0;
}
