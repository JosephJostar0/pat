#include <iostream>
#include <vector>
std::vector<std::pair<int, int>> v;
int K, n, m, last, need, nine;
int getDivisor(int p, int q) {
    int x = p % q;
    while (x) {
        p = q;
        q = x;
        x = p % q;
    }
    return q;
}

bool isNeed(int t) {
    if (t <= 2 || t % 2 == 0)
        return false;
    for (int i = 3; i * i <= t; i += 2)
        if (t % i == 0)
            return false;
    return true;
}

void getAns(int temp = 0, int cnt = 0, int step = 0) {
    if (step == last) {
        if (cnt == need && temp % 10 != 9) {
            for (int j = 0; j < nine; j++)
                temp *= 10, temp += 9;
            v.push_back(std::make_pair(n, temp));
        }
        return;
    }
    temp *= 10;
    int top = std::min(9, need - cnt);
    for (int i = step ? 0 : 1; i <= top; i++)
        getAns(temp + i, cnt + i, step + 1);
}

int main() {
    int N, i, num;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d%d", &K, &m);
        printf("Case %d\n", i);
        v.clear();
        for (n = 3; n < m; n++)
            if (isNeed(getDivisor(n, m))) {
                int div = m - n;
                if (div < 8)
                    continue;
                div -= 8;
                if (div % 9)
                    continue;
                nine = 1 + div / 9;
                last = K - nine;
                need = m - nine * 9;
                getAns();
            }
        if (v.empty()) {
            printf("No Solution\n");
            continue;
        }
        for (auto it = v.begin(); it != v.end(); it++)
            printf("%d %d\n", (*it).first, (*it).second);
    }
    return 0;
}
