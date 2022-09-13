#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int         n;
    vector<int> v;
    cin >> n;
    int i, j, k;
    for (i = 0; i < n; i++) {
        cin >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    int h, m, e, ddd = 0;
    for (i = 0; i < v.size(); i++) {
        h = v[i];
        for (j = 0; j < v.size(); j++) {
            m = v[j];
            for (k = 0; k < v.size(); k++) {
                if (ddd > 0)
                    cout << ' ';
                e = v[k];
                printf("%d%d%d", h, m, e);
                if (ddd == 9) {
                    cout << endl;
                    ddd = -1;
                }
                ddd++;
            }
        }
    }
    return 0;
}