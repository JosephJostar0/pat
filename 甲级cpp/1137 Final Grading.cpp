#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Stu {
public:
    int gs[3], G;
    double g;
    Stu() { fill(gs, gs + 3, -1); }
    bool check() {
        if (gs[0] < 200)
            return false;
        g = (gs[1] <= gs[2]) ? (1.0 * gs[2]) : (0.4 * gs[1] + 0.6 * gs[2]);
        G = (int)g;
        if (g - G >= 0.5)
            G++;
        return G >= 60;
    }
};
std::unordered_map<string, Stu> stus;
std::vector<string> stu_pass;
bool cmp(string a, string b) {
    if (stus[a].G != stus[b].G)
        return stus[a].G > stus[b].G;
    return a < b;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string temp;
    int score, in[3];
    cin >> in[0] >> in[1] >> in[2];
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < in[j]; i++) {
            cin >> temp >> score;
            stus[temp].gs[j] = score;
            if (j == 2 && stus[temp].check())
                stu_pass.push_back(temp);
        }
    sort(stu_pass.begin(), stu_pass.end(), cmp);
    for (auto it : stu_pass) {
        Stu cur = stus[it];
        cout << it << ' ' << cur.gs[0] << ' ' << cur.gs[1] << ' ' << cur.gs[2] << ' ' << cur.G << '\n';
    }
    return 0;
}
