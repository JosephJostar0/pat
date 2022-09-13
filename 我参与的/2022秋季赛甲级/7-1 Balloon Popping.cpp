#include <iostream>
#include <vector>
int main() {
    int N, h, i, t;
    int v[100001], left;
    int top = 0, top_l;
    scanf("%d%d", &N, &h);
    for (i = 0; i < N; i++) {
        scanf("%d", v + i);
        left = v[i];
        int temp = 0;
        t = i;
        while (t >= 0 && left - v[t] <= h) {
            t--, temp++;
        }
        if (temp > top)
            top = temp, top_l = left;
    }
    printf("%d %d", top_l - h, top);
    return 0;
}
