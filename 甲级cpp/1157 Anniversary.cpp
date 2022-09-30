#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> fun;
string oldest;
int top;
void isOld(string str) {
    int temp = stoi(str.substr(6, 8));
    if (temp < top)
        top = temp, oldest = str;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, i, cnt = 0;
    string str;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> str;
        fun[str] = 1;
    }
    cin >> M >> str;
    if (fun[str])
        cnt++;
    oldest = str;
    top = stoi(str.substr(6, 8));
    for (i = 1; i < M; i++) {
        cin >> str;
        if (fun[str])
            cnt++;
        isOld(str);
    }
    cout << cnt << '\n' << oldest;
    return 0;
}
