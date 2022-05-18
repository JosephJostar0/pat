#include <iostream>
long long divided(long long a, long long b) {
    if (a == 0 || b == 0)
        return 0;
    long long c = a % b;
    while (c) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

void sout(long long son, long long mother) {
    bool flag = false;
    if (son * mother < 0)
        printf("(-"), flag = true;
    son = llabs(son), mother = llabs(mother);
    if (son == 0)
        printf("0");
    else if (mother == 0)
        printf("Inf");
    else if (son / mother && son % mother)
        printf("%lld %lld/%lld", son / mother, son % mother, mother);
    else if (son / mother)
        printf("%lld", son / mother);
    else
        printf("%lld/%lld", son, mother);
    if (flag)
        printf(")");
}

void cal(long long son[], long long mother[], long long how) {
    long long div, s, m;
    char      sign[4] = {'+', '-', '*', '/'};
    sout(son[0], mother[0]);
    printf(" %c ", sign[how]);
    sout(son[1], mother[1]);
    printf(" = ");
    if (how == 0)
        m = mother[0] * mother[1], s = (son[0] * mother[1] + son[1] * mother[0]);
    else if (how == 1)
        m = mother[0] * mother[1], s = (son[0] * mother[1] - son[1] * mother[0]);
    else if (how == 2)
        m = mother[0] * mother[1], s = son[0] * son[1];
    else if (how == 3)
        m = mother[0] * son[1], s = mother[1] * son[0];
    div = divided(s, m);
    if (div)
        m /= div, s /= div;
    sout(s, m);
    printf("\n");
}

int main() {
    long long son[2], mother[2], out[2], div, i;
    scanf("%lld/%lld %lld/%lld", son, mother, son + 1, mother + 1);
    for (i = 0; i < 2; i++) {
        div = divided(son[i], mother[i]);
        if (div)
            son[i] /= div, mother[i] /= div;
    }
    for (i = 0; i < 4; i++)
        cal(son, mother, i);
    return 0;
}
