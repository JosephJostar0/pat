#include <iostream>
int main() {
    int N, nums[100000], i, j, k = 1, out = 0, wait = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &j);
        nums[j] = i;
        if (j != i)
            wait++;
    }
    while (k != N) {
        while (nums[0]) {
            std::swap(nums[0], nums[nums[0]]);
            out++;
            wait--;
        }
        if (!nums[0]) {
            while (k < N && nums[k] == k)
                k++;
            if (k == N)
                break;
            std::swap(nums[0], nums[k]);
            out++;
        }
    }
    printf("%d", out);
    return 0;
}
