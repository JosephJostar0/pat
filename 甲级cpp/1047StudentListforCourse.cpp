#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
char name[40000][5];
bool cmp(int x, int y) { return strcmp(name[x], name[y]) < 0; }

int main() {
    int N, K, i, j, cnt, id;
    scanf("%d%d", &N, &K);
    vector<int> table[2501];
    for (i = 0; i < N; i++) {
        scanf("%s %d", name + i, &cnt);
        for (j = 0; j < cnt; j++) {
            scanf("%d", &id);
            table[id].push_back(i);
        }
    }
    for (i = 1; i <= K; i++) {
        cnt = table[i].size();
        printf("%d %d\n", i, cnt);
        sort(table[i].begin(), table[i].end(), cmp);
        for (j = 0; j < cnt; j++)
            printf("%s\n", name[table[i][j]]);
    }
    return 0;
}
