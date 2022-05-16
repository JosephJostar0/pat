#include <iostream>
int main() {
    char str[100001];
    int  i, p_num = 0, t_num = 0, out = 0;
    scanf("%s", str);
    for (i = 0; str[i]; i++)
        if (str[i] == 'T')
            t_num++;
    for (i = 0; str[i]; i++) {
        if (str[i] == 'P')
            p_num++;
        else if (str[i] == 'T')
            t_num--;
        else {
            out += p_num * t_num;
            out %= 1000000007;
        }
    }
    printf("%d", out);
    return 0;
}
