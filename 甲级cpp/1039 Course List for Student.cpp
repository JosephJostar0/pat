#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N, K, i, j, id, cnt;
    string name;
    unordered_map<string, vector<int>> table;
    cin >> N >> K;
    for (i = 0; i < K; i++) {
        cin >> id >> cnt;
        for (j = 0; j < cnt; j++) {
            cin >> name;
            table[name].push_back(id);
        }
    }
    for (i = 0; i < N; i++) {
        cin >> name;
        cnt = table[name].size();
        sort(table[name].begin(), table[name].end());
        cout << name << ' ' << cnt;
        for (j = 0, cnt = table[name].size(); j < cnt; j++)
            cout << ' ' << table[name][j];
        cout << endl;
    }
    return 0;
}
