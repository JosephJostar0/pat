#include <iostream>
double sum[1001]; //全局变量自动初始化为全0

int main() {
    int    i, j, num, index, count = 0;
    double value;
    for (i = 0; i < 2; i++) {
        scanf("%d", &num);
        for (j = 0; j < num; j++) {
            scanf("%d%lf", &index, &value);
            if (sum[index] == 0)
                count++;
            sum[index] += value;
            if (sum[index] == 0)
                count--;
        }
    }
    printf("%d", count);
    for (i = 1000; i >= 0; i--)
        if (sum[i] != 0)
            printf(" %d %.1f", i, sum[i]);
    return 0;
}
