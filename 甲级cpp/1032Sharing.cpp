#include <iostream>
#include <stack>
#define MAXN 100000
char letter[MAXN];
int  next[MAXN];

int main() {
    int words[2], N, i, ans = -1;
    scanf("%d %d %d\n", words, words + 1, &N);
    for (i = 0; i < N; i++) {
        int id;
        scanf("%d ", &id);
        scanf("%c %d", letter + id, next + id);
    }
    std::stack<int> s[2];
    for (i = 0; i < 2; i++)
        while (words[i] != -1)
            s[i].push(words[i]), words[i] = next[words[i]];
    while (s[0].size() && s[1].size() && s[0].top() == s[1].top()) {
        ans = s[0].top();
        s[0].pop(), s[1].pop();
    }
    ans >= 0 ? printf("%05d", ans) : printf("-1");
    return 0;
}
