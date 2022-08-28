#include <iostream>
#include <vector>
#define MAXN 30
std::vector<int> v[MAXN];

int  in[MAXN], post[MAXN], N, temp;
void getLevel(int l = 0, int r = N, int level = 0) {
    if (l >= r)
        return;
    int margin;
    for (margin = l; margin < r; margin++)
        if (in[margin] == post[temp])
            break;
    v[level].push_back(post[temp--]);
    getLevel(margin + 1, r, level + 1);
    getLevel(l, margin, level + 1);
}

int main() {
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++)
        scanf("%d", post + i);
    for (i = 0; i < N; i++)
        scanf("%d", in + i);
    temp = N - 1;
    getLevel();
    printf("%d", v[0][0]);
    for (int j = 1; j < 30; j++)
        if (v[j].size())
            for (i = v[j].size() - 1; i >= 0; i--)
                printf(" %d", v[j][i]);
    return 0;
}
