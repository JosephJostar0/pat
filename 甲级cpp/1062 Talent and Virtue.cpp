#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Master {
public:
    string id;
    int    virtue;
    int    talent;
};

bool cmp(Master a, Master b) {
    int sum_a = a.talent + a.virtue;
    int sum_b = b.talent + b.virtue;
    if (sum_a == sum_b) {
        if (a.virtue == b.virtue)
            return a.id < b.id;
        return a.virtue > b.virtue;
    }
    return sum_a > sum_b;
}

int main() {
    int            N, L, H;
    Master         man;
    vector<Master> list[4];
    int            i, j;
    cin >> N >> L >> H;
    for (i = 0; i < N; i++) {
        cin >> man.id >> man.virtue >> man.talent;
        if (man.talent >= L && man.virtue >= L) {
            if (man.talent >= H && man.virtue >= H)
                list[0].push_back(man);
            else if (man.virtue >= H)
                list[1].push_back(man);
            else if (man.virtue < H && man.talent < H && man.virtue >= man.talent)
                list[2].push_back(man);
            else
                list[3].push_back(man);
        }
    }
    printf("%d", (list[0].size() + list[1].size() + list[2].size() + list[3].size()));
    for (i = 0; i < 4; i++) {
        sort(list[i].begin(), list[i].end(), cmp);
        for (j = 0; j < list[i].size(); j++)
            printf("\n%s %d %d", list[i][j].id.c_str(), list[i][j].virtue, list[i][j].talent);
    }
    return 0;
}
