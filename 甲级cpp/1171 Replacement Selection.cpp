#include <algorithm>
#include <iostream>
#include <queue>
int main() {
    int N, M, last;
    std::vector<int> v, out, next;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);
        v.push_back(n);
    }
    auto it = v.begin();
    while (heap.size() < M)
        heap.push(*it), it++;
    while (it != v.end() || !heap.empty()) {
        last = heap.top();
        out.push_back(last);
        heap.pop();
        if (it != v.end()) {
            if (*it > last)
                heap.push(*it);
            else
                next.push_back(*it);
            it++;
        }
        if (heap.empty()) {
            printf("%d", out[0]);
            for (int i = 1; i < out.size(); i++)
                printf(" %d", out[i]);
            printf("\n");
            out.clear();
            for (int i = 0; i < next.size(); i++)
                heap.push(next[i]);
            next.clear();
        }
    }
    return 0;
}
