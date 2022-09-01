#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define MAXN 1000 + 1
int arr[MAXN], son[MAXN][2];
int findRoot(int l, int r) {
    if (l >= r)
        return -1;
    int num = r - l, level = 1;
    while ((int)pow(2, level) - 1 < num)
        level++;
    int more = num - (int)pow(2, level - 1) + 1;
    int left_take = (int)pow(2, level - 2);
    int more_r = std::max(0, more - left_take);
    int root = r - more_r - (int)pow(2, level - 2);
    son[root][0] = findRoot(l, root);
    son[root][1] = findRoot(root + 1, r);
    return root;
}

void levelOrder(int id) {
    std::queue<int> q;
    q.push(id);
    int flag = 0;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < 2; i++)
            if (son[temp][i] >= 0)
                q.push(son[temp][i]);
        if (flag)
            printf(" ");
        printf("%d", arr[temp]);
        flag = 1;
    }
}

int main() {
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", arr + i);
    std::sort(arr, arr + N);
    levelOrder(findRoot(0, N));
    return 0;
}
