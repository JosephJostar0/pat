#include <iostream>
#define MAXN 1000
int  sequence[MAXN], M, N, K;
bool check() {
    int lite, temp, current;
    for (int i = 0; i < N; i++) {
        temp    = sequence[i];
        current = temp;
        lite    = 0;
        for (int j = i + 1; j < N; j++)
            if (sequence[j] < temp) {
                if (current > sequence[j])
                    current = sequence[j];
                else
                    return false;
                lite++;
            }
        if (lite >= M)
            return false;
    }
    return true;
}
int main() {
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++)
            scanf("%d", sequence + j);
        printf(check() ? "YES\n" : "NO\n");
    }
    return 0;
}
