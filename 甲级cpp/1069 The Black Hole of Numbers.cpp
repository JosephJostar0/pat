#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string num;
    int    n1, n2, result;
    cin >> result;
    do {
        num = to_string(result);
        while (num.size() < 4)
            num.push_back('0');
        sort(num.begin(), num.end());
        n2 = stoi(num);
        reverse(num.begin(), num.end());
        n1     = stoi(num);
        result = n1 - n2;
        printf("%04d - %04d = %04d\n", n1, n2, result);
    } while (result != 0 && result != 6174);
    return 0;
}
