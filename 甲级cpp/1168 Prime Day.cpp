#include <algorithm>
#include <iostream>
#include <string>
std::string num, ans[2] = {"Yes", "No"};
bool flag = true;
bool isPrime(int x) {
    if (x == 2)
        return true;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return (x > 2) && (x & 1);
}

void f(int step = 0) {
    if (step == num.size())
        return;
    f(step + 1);
    std::string str = "";
    for (int i = step; i >= 0; i--)
        str.push_back(num[7 - i]);
    int i = std::stoi(str), tag = 0;
    if (!isPrime(i))
        tag = 1, flag = false;
    printf("%s %s\n", str.c_str(), ans[tag].c_str());
}

int main() {
    std::cin >> num;
    f();
    if (flag)
        printf("All Prime!\n");
    return 0;
}
