#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Ins {
public:
    string name;
    int TWS, Ns;
};
bool cmp(Ins a, Ins b) {
    if (a.TWS != b.TWS)
        return a.TWS > b.TWS;
    if (a.Ns != b.Ns)
        return a.Ns < b.Ns;
    return a.name < b.name;
}

int main() {
    int N;
    scanf("%d", &N);
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;
    for (int i = 0; i < N; i++) {
        string id, school;
        double score;
        cin >> id >> score >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if (id[0] == 'B')
            score /= 1.5;
        else if (id[0] == 'T')
            score *= 1.5;
        sum[school] += score;
        cnt[school]++;
    }
    vector<Ins> ans;
    for (auto it : cnt)
        ans.push_back(Ins{it.first, (int)sum[it.first], cnt[it.first]});
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    int rank = 0, pre = -1;
    for (int i = 0; i < ans.size(); i++) {
        if (pre != ans[i].TWS)
            rank = i + 1;
        printf("%d %s %d %d\n", rank, ans[i].name.c_str(), ans[i].TWS, ans[i].Ns);
        pre = ans[i].TWS;
    }
    return 0;
}
