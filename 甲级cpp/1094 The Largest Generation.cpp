#include <iostream>
#include <queue>
#include <vector>
#define MAXN 100
std::vector<int> v[MAXN];
int isSon[MAXN], rankNum[MAXN], rank = 1, top;
void levelOrder(int root) {
    std::queue<int> q;
    q.push(root);
    int temp, last = root, pre, i;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        rankNum[rank]++;
        if (rankNum[top] < rankNum[rank])
            top = rank;
        for (i = 0; i < v[temp].size(); i++) {
            pre = v[temp][i];
            q.push(pre);
        }
        if (temp == last) {
            last = pre;
            rank++;
        }
    }
}

int main() {
    int N, M, i;
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++) {
        int temp, num, son;
        scanf("%d%d", &temp, &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &son);
            v[temp].push_back(son);
            isSon[son] = 1;
        }
    }
    for (i = 1; i <= N; i++)
        if (!isSon[i])
            break;
    levelOrder(i);
    printf("%d %d", rankNum[top], top);
    return 0;
}
