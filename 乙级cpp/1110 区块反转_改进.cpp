#include <iostream>
#include <stack>
#include <vector>
std::stack<std::vector<int>> s;

int main() {
    int  start, N, K;
    int  nodes[100000], next[100000], i, add;
    bool flag = false;
    scanf("%d%d%d", &start, &N, &K);
    for (i = 0; i < N; i++) {
        scanf("%d", &add);        //存地址
        scanf("%d", &nodes[add]); //存值
        scanf("%d", &next[add]);  //存下一个
    }
    std::vector<int> part; //一块

    while (start != -1) {
        part.push_back(start);
        if (part.size() == K) {
            s.push(part);
            part.clear();
        }
        start = next[start];
    }
    if (part.size() > 0)
        s.push(part);
    while (!s.empty()) {
        part = s.top();
        s.pop();
        for (i = 0; i < part.size(); i++) {
            if (flag)
                printf("%05d\n%05d %d ", part[i], part[i], nodes[part[i]]);
            else
                printf("%05d %d ", part[i], nodes[part[i]]), flag = true;
        }
    }
    printf("-1");
    return 0;
}
