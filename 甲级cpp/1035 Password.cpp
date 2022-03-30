#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//像我这样用一堆标准库就可以不用struct/class...
bool change(std::string &str) {
    int  i;
    bool flag = false;
    for (i = 0; i < str.size(); i++) {
        if (str[i] == '1')
            str[i] = '@';
        else if (str[i] == '0')
            str[i] = '%';
        else if (str[i] == 'l')
            str[i] = 'L';
        else if (str[i] == 'O')
            str[i] = 'o';
        else
            continue;
        flag = true;
    }
    return flag;
}

int main() {
    int         N, i;
    std::string id, pwd;
    scanf("%d", &N);
    std::unordered_map<std::string, std::string> map;
    std::vector<std::string>                     list;
    for (i = 0; i < N; i++) {
        std::cin >> id >> pwd;
        if (change(pwd))
            map[id] = pwd, list.push_back(id);
    }
    if (map.size()) {
        printf("%d\n", map.size());
        std::vector<std::string>::iterator it;
        for (it = list.begin(); it != list.end(); it++)
            printf("%s %s\n", (*it).c_str(), map[(*it)].c_str());
    } else if (N > 1)
        printf("There are %d accounts and no account is modified", N);
    else
        printf("There is 1 account and no account is modified");
    return 0;
}
