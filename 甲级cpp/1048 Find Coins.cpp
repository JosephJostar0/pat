#include <iostream>
int coins[501];
int main() {
    int N, M, i, j;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++) {
        scanf("%d", &j);
        coins[j]++;
    }
    for (i = 0; i <= M / 2; i++)
        if (coins[i] && coins[M - i])
            break;
    if (i > M / 2)
        printf("No Solution");
    else if (i == M / 2 && coins[i] < 2)
        printf("No Solution");
    else
        printf("%d %d", i, M - i);
    return 0;
}
