#include <iostream>
#include <vector>
#define MAXN 200 + 1
int G[MAXN][MAXN];
int main() {
    int N, M, K, i, j;
    scanf("%d%d", &N, &M);
    for (i = 0; i < M; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x][y] = G[y][x] = 1;
    }
    scanf("%d", &K);
    std::vector<int> v;
    for (i = 1; i <= K; i++) {
        v.clear();
        int num, t, flag = 1, sign[MAXN] = {0};
        scanf("%d", &num);
        for (j = 0; j < num; j++) {
            scanf("%d", &t);
            for (auto it = v.begin(); it != v.end(); it++)
                if (!G[t][*it])
                    flag = 0;
            v.push_back(t), sign[t] = 1;
        }
        if (!flag)
            printf("Area %d needs help.\n", i);
        else {
            for (j = 1; j <= N; j++)
                if (!sign[j]) {
                    std::vector<int>::iterator it;
                    for (it = v.begin(); it != v.end(); it++)
                        if (!G[*it][j])
                            break;
                    if (it == v.end()) {
                        printf("Area %d may invite more people, such as %d.\n", i, j);
                        break;
                    }
                }
            if (j > N)
                printf("Area %d is OK.\n", i);
        }
    }
    return 0;
}
