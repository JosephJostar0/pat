#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 100000
int  data[MAXN], next[MAXN];
bool cmp(int a, int b) { return data[a] < data[b]; }

int main() {
    int N, add, i;
    scanf("%d%d", &N, &add);
    for (i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        scanf("%d%d", data + x, next + x);
    }
    std::vector<int> v;
    while (add != -1) {
        v.push_back(add);
        add = next[add];
    }
    std::sort(v.begin(), v.end(), cmp);
    if (v.empty()) {
        printf("0 -1");
        return 0;
    }
    printf("%d %05d\n%05d %d ", v.size(), v[0], v[0], data[v[0]]);
    for (i = 1; i < v.size(); i++)
        printf("%05d\n%05d %d ", v[i], v[i], data[v[i]]);
    printf("-1");
    return 0;
}
