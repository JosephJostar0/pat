#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, unordered_map<int, int>> m;

int main() {
    int  N, M, K;
    int  L, t, place;
    int  i, j, k;
    bool flag, last = true;
    scanf("%d %d %d", &N, &M, &K);
    vector<int> v;
    for (i = 1; i <= N; i++) {
        v.clear();
        cin >> L;
        flag = true;
        for (j = 0; j < L; j++) {
            cin >> t;
            v.push_back(t);
        }
        scanf("%d %d", &t, &place);
        if (m[t][place] != 0) {
            printf("ERROR: Conflict between %d and %d.\n", i, m[t][place]);
            flag = false;
            last = false;
        }
        if (v.size() > 0 && find(v.begin(), v.end(), t) != v.end()) {
            printf("ERROR: Conflict with instructor for %d.\n", i);
            flag = false;
            last = false;
        }
        if (flag)
            m[t][place] = i;
    }
    if (last)
        printf("Perfect Arrangement for %d classes!", N);
    return 0;
}