#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, B, i, j;
    cin >> N >> B;
    vector<int> result;
    while (N) {
        result.insert(result.begin(), (N % B));
        N /= B;
    }
    while (result.size() && result[0] == '0')
        result.erase(result.begin());
    for (i = 0, j = result.size() - 1; i < j; i++, j--)
        if (result[i] != result[j])
            break;
    if (i != j)
        cout << "No\n";
    else
        cout << "Yes\n";
    cout << result[0];
    for (i = 1; i < result.size(); i++)
        cout << ' ' << result[i];
    return 0;
}
