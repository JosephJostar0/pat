#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N, M, len, sum = 0;
    int i, j, k, t;
    scanf("%d", &N);
    vector<int> dis(N + 2, 0);
    for (i = 1; i <= N; i++) {
        scanf("%d", &j);
        sum += j;
        dis[i + 1] = sum;
    }
    cin >> M;
    for (i = 0; i < M; i++) {
        scanf("%d%d", &j, &k);
        if (j > k)
            t = j, j = k, k = t;
        len = dis[k] - dis[j];
        if (len * 2 > sum)
            len = sum - len;
        printf("%d\n", len);
    }
    return 0;
}
