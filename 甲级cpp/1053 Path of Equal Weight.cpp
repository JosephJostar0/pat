#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 100 + 1
std::vector<int> v[MAXN], temp;
std::vector<std::vector<int>> ans;
int N, M, S, weight[MAXN];
void DFS(int id = 0, int sum = 0) {
    if (sum > S)
        return;
    temp.push_back(weight[id]);
    sum += weight[id];
    for (auto it = v[id].begin(); it != v[id].end(); it++)
        DFS(*it, sum);
    if (v[id].empty() && sum == S)
        ans.push_back(temp);
    temp.pop_back();
}

int main() {
    scanf("%d%d%d", &N, &M, &S);
    int i;
    for (i = 0; i < N; i++)
        scanf("%d", weight + i);
    for (i = 0; i < M; i++) {
        int id, k, temp;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &temp);
            v[id].push_back(temp);
        }
    }
    DFS();
    std::sort(ans.begin(), ans.end(), std::greater<std::vector<int>>());
    for (i = 0; i < ans.size(); i++) {
        printf("%d", ans[i][0]);
        for (auto it = ans[i].begin() + 1; it != ans[i].end(); it++)
            printf(" %d", *it);
        printf("\n");
    }
    return 0;
}
