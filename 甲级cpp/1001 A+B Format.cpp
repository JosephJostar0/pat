#include <iostream>
int main() {
    int n1, n2;
    std::cin >> n1 >> n2;
    n1 += n2;
    if (n1 < 0)
        printf("-"), n1 = -n1;
    if (n1 >= 1000000)
        printf("%d,%03d,%03d", n1 / 1000000, n1 % 1000000 / 1000, n1 % 1000);
    else if (n1 >= 1000)
        printf("%d,%03d", n1 / 1000, n1 % 1000);
    else
        printf("%d", n1);
    return 0;
}
