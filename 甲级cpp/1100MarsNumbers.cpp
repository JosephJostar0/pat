#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string link[2][13] = {{"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
                      {"0000", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}};
int main() {
    int N, up, down;
    string str, low, high;
    cin >> N, getchar();
    for (int i = 0; i < N; i++) {
        getline(cin, str);
        if (isdigit(str[0])) {
            up = stoi(str);
            down = up % 13;
            up /= 13;
            if (up)
                cout << link[1][up];
            if (up && down)
                cout << ' ';
            if (down || !up)
                cout << link[0][down];
        } else {
            up = 0;
            if (str.size() > 5) {
                high = str.substr(0, str.find_first_of(' ')), low = str.substr(str.find_first_of(' ') + 1, str.size());
                for (int j = 1; j < 13; j++)
                    if (link[1][j] == high)
                        up = j * 13;
            } else
                low = str;
            for (int k = 0; k < 2; k++)
                for (int j = k; j < 13; j++)
                    if (link[k][j] == low)
                        up += j * (k ? 13 : 1);
            cout << up;
        }
        cout << endl;
    }
    return 0;
}
