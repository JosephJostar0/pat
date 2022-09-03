#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
int N, K;
std::string top;
std::unordered_map<std::string, int> phone, visit;
std::unordered_map<std::string, std::vector<std::string>> G;

int BFS(std::string id) {
    std::queue<std::string> q;
    std::string temp;
    visit[id] = 1;
    top = id;
    q.push(id);
    int cnt = 0, tel = 0;
    while (!q.empty()) {
        temp = q.front(), q.pop(), cnt++, tel += phone[temp];
        if (phone[temp] > phone[top])
            top = temp;
        for (auto it = G[temp].begin(); it != G[temp].end(); it++)
            if (!visit[*it])
                q.push(*it), visit[*it] = 1;
    }
    tel /= 2;
    return tel > K ? cnt : 0;
}

bool cmp(std::pair<std::string, int> p1, std::pair<std::string, int> p2) { return p1.first < p2.first; }

int main() {
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int i, weight;
    std::string n1, n2;
    std::vector<std::pair<std::string, int>> v;
    std::cin >> N >> K;
    for (i = 0; i < N; i++) {
        std::cin >> n1 >> n2 >> weight;
        phone[n1] += weight;
        phone[n2] += weight;
        G[n1].push_back(n2), G[n2].push_back(n1);
    }
    for (auto it = phone.begin(); it != phone.end(); it++) {
        if (visit[(*it).first] != 0)
            continue;
        weight = BFS((*it).first);
        if (weight > 2)
            v.push_back(std::make_pair(top, weight));
    }
    std::sort(v.begin(), v.end(), cmp);
    std::cout << v.size() << std::endl;
    for (auto it = v.begin(); it != v.end(); it++)
        std::cout << (*it).first << ' ' << (*it).second << std::endl;
    return 0;
}
