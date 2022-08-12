#include <cstring>
#include <iostream>
class BigInt {
public:
    int data[500];
    int len;
    BigInt() { len = 0; }
    void out() {
        for (int i = len - 1; i >= 0; i--)
            printf("%d", data[i]);
    }
    void toBigInt(char N[]) {
        int size = strlen(N);
        while (size--)
            data[len++] = (int)(N[size] - '0');
    }
};

BigInt alter(BigInt bigInt) {
    BigInt ans;
    int move = 0, current, i, len = bigInt.len - 1;
    for (i = 0; i < bigInt.len; i++) {
        current = move + bigInt.data[i] + bigInt.data[len - i];
        move = current / 10;
        ans.data[ans.len++] = current % 10;
    }
    while (move)
        ans.data[ans.len++] = move % 10, move /= 10;
    return ans;
}

bool isPalindromic(BigInt bigInt) {
    int i, margin = bigInt.len / 2, len = bigInt.len - 1;
    for (i = 0; i < margin; i++)
        if (bigInt.data[i] != bigInt.data[len - i])
            return false;
    return true;
}

int main() {
    char N[12];
    int K, cnt = 0;
    BigInt bigInt;
    scanf("%s%d", &N, &K);
    bigInt.toBigInt(N);
    while (cnt < K && !isPalindromic(bigInt)) {
        bigInt = alter(bigInt);
        cnt++;
    }
    bigInt.out();
    printf("\n%d", cnt);
    return 0;
}
