#include <iostream>
#include <vector>
#define MAXN 100000
std::vector<int> v[MAXN];
int N;
double P, r, ans = 0;
void getAns(int id = 0, double price = P) {
    if (v[id][0] == 0) {
        ans += v[id][1] * price;
        return;
    }
    for (int i = 0; i < v[id].size(); i++)
        getAns(v[id][i], price * r);
}

int main() {
    int i, j;
    scanf("%d%lf%lf", &N, &P, &r);
    r += 100, r /= 100;
    for (i = 0; i < N; i++) {
        int cnt, temp;
        scanf("%d", &cnt);
        if (cnt)
            for (j = 0; j < cnt; j++) {
                scanf("%d", &temp);
                v[i].push_back(temp);
            }
        else {
            scanf("%d", &temp);
            v[i].push_back(0);
            v[i].push_back(temp);
        }
    }
    getAns();
    printf("%.1f", ans);
    return 0;
}
