#include <iostream>
int ans[10001], in[100001];
int main() {
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &in[i]);
        ans[in[i]]++;
    }
    for (i = 0; i < N; i++)
        if (ans[in[i]] == 1) {
            printf("%d", in[i]);
            break;
        }
    if (i == N)
        printf("None");
    return 0;
}
