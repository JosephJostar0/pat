#include <iostream>
int main() { //其实就是个排列组合问题
    int N, i, high, low, ans = 0;
    scanf("%d", &N);
    for (i = 1; i <= N; i *= 10) {
        high = N / i / 10;  //高位的可选-1
        low  = N % i + 1;   //低位的可选
        ans += high * i;    //加上本位取1的所有组合
        if (N / i % 10 > 1) //如果高满时本位超过1
            ans += i;
        else if (N / i % 10 == 1) //本位为1
            ans += low;
    }
    printf("%d\n", ans);
}
