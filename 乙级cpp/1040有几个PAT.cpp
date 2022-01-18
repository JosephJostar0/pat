#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    unsigned int result = 0, p = 0, t = 0, i;
    for (i = 0; i < s.length(); i++)
        if (s[i] == 'T')
            t++;
    for (i = 0; i < s.length(); i++) {//每遇到一个a，则将可用p与可用t相乘
        if (s[i] == 'P')
            p++;
        if (s[i] == 'T')
            t--;
        if (s[i] == 'A')
            result = (result + (p * t) % 1000000007) % 1000000007;
    }
    cout << result << endl;
    return 0;
}
