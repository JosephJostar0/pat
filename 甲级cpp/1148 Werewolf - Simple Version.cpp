#include <iostream>
#define MAXN 101
int N, msg[MAXN];
bool check(int l1, int l2) {
    int lie = 0, wolf = 0;
    for (int i = 1; i <= N; i++) {
        if (msg[i] < 0) {
            if (-msg[i] != l1 && -msg[i] != l2) {
                lie++;
                if (i == l1 || i == l2)
                    wolf++;
            }
        } else {
            if (msg[i] == l1 || msg[i] == l2) {
                lie++;
                if (i == l1 || i == l2)
                    wolf++;
            }
        }
    }
    return (lie == 2 && wolf == 1);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", msg + i);
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            if (check(i, j)) {
                printf("%d %d\n", i, j);
                return 0;
            }
    printf("No Solution\n");
    return 0;
}
