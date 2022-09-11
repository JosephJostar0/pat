#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class student {
public:
    int time;
    int count;
    student() { time = 0, count = 0; }
    void plus(int t) { time += t, count++; };
};
std::unordered_map<int, student> m;

std::vector<int> v;

bool cmp(int a, int b) {
    student p = m[a], q = m[b];
    if (p.time == q.time) {
        if (p.count == q.count)
            return a < b;
        return p.count > q.count;
    }
    return p.time > q.time;
}

int main() {
    int N;
    int t, num, top = 0;
    int i, j, k;
    scanf("%d", &N);
    int id;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &t, &num);
        for (j = 0; j < num; j++) {
            std::cin >> id;
            m[id].plus(t);
            if (m[id].time > top) {
                v.clear();
                top = m[id].time;
                v.push_back(id);
            } else if (m[id].time == top)
                v.push_back(id);
        }
    }
    std::sort(v.begin(), v.end(), cmp);
    j = m[v[0]].count, k = m[v[0]].time;
    printf("%d %d\n%05d", k, j, v[0]);
    for (i = 1; i < v.size() && m[v[i]].time == k && m[v[i]].count == j; i++)
        printf(" %05d", v[i]);
    return 0;
}