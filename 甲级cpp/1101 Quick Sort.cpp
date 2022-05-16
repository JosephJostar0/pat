#include <algorithm>
#include <iostream>
int main() {
    int N, nums[100002], copy[100002], i, ans = 0, big = -1, out[100002];
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", nums + i);
        copy[i] = nums[i];
    }
    std::sort(copy, copy + N);
    for (i = 0; i < N; i++) {
        if (copy[i] == nums[i] && big < copy[i])
            out[ans++] = nums[i];
        big = std::max(big, nums[i]);
    }
    if (ans == 0) {
        printf("%d\n\n", ans);
        return 0;
    }
    printf("%d\n%d", ans, out[0]);
    for (i = 1; i < ans; i++)
        printf(" %d", out[i]);
    return 0;
}
