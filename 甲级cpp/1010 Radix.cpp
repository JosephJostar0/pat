#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
long long map[123], value1;
string    n1, n2;

long long alter(string str, long long radix) {
    int       i, j;
    long long result = 0, temp;
    for (i = 0; i < str.size(); i++) {
        temp = map[(int)str[i]];
        for (j = 0; j < i; j++)
            temp *= radix;
        result += temp;
    }
    return result;
}

int cmp(long long a, long long b) {
    if (a < 0 || a > b)
        return 1;
    else if (a == b)
        return 0;
    else
        return -1;
}

long long binarySearch(long long left, long long right) {
    long long mid;
    int       flag;
    while (left <= right) {
        mid  = (left + right) / 2;
        flag = cmp(alter(n2, mid), value1);
        if (flag == 0)
            return mid;
        if (flag > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    int       tag, radix, i;
    long long bottom = 2, ans;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2)
        swap(n1, n2);
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    for (i = (int)'0'; i <= (int)'9'; i++)
        map[i] = (long long)(i - (int)'0');
    for (i = (int)'a'; i <= (int)'z'; i++)
        map[i] = (long long)(i - (int)'a' + 10);
    value1 = alter(n1, (long long)radix);
    for (i = 0; i < n2.size(); i++)
        if (map[(int)n2[i]] >= bottom)
            bottom = map[(int)n2[i]] + 1;
    ans = binarySearch(bottom, (value1 + 1));
    if (ans)
        cout << ans;
    else
        cout << "Impossible";
    return 0;
}