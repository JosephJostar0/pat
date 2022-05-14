#include <algorithm>
#include <iostream>
double cake[1001][3];
bool   cmp(int a, int b) { return cake[a][2] > cake[b][2]; }

int main() {
    int    N, D, i, value[1001];
    double out = 0;
    scanf("%d%d", &N, &D);
    for (i = 0; i < N; i++)
        scanf("%lf", &cake[i][0]);
    for (i = 0; i < N; i++) {
        scanf("%lf", &cake[i][1]);
        cake[i][2] = cake[i][1] / cake[i][0];
        value[i]   = i;
    }
    std::sort(value, value + N, cmp);
    for (i = 0; i < N; i++) {
        if (cake[value[i]][0] > D)
            break;
        D -= cake[value[i]][0];
        out += cake[value[i]][1];
    }
    if (i < N)
        out += cake[value[i]][1] * D / cake[value[i]][0];
    printf("%.2f", out);
    return 0;
}
