#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> v[11], pre;
int have[100001], lose[11], cnt;
bool check(int num) {
    if (have[num])
        return false;
    for (auto it = pre.begin(); it != pre.end(); it++)
        if ((*it) + num <= 100000)
            if (have[(*it) + num])
                return true;
    return false;
}

int main() {
    int n1, n2, M, N, num;
    scanf("%d%d%d%d", &n1, &n2, &N, &M);
    have[n1] = have[n2] = 1;
    pre.push_back(n1);
    pre.push_back(n2);
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++) {
            scanf("%d", &num);
            v[i].push_back(num);
        }
    for (int j = 0; j < M; j++) {
        for (int i = 1; i <= N; i++) {
            if (lose[i])
                continue;
            num = v[i][j];
            if (!check(num)) {
                lose[i] = 1, cnt++;
                printf("Round #%d: %d is out.\n", j + 1, i);
            } else
                pre.push_back(num), have[num] = 1;
        }
    }

    if (cnt == N)
        printf("No winner.\n");
    else {
        printf("Winner(s):");
        for (int i = 1; i <= N; i++)
            if (!lose[i])
                printf(" %d", i);
    }
    return 0;
}
