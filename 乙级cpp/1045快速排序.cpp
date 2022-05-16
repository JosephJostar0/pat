#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>           vec, result, order;
    vector<int>::iterator it;
    int                   i, j, k;
    int                   max = 0, min = 0;
    for (i = 0; i < n; i++) {
        cin >> j;
        vec.push_back(j);
        order.push_back(j);
    }
    sort(order.begin(), order.end());
    for (i = 0; i < n; i++) {
        if (vec[i] == order[i] && vec[i] > max)
            result.push_back(vec[i]);
        if (vec[i] > max)
            max = vec[i];
    }
    cout << result.size() << endl;
    if (result.size() > 0)
        cout << result[0];
    for (i = 1; i < result.size(); i++)
        cout << ' ' << result[i];
    cout << endl;
    return 0;
}
