#include <iostream>
#include <queue>
#define MAXP 1000
std::queue<int> q;

int main() {
    int Np, Ng, i, t;
    int weight[MAXP], rank[MAXP];
    scanf("%d%d", &Np, &Ng);
    for (i = 0; i < Np; i++)
        scanf("%d", weight + i);
    for (i = 0; i < Np; i++)
        scanf("%d", &t), q.push(t);
    while (q.size() > 1) {
        int size = q.size();
        int turn = size / Ng + ((size % Ng) ? 1 : 0);
        for (i = 0; i < turn; i++) {
            int big = q.front();
            for (t = 0; t < Ng && t + i * Ng < size; t++, q.pop()) {
                rank[q.front()] = turn + 1;
                if (weight[big] < weight[q.front()])
                    big = q.front();
            }
            q.push(big);
        }
    }
    rank[q.front()] = 1;
    printf("%d", rank[0]);
    for (i = 1; i < Np; i++)
        printf(" %d", rank[i]);
    return 0;
}
