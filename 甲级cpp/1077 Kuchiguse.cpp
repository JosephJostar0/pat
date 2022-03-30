#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int  N, i, j, small = 0xbadbeef;
    char letter;
    cin >> N;
    getchar();
    vector<string> strList;
    string         str;
    for (i = 0; i < N; i++) {
        getline(cin, str);
        reverse(str.begin(), str.end());
        strList.push_back(str);
        if (str.size() < small)
            small = str.size();
    }
    for (i = 0, str.clear(); i < small; i++) {
        letter = strList[0][i];
        for (j = 1; j < strList.size(); j++)
            if (strList[j][i] != letter)
                break;
        if (j == strList.size())
            str.insert(str.begin(), letter);
        else
            break;
    }
    if (str.size())
        cout << str;
    else
        cout << "nai";
    return 0;
}
