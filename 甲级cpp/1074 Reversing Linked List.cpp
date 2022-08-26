#include <iostream>
#include <vector>
#define MAXN 100000
int next[MAXN], data[MAXN];
int main() {
    int current, N, K, i, flag = 0;
    scanf("%d%d%d", &current, &N, &K);
    for (i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        scanf("%d%d", data + x, next + x);
    }
    std::vector<int> v;
    while (current != -1) {
        while (current != -1 && v.size() < K)
            v.push_back(current), current = next[current];
        if (v.size() == K)
            for (i = v.size() - 1; i >= 0; i--) {
                if (flag)
                    printf("%05d\n", v[i]);
                printf("%05d %d ", v[i], data[v[i]]);
                flag = 1;
            }
        else
            for (i = 0; i < v.size(); i++) {
                if (flag)
                    printf("%05d\n", v[i]);
                printf("%05d %d ", v[i], data[v[i]]);
                flag = 1;
            }
        v.clear();
    }
    printf("-1");
    return 0;
}
