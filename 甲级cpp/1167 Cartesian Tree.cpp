#include <iostream>
#include <vector>
#define MAXN 30
std::vector<int> v[MAXN];
int N, nodes[MAXN];

void getTop(int left, int right, int step = 0) {
    if (right <= left)
        return;
    int margin = left;
    for (int i = left + 1; i < right; i++)
        if (nodes[margin] > nodes[i])
            margin = i;
    v[step].push_back(nodes[margin]);
    getTop(left, margin, step + 1);
    getTop(margin + 1, right, step + 1);
}

int main() {
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", nodes + i);
    getTop(0, N);
    printf("%d", v[0][0]);
    for (i = 1; i < N; i++)
        for (auto it = v[i].begin(); it != v[i].end(); it++)
            printf(" %d", *it);
    return 0;
}
