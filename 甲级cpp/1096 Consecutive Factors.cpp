#include <iostream>
int main() {
    long long num, copy, maxLen = 0, flag, len, i, j;
    scanf("%lld", &num);
    for (i = 2; i * i <= num; i++) {
        copy = num, len = 0, j = i;
        while (copy % j == 0) {
            copy /= j;
            len++, j++;
        }
        if (maxLen < len)
            maxLen = len, flag = i;
    }
    if (maxLen)
        printf("%lld\n%lld", maxLen, flag);
    else
        printf("%lld\n%lld", 1, num);
    for (i = 1; i < maxLen; i++)
        printf("*%lld", ++flag);
    return 0;
}
