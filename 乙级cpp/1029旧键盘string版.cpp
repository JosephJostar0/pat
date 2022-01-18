#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    	//s2.find(s1[i]) == string::npos 当等号左右两边的值相等时意味着没找到字符s[i] 
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
            ans += toupper(s1[i]);//大写 
    cout << ans;
    return 0;
}
