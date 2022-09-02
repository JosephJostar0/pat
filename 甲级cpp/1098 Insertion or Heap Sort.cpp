#include <iostream>
#define MAXN 101
int pre[MAXN], arr[MAXN], N;
bool isInsert() {
    int i = 0, temp;
    while (i + 1 < N && arr[i] <= arr[i + 1])
        i++;
    for (temp = i + 1; temp < N; temp++)
        if (pre[temp] != arr[temp])
            return false;
    printf("Insertion Sort\n");
    while (i >= 0 && i + 1 < N && arr[i + 1] < arr[i])
        std::swap(arr[i + 1], arr[i]), i--;
    printf("%d", arr[0]);
    for (i = 1; i < N; i++)
        printf(" %d", arr[i]);
    return true;
}

void downAdjust(int dad, int margin) {
    int son = dad * 2 + 1;
    while (son < margin) {
        if (son + 1 < margin && arr[son + 1] > arr[son])
            son++;
        if (arr[son] < arr[dad])
            return;
        std::swap(arr[son], arr[dad]);
        dad = son;
        son = dad * 2 + 1;
    }
}

void heap() {
    int back = N - 1;
    while (back > 0 && arr[back] >= arr[back - 1] && arr[back] >= arr[0])
        back--;
    std::swap(arr[back], arr[0]);
    downAdjust(0, back);
    printf("Heap Sort\n%d", arr[0]);
    for (int i = 1; i < N; i++)
        printf(" %d", arr[i]);
}

int main() {
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++)
        scanf("%d", pre + i);
    for (i = 0; i < N; i++)
        scanf("%d", arr + i);
    if (!isInsert())
        heap();
    return 0;
}
