#include <cmath>
#include <iostream>
#include <vector>
#define MAXN 100000
std::vector<int> v[MAXN];
int N, isSon[MAXN], cnt, top = MAXN + 1;
double P, r;
void DFS(int root, int mul = 0) {
    if (v[root].empty()) {
        if (mul < top)
            top = mul, cnt = 1;
        else if (mul == top)
            cnt++;
        return;
    }
    mul++;
    for (auto it = v[root].begin(); it != v[root].end(); it++)
        DFS(*it, mul);
}

int main() {
    scanf("%d%lf%lf", &N, &P, &r);
    r += 100, r /= 100;
    int i;
    for (i = 0; i < N; i++) {
        int num, j, id;
        scanf("%d", &num);
        for (j = 0; j < num; j++) {
            scanf("%d", &id);
            v[i].push_back(id);
            isSon[id] = 1;
        }
    }
    for (i = 0; i < N; i++)
        if (!isSon[i])
            break;
    DFS(i);
    printf("%.4f %d", P * pow(r, top), cnt);
    return 0;
}
