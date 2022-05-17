#include <iostream>
int main() {
    int i, N, ans = 0, step = 0, floor;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &floor);
        if (floor > step)
            ans += (floor - step) * 6;
        else
            ans += (step - floor) * 4;
        ans += 5;
        step = floor;
    }
    printf("%d\n", ans);
    return 0;
}
