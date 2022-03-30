#include <iostream>
#include <string>
std::string out[10] = {"zero", "one", "two",   "three", "four",
                       "five", "six", "seven", "eight", "nine"};

void dfs(int n) {
    if (n / 10 == 0) {
        printf("%s", out[n % 10].c_str());
        return;
    }
    dfs(n / 10);
    printf(" %s", out[n % 10].c_str());
}

int main() {
    std::string num;
    std::cin >> num;
    int sum = 0, i;
    for (i = 0; i < num.size(); i++)
        sum += (int)(num[i] - '0');
    dfs(sum);
    return 0;
}
