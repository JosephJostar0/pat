#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, K;
    int i, j;
    scanf("%d %d", &N, &K);
    vector<int> v;
    for (i = 0; i < N && i < K; i++) {
        scanf("%d", &j);
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    for (; i < N; i++) {
        scanf("%d", &j);
        if (j > v[0]) {
            v.erase(v.begin());
            v.push_back(j);
            sort(v.begin(), v.end());
        }
    }
    printf("%d", v[v.size() - 1]);
    for (i = v.size() - 2; i >= 0; i--)
        printf(" %d", v[i]);
    return 0;
}