#include <algorithm>
#include <iostream>
int main() {
    int       N, i, ans = 0, left, right;
    long long nums[100000], p;
    scanf("%d%d", &N, &p);
    for (i = 0; i < N; i++)
        scanf("%lld", &nums[i]);
    std::sort(nums, nums + N);
    for (right = 1; right < N; right++)
        if (nums[right] > nums[0] * p)
            break;
    ans = right;
    for (left = 0; left < N; left++) {
        if (right == N)
            break;
        while (right < N && nums[right] <= nums[left] * p)
            right++;
        if (right - left > ans)
            ans = right - left;
    }
    printf("%d", ans);
    return 0;
}
