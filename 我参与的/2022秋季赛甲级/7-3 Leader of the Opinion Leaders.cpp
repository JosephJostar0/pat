#include <iostream>
#include <vector>
#define MAXN 10001
std::vector<int> v[MAXN], ans;
int Nout[MAXN], isLead[MAXN];
int main() {
    int N, T, i, top = 0;
    scanf("%d%d", &N, &T);
    for (i = 1; i <= N; i++) {
        scanf("%d", Nout + i);
        for (int j = 0, t; j < Nout[i]; j++)
            scanf("%d", &t), v[t].push_back(i);
    }
    for (i = 1; i <= N; i++) {
        int oli = v[i].size() / Nout[i];
        if (oli >= T)
            isLead[i] = 1;
    }
    for (i = 1; i <= N; i++)
        if (isLead[i]) {
            int temp = 0;
            for (auto it = v[i].begin(); it != v[i].end(); it++)
                if (isLead[*it])
                    temp++;
            if (temp > top) {
                top = temp;
                ans.clear();
                ans.push_back(i);
            } else if (temp == top)
                ans.push_back(i);
        }
    printf("%d", ans[0]);
    for (i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
    return 0;
}