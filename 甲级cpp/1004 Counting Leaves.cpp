#include <iostream>
#include <queue>
#include <vector>
#define MAXN 100
int N, M;
std::vector<int> v[MAXN];
void levelOrder(int root = 1) {
    std::queue<int> q;
    int temp, cnt = 0, level = 0, pre, last = root, i;
    q.push(root);
    while (q.size()) {
        temp = q.front();
        q.pop();
        for (i = 0; i < v[temp].size(); i++)
            q.push(v[temp][i]), pre = v[temp][i];
        if (i == 0)
            cnt++;
        if (temp == last) {
            if (level)
                printf(" ");
            printf("%d", cnt);
            last = pre;
            cnt = 0;
            level++;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    int i;
    for (i = 0; i < M; i++) {
        int id, k, son;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &son);
            v[id].push_back(son);
        }
    }
    levelOrder();
    return 0;
}
