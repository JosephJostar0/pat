#include <algorithm>
#include <iostream>
#define MAXN 100001
int arr[MAXN], order[MAXN], N;
bool check(int l = 0, int r = N, bool flag = true) {
    if (l >= r)
        return true;
    int top = order[0], i;
    for (i = l; i < r; i++) {
        if (arr[i] > top)
            top = arr[i];
        if (arr[i] == order[i] && arr[i] == top) {
            if (flag) {
                if (check(0, i, false) && check(i + 1, N, false))
                    return true;
            } else
                return true;
        }
    }
    return false;
}

int main() {
    int turn;
    scanf("%d", &turn);
    while (turn) {
        int i;
        scanf("%d", &N);
        for (i = 0; i < N; i++)
            scanf("%d", arr + i), order[i] = arr[i];
        std::sort(order, order + N);
        if (check())
            printf("Yes\n");
        else
            printf("No\n");
        turn--;
    }
    return 0;
}