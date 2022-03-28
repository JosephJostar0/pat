#include <iostream>
int main() {
    char   result[3] = {'W', 'T', 'L'};
    int    i, j, id;
    double value = 0.65, k, big;
    for (i = 0; i < 3; i++) {
        big = 0.0, id = 0;
        for (j = 0; j < 3; j++) {
            scanf("%lf", &k);
            if (k > big)
                big = k, id = j;
        }
        value *= big;
        printf("%c ", result[id]);
    }
    value -= 1;
    value *= 2;
    printf("%.2f", value);
    return 0;
}
