#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
std::vector<int> level;
int              N, K, M;
class Student {
public:
    int                          pass, total;
    std::unordered_map<int, int> problem;
    bool                         live;
    Student() { pass = 0, total = 0, live = true; }
    void commit(int user_id, int pro_id, int score, bool flag) {
        if (score > problem[pro_id]) {
            total -= problem[pro_id];
            total += score;
            problem[pro_id] = score;
            if (flag)
                pass++;
        }
        if (live && score >= 0)
            live = false, level.push_back(user_id);
    }
    void out_score() {
        printf(" %d", total);
        for (int j = 1; j <= K; j++) {
            if (problem.find(j) == problem.end())
                printf(" -");
            else
                printf(" %d", problem[j]);
        }
        printf("\n");
    }
};
std::unordered_map<int, Student> User;

bool cmp(int a, int b) {
    if (User[a].total != User[b].total)
        return User[a].total > User[b].total;
    if (User[a].pass != User[b].pass)
        return User[a].pass > User[b].pass;
    return a < b;
}

int main() {
    int user_id, problem_id, score;
    int i, pre_rank = 0, pre_score = 0xbadbeef;
    scanf("%d %d %d", &N, &K, &M);
    std::vector<int> p(K + 1, 0);
    for (i = 1; i <= K; i++)
        scanf("%d", &p[i]);
    for (i = 0; i < M; i++) {
        scanf("%d %d %d", &user_id, &problem_id, &score);
        User[user_id].commit(user_id, problem_id, score, score == p[problem_id]);
    }
    std::sort(level.begin(), level.end(), cmp);
    for (i = 0; i < level.size(); i++) {
        if (User[level[i]].total != pre_score)
            pre_score = User[level[i]].total, pre_rank = i + 1;
        printf("%d %05d", pre_rank, level[i]);
        User[level[i]].out_score();
    }
    return 0;
}
