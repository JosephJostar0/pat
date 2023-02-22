#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class Student {
public:
    std::string id;
    int score;
} stu;
std::unordered_map<char, std::vector<Student>> one;          // 等级索引
std::unordered_map<int, std::pair<int, int>> two;            // 考场索引
std::unordered_map<int, std::unordered_map<int, int>> three; // 记录某日某考场人数
std::unordered_map<int, std::vector<int>> three_;            // 记录某日有哪些考场
int temp;

void f() {
    one[stu.id[0]].push_back(stu);
    std::string str = stu.id.substr(1, 3);
    int site = std::stoi(str);
    str = stu.id.substr(4, 6);
    int date = std::stoi(str);
    two[site].first++, two[site].second += stu.score;
    if (three[date][site] == 0)
        three_[date].push_back(site);
    three[date][site]++;
}

bool cmp1(Student s1, Student s2) {
    if (s1.score != s2.score)
        return s1.score > s2.score;
    return s1.id < s2.id;
}

bool cmp3(int site1, int site2) {
    if (three[temp][site1] != three[temp][site2])
        return three[temp][site1] > three[temp][site2];
    return site1 < site2;
}

int main() {
    int N, M, type;
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> stu.id >> stu.score;
        f();
    }
    std::sort(one['A'].begin(), one['A'].end(), cmp1);
    std::sort(one['B'].begin(), one['B'].end(), cmp1);
    std::sort(one['T'].begin(), one['T'].end(), cmp1);
    for (int i = 1; i <= M; i++) {
        std::cout << "Case " << i;
        std::cin >> type;
        std::string str;

        switch (type) {
        case 1:
            char c;
            std::cin >> c;
            std::cout << ": 1 " << c << '\n';
            if (one[c].empty())
                std::cout << "NA\n";
            else
                for (auto it = one[c].begin(); it != one[c].end(); it++)
                    std::cout << (*it).id << ' ' << (*it).score << '\n';
            break;
        case 2:
            std::cin >> str;
            temp = std::stoi(str);
            std::cout << ": 2 " << str << '\n';
            if (two[temp].first == 0)
                std::cout << "NA\n";
            else
                std::cout << two[temp].first << ' ' << two[temp].second << '\n';
            break;
        case 3:
            std::cin >> str;
            std::cout << ": 3 " << str << '\n';
            temp = std::stoi(str);
            if (three[temp].size() == 0)
                std::cout << "NA\n";
            else {
                std::sort(three_[temp].begin(), three_[temp].end(), cmp3);
                for (auto it = three_[temp].begin(); it != three_[temp].end(); it++)
                    std::cout << *it << ' ' << three[temp][*it] << '\n';
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
