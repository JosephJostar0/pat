#include <iostream>
#include <vector>
#define MAXN 100000
int N, cnt;
double P, r, top = 0.0;
std::vector<int> v[MAXN];
void DFS(int id, double price = P) {
    if (price > top)
        top = price, cnt = 1;
    else if (price == top)
        cnt++;
    price *= r;
    for (int i = 0; i < v[id].size(); i++)
        DFS(v[id][i], price);
}

int main() {
    scanf("%d%lf%lf", &N, &P, &r);
    r += 100, r /= 100;
    int i, root;
    for (i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        if (temp < 0)
            root = i;
        else
            v[temp].push_back(i);
    }
    DFS(root);
    printf("%.2f %d", top, cnt);
    return 0;
}
