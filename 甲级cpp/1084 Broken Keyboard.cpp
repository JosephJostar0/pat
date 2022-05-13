#include <iostream>
int HashTable[256];
int main() {
    char origin[128], out[128];
    int  i;
    scanf("%s%s", origin, out);
    for (i = 0; out[i]; i++) {
        if (out[i] >= 'a' && out[i] <= 'z')
            out[i] &= 255 - 0x20;
        HashTable[out[i]] = 1;
    }
    for (i = 0; origin[i]; i++) {
        if (origin[i] >= 'a' && origin[i] <= 'z')
            origin[i] &= 255 - 0x20;
        if (HashTable[origin[i]] == 1)
            continue;
        printf("%c", origin[i]);
        HashTable[origin[i]] = 1;
    }
    return 0;
}
