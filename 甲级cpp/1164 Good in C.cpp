#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
std::vector<int> v;
int flag;
class Letter {
public:
    std::string line[7];
    void input() {
        for (int i = 0; i < 7; i++)
            std::getline(std::cin, line[i]);
    }
} letters[26];

void output() {
    if (v.size()) {
        int j, k;
        if (flag)
            std::cout << std::endl << std::endl;
        for (j = 0; j < 7; j++) {
            if (j)
                std::cout << std::endl;
            for (k = 0; k < v.size(); k++) {
                if (k)
                    std::cout << ' ';
                std::cout << letters[v[k]].line[j];
            }
        }
        v.clear();
        flag = 1;
    }
}

int main() {
    int i;
    std::string str;
    for (i = 0; i < 26; i++)
        letters[i].input();
    std::getline(std::cin, str);
    for (i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            v.push_back(str[i] - 'A');
        else
            output();
    }
    output();
    return 0;
}
