#include <iostream>
#include <string>
int main() {
    std::string line, ans, num;
    std::cin >> line;
    int  i, j;
    bool how;
    if (line[0] == '-')
        printf("-");
    for (i = 1; i < line.size(); i++) {
        if (line[i] == 'E')
            break;
        if (line[i] == '.')
            continue;
        num.push_back(line[i]);
    }
    how = line[i + 1] == '+' ? true : false;
    j   = std::stoi(line.substr(i + 2));
    if (how) {
        if (num.size() - 1 <= j)
            for (i = num.size() - 1; i < j; i++)
                num.push_back('0');
        else
            num.insert(num.begin() + 1 + j, '.');
        printf("%s", num.c_str());
    } else {
        for (i = 1; i < j; i++)
            num.insert(num.begin(), '0');
        printf("0.%s", num.c_str());
    }
    return 0;
}
