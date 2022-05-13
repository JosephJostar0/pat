#include <stdio.h>
int need[256];
int main() {
    char str1[10001], str2[10001];
    int  i;
    gets(str1);
    gets(str2);
    for (i = 0; str2[i]; i++)
        need[(int)str2[i]]++;
    for (i = 0; str1[i]; i++)
        if (!need[(int)str1[i]])
            printf("%c", str1[i]);
    return 0;
}
