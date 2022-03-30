#include <iostream>
#include <string>
using namespace std;
int main() {
    string digit[10] = {"ling", "yi",  "er", "san", "si",
                        "wu",   "liu", "qi", "ba",  "jiu"};
    string decimal[] = {"", " Shi", " Bai", " Qian", " Wan", " Yi"};
    string num;
    int    low, high;
    cin >> num;
    low = 0, high = num.size() - 1;
    if (num[0] == '-')
        cout << "Fu", low++;
    while (low + 4 <= high)
        high -= 4;
    while (low < num.size()) {
        bool flag    = false;
        bool isPrint = false;
        while (low <= high) {
            if (low > 0 && num[low] == '0')
                flag = true;
            else {
                if (flag == true)
                    cout << " ling", flag = false;
                if (low > 0)
                    cout << ' ';
                cout << digit[(int)(num[low] - '0')];
                isPrint = true;
                if (low != high)
                    cout << decimal[high - low];
            }
            low++;
        }
        if (isPrint && high != num.size() - 1)
            cout << decimal[(num.size() - high) / 4 + 3];
        high += 4;
    }
    return 0;
}
