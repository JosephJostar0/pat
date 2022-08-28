#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
std::vector<int> current, result;
int N, K, P, preSum = 0, top;
int getPow(int num) {
    int ans = 1;
    for (int i = 0; i < P; i++)
        ans *= num;
    return ans;
}

void dfs(int sum = 0, int now = 0, int margin = top) {
    if (sum > N)
        return;
    if (current.size() == K) {
        if (sum == N) {
            if (now > preSum) {
                preSum = now;
                result = current;
            } else if (now == preSum)
                result = std::max(result, current);
        }
    }
    for (int i = margin; i; i--) {
        int pow = getPow(i);
        if (pow * (K - current.size()) < N - sum)
            break;
        current.push_back(i);
        dfs(sum + pow, now + i, i);
        current.pop_back();
    }
}

int main() {
    scanf("%d%d%d", &N, &K, &P);
    while (getPow(top + 1) <= N)
        top++;
    dfs();
    if (result.empty()) {
        printf("Impossible");
        return 0;
    }
    printf("%d = %d^%d", N, result[0], P);
    for (int i = 1; i < result.size(); i++)
        printf(" + %d^%d", result[i], P);
    return 0;
}
