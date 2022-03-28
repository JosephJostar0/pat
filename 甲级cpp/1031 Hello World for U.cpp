#include <iostream>
#include <string>
int main() {
    std::string str;
    std::cin >> str;
    int m, n, i, j;
    m = (str.size() + 2) / 3;
    n = str.size() + 2 - 2 * m;
    for (i = 0; i < m - 1; i++) {
        std::cout << str[i];
        for (j = 0; j < n - 2; j++)
            std::cout << ' ';
        std::cout << str[str.size() - i - 1] << std::endl;
    }
    for (j = i; j < i + n; j++)
        std::cout << str[j];
    return 0;
}
