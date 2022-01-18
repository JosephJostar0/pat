#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> v;
    string str;
    do {
        cin >> str;
        v.push(str);
    } while (getchar() == ' ');
    cout << v.top();
    v.pop();
    while (!v.empty()) {
        cout << " " << v.top();
        v.pop();
    }
    return 0;
}
