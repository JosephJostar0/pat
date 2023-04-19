#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
int N, M, K;
std::unordered_map<int, std::vector<int>> table;
std::unordered_map<int, std::unordered_map<int, int>> G;
std::vector<std::pair<int, int>> temp;
std::unordered_map<int, int> gender;
int main() {
    int u, v;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        std::string num1, num2;
        std::cin >> num1 >> num2;
        u = std::abs(std::stoi(num1));
        v = std::abs(std::stoi(num2));
        gender[u] = num1[0] == '-' ? 1 : 0;
        gender[v] = num2[0] == '-' ? 1 : 0;
        G[u][v] = 1, G[v][u] = 1;
        table[u].push_back(v);
        table[v].push_back(u);
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        temp.clear();
        scanf("%d%d", &u, &v);
        u = std::abs(u), v = std::abs(v);
        for (auto it : table[u])
            if (gender[it] == gender[u] && it != v && it != u)
                for (auto it2 : table[it])
                    if (gender[it2] == gender[v] && it2 != v && it2 != u)
                        if (G[it2][v])
                            temp.push_back(std::make_pair(it, it2));
        std::sort(temp.begin(), temp.end());
        printf("%d\n", temp.size());
        for (auto it : temp)
            printf("%04d %04d\n", it.first, it.second);
    }
    return 0;
}
