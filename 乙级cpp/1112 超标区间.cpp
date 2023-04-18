#include <iostream>
#include <vector>
#define MAXN 10001
int main() {
    int N, T, value[MAXN], top = 0;
    std::vector<std::pair<int, int>> v;
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++) {
        scanf("%d", value + i);
        top = std::max(top, value[i]);
        if (value[i] > T) {
            if (!v.empty() && v.back().second == i - 1)
                v.back().second = i;
            else
                v.push_back(std::make_pair(i, i));
        }
    }
    for (auto it : v)
        printf("[%d, %d]\n", it.first, it.second);
    if (v.empty())
        printf("%d", top);
    return 0;
}
