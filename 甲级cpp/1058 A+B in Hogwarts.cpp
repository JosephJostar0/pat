#include <iostream>
int main() {
    int gallon1, sickle1, knut1;
    int gallon2, sickle2, knut2;
    scanf("%d.%d.%d", &gallon1, &sickle1, &knut1);
    scanf("%d.%d.%d", &gallon2, &sickle2, &knut2);
    knut1 += knut2;
    sickle1 += sickle2;
    gallon1 += gallon2;
    sickle1 += knut1 / 29;
    knut1 %= 29;
    gallon1 += sickle1 / 17;
    sickle1 %= 17;
    printf("%d.%d.%d", gallon1, sickle1, knut1);
    return 0;
}
