#include <cstring>
#include <iostream>
int has[256], need[256];
int main() {
    int  i, begin, end, less = 0, min, p[256];
    char str1[1001], str2[1001];
    scanf("%s%s", str1, str2);
    for (i = 0; str1[i]; i++)
        has[(int)str1[i]]++;
    for (i = 0; str2[i]; i++) {
        need[(int)str2[i]]++;
        if (need[(int)str2[i]] > has[(int)str2[i]])
            less++;
    }
    if (less)
        printf("No %d", less);
    else
        printf("Yes %d", strlen(str1) - strlen(str2));
    return 0;
}
