#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 1001
int N, dad[MAXN], hob[1001];
std::vector<int> v;
bool cmp(int x, int y) { return dad[x] < dad[y]; }

int findDad(int x) {
    int temp = x;
    while (dad[x] >= 0)
        x = dad[x];
    while (temp != x) {
        int step = dad[temp];
        dad[temp] = x;
        temp = step;
    }
    return x;
}

void Union(int x, int y) {
    int xdad = findDad(x);
    int ydad = findDad(y);
    if (xdad != ydad) {
        dad[ydad] += dad[xdad];
        dad[xdad] = ydad;
    }
}

int main() {
    scanf("%d", &N);
    std::fill(dad, dad + N + 1, -1);
    int k, h, i, j, ans = 0;
    for (i = 1; i <= N; i++) {
        scanf("%d:", &k);
        for (j = 0; j < k; j++) {
            scanf("%d", &h);
            if (!hob[h])
                hob[h] = i;
            else
                Union(i, hob[h]);
        }
    }
    for (i = 1; i <= N; i++)
        if (dad[i] < 0)
            v.push_back(i);
    std::sort(v.begin(), v.end(), cmp);
    printf("%d\n%d", v.size(), -dad[v[0]]);
    for (i = 1; i < v.size(); i++)
        printf(" %d", -dad[v[i]]);
    return 0;
}
