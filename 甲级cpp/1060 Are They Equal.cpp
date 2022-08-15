#include <iostream>
#include <string>
using namespace std;
int N, index[2];
string str[2];
void getNum(int id) {
    int i;
    while (str[id].size() && str[id][0] == '0')
        str[id].erase(str[id].begin());
    if (str[id].size() && str[id][0] == '.') {
        str[id].erase(str[id].begin());
        while (str[id].size() && str[id][0] == '0')
            str[id].erase(str[id].begin()), index[id]--;
        if (str[id].empty())
            index[id] = 0;
    } else {
        for (i = 0; i < str[id].size(); i++, index[id]++)
            if (str[id][i] == '.') {
                str[id].erase(str[id].begin() + i);
                break;
            }
    }
    while (str[id].size() > N)
        str[id].pop_back();
    while (str[id].size() < N)
        str[id].push_back('0');
    str[id] = "0." + str[id];
}

int main() {
    int i;
    cin >> N >> str[0] >> str[1];
    getNum(0), getNum(1);
    if (index[0] == index[1] && str[0] == str[1])
        printf("YES %s*10^%d", str[0].c_str(), index[0]);
    else
        printf("NO %s*10^%d %s*10^%d", str[0].c_str(), index[0], str[1].c_str(), index[1]);
    return 0;
}
