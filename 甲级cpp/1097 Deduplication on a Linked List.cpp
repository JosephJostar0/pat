#include <iostream>
#include <vector>
#define MAXN 100000
#define MAXK 10000 + 1
int data[MAXN], next[MAXN], cnt[MAXK];
int main() {
    int add, N, i, j;
    scanf("%d%d", &add, &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &j);
        scanf("%d%d", data + j, next + j);
    }
    std::vector<int> v[2];
    while (add != -1) {
        int temp = abs(data[add]);
        if (cnt[temp])
            v[1].push_back(add);
        else
            cnt[temp] = 1, v[0].push_back(add);
        add = next[add];
    }
    for (j = 0; j < 2; j++) {
        if (v[j].empty())
            continue;
        printf("%05d %d ", v[j][0], data[v[j][0]]);
        for (i = 1; i < v[j].size(); i++)
            printf("%05d\n%05d %d ", v[j][i], v[j][i], data[v[j][i]]);
        printf("-1\n");
    }
    return 0;
}
