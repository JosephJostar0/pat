#include <iostream>
int main() {
    int N, M, diamonds[100001], i, left, right, sum = 0, flag = 0, margin = 0xbadbeef;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++)
        scanf("%d", &diamonds[i]);
    for (left = 0, right = 0; left < N; left++) {
        while (right < N && sum < M)
            sum += diamonds[right++];
        if (sum > M && sum < margin)
            margin = sum;
        if (sum == M && right > left) {
            if (flag)
                printf("\n");
            printf("%d-%d", left + 1, right);
            flag = 1;
        }
        sum -= diamonds[left];
    }
    if (!flag) {
        M = margin, sum = 0;
        for (left = 0, right = 0; left < N; left++) {
            while (right < N && sum < M)
                sum += diamonds[right++];
            if (sum == M && right > left) {
                if (flag)
                    printf("\n");
                printf("%d-%d", left + 1, right);
                flag = 1;
            }
            sum -= diamonds[left];
        }
    }
    return 0;
}
