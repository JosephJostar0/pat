#include <iostream>
int main() {
    int  n1, n2, n3;
    char i, j;
    scanf("%d%d%d", &n1, &n2, &n3);
    printf("#");
    i = (n1 % 13) > 9 ? ('A' + n1 % 13 - 10) : ('0' + n1 % 13);
    j = (n1 / 13) > 9 ? ('A' + n1 / 13 - 10) : ('0' + n1 / 13);
    printf("%c%c", j, i);
    i = (n2 % 13) > 9 ? ('A' + n2 % 13 - 10) : ('0' + n2 % 13);
    j = (n2 / 13) > 9 ? ('A' + n2 / 13 - 10) : ('0' + n2 / 13);
    printf("%c%c", j, i);
    i = (n3 % 13) > 9 ? ('A' + n3 % 13 - 10) : ('0' + n3 % 13);
    j = (n3 / 13) > 9 ? ('A' + n3 / 13 - 10) : ('0' + n3 / 13);
    printf("%c%c", j, i);
    return 0;
}
