#include <cstring>
#include <iostream>
char map[13][4] = {
    "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
};
int main() {
    int N, day, year;
    char month[4], line[16] = "";
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int flag = 1;
        scanf("%s %d,%d", month, &day, &year);
        for (int j = 1; j < 13; j++)
            if (!strcmp(month, map[j]))
                sprintf(line, "%04d%02d%02d", year, j, day);
        for (int j = 0, k = 7; j < k; j++, k--)
            if (line[j] != line[k])
                flag = 0;
        printf("%s %s\n", flag ? "Y" : "N", line);
    }
    return 0;
}
