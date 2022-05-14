#include <algorithm>
#include <iostream>
int main() {
    int       Nc, Np, i, flag, j;
    long long value = 0, coupons[100000], products[100000];
    bool      has   = false;
    scanf("%d", &Nc);
    for (i = 0; i < Nc; i++)
        scanf("%lld", &coupons[i]);
    scanf("%d", &Np);
    for (i = 0; i < Np; i++)
        scanf("%lld", &products[i]);
    std::sort(coupons, coupons + Nc);
    std::sort(products, products + Np);
    for (i = 0; i < Nc && i < Np && coupons[i] < 0 && products[i] < 0; i++)
        value += coupons[i] * products[i];
    for (i = Nc - 1, j = Np - 1; i >= flag && j >= flag; i--, j--)
        if (coupons[i] > 0 && products[j] > 0)
            value += coupons[i] * products[j];
    printf("%lld", value);
    return 0;
}
