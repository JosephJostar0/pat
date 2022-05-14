#include <algorithm>
#include <iostream>
#include <string>
bool cmp(std::string a, std::string b) {
    std::string s1 = a + b, s2 = b + a;
    return a + b < b + a;
}
int main() {
    int         N, i, k, d = 1;
    std::string num[10000];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        std::cin >> num[i];
    std::sort(num, num + N, cmp);
    for (i = 1; i < N; i++)
        num[0] += num[i];
    while (num[0].size() && num[0][0] == '0')
        num[0].erase(num[0].begin());
    if (num[0].empty())
        std::cout << 0;
    else
        std::cout << num[0];
    return 0;
}
