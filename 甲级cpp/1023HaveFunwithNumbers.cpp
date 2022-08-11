#include <cstring>
#include <iostream>
class BigInt {
public:
    int data[30];
    int len;
    BigInt() { len = 0; }
    void out() {
        for (int i = len - 1; i >= 0; i--)
            printf("%d", data[i]);
    }
} bigInt;
int cnt[10], now[10];

BigInt toBigInt(char str[]) {
    int size = strlen(str), num;
    BigInt temp;
    while (size--) {
        num = (int)(str[size] - '0');
        temp.data[temp.len++] = num;
        cnt[num]++;
    }
    return temp;
}

BigInt mul(BigInt bigInt) {
    int move = 0, current, i;
    for (i = 0; i < bigInt.len; i++) {
        current = move + bigInt.data[i] * 2;
        bigInt.data[i] = current % 10;
        now[bigInt.data[i]]++;
        move = current /= 10;
    }
    while (current)
        bigInt.data[bigInt.len++] = current % 10, current /= 10;
    return bigInt;
}

int main() {
    int i;
    char str[22];
    scanf("%s", str);
    bigInt = toBigInt(str);
    bigInt = mul(bigInt);
    for (i = 0; i < 10; i++)
        if (cnt[i] != now[i])
            break;
    printf("%s\n", i == 10 ? "Yes" : "No");
    bigInt.out();
    return 0;
}
