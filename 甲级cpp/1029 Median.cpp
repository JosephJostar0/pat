#include <iostream>
int main() {
    int arr1[200002], arr2[200002], N1, N2, i, j, N, out;
    scanf("%d", &N1);
    for (i = 0; i < N1; i++)
        scanf("%d", &arr1[i]);
    arr1[N1] = 0xbadbeef;
    scanf("%d", &N2);
    N1++;
    for (i = 0; i < N2; i++)
        scanf("%d", &arr2[i]);
    arr2[N2] = 0xbadbeef;
    N2++;
    N = (N1 + N2 - 3) / 2;
    i = 0, j = 0, out = 0;
    while (out++ < N && i < N1 && j < N2) {
        if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    printf("%d", std::min(arr1[i], arr2[j]));
    return 0;
}
