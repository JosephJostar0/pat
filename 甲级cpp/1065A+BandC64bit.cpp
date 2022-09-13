#include <iostream>
using namespace std;
int main() {
    int T, i;
    long long a, b, c, d;
    scanf("%d", &T);
    for (i = 1; i <= T; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        d = a + b;
        if (a > 0 && b > 0 && d < 0)
            printf("Case #%d: true\n", i);
        else if (a < 0 && b < 0 && d >= 0)
            printf("Case #%d: false\n", i);
        else if (d > c)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}
