#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int K;
    int i, j, t, s = 1;
    cin >> K;
    unordered_map<int, int> m;
    for (i = 1; i <= 54; i++) {
        cin >> t;
        m[i] = t;
    }
    string         cards[5] = {"S", "H", "C", "D", "J"};
    string         card;
    vector<string> v(55);
    for (i = 0; i < 54; i++) {
        t = i + 1;
        for (j = 0; j < K; j++)
            t = m[t];
        card = cards[i / 13];
        card += to_string(s);
        v[t] = card;
        s++;
        s = s < 14 ? s : 1;
    }
    cout << v[1];
    for (i = 2; i <= 54; i++)
        cout << ' ' << v[i];
    return 0;
}
