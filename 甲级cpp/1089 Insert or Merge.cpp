#include <algorithm>
#include <iostream>
int  N, pre[101], alter[101];
bool isInsert() {
    int i;
    for (i = 1; i < N; i++)
        if (alter[i] < alter[i - 1])
            break;
    while (i < N) {
        if (alter[i] != pre[i])
            return false;
        i++;
    }
    return true;
}

void insertSort() {
    printf("Insertion Sort\n");
    int i;
    for (i = 1; i < N; i++)
        if (alter[i] < alter[i - 1])
            break;
    if (i < N)
        std::sort(alter, alter + i + 1);
    printf("%d", alter[0]);
    for (i = 1; i < N; i++)
        printf(" %d", alter[i]);
}

void mergeSort() {
    printf("Merge Sort\n");
    int i, j, k;
    for (i = 2, j = 1; i < N; i *= 2) {
        for (j = 0; j < N; j += i)
            std::sort(pre + j, pre + std::min(j + i, N));
        for (k = 0; k < N; k++)
            if (pre[k] != alter[k])
                break;
        if (k != N)
            continue;
        i *= 2;
        for (j = 0; j < N; j += i)
            std::sort(pre + j, pre + std::min(j + i, N));
        break;
    }
    printf("%d", pre[0]);
    for (k = 1; k < N; k++)
        printf(" %d", pre[k]);
}

int main() {
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &pre[i]);
    for (i = 0; i < N; i++)
        scanf("%d", &alter[i]);
    if (isInsert())
        insertSort();
    else
        mergeSort();
    return 0;
}
