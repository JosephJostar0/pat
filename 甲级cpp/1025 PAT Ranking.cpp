#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Student {
public:
    string no;
    int    grade;
    int    part;
};

bool cmp(Student a, Student b) {
    if (a.grade == b.grade)
        return a.no < b.no;
    return a.grade > b.grade;
}

int main() {
    vector<Student> list;
    vector<int>     rank, high, count;
    string          no;
    Student         stu;
    int             N, K;
    int             i, j, grade, last, level = 1;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &K);
        rank.push_back(1);
        high.push_back(0);
        count.push_back(0);
        for (j = 0; j < K; j++) {
            std::cin >> no >> grade;
            if (grade > high[i])
                high[i] = grade;
            stu.grade = grade;
            stu.no    = no;
            stu.part  = i + 1;
            list.push_back(stu);
        }
    }
    sort(list.begin(), list.end(), cmp);
    printf("%d\n", list.size());
    for (i = 0, last = list[0].grade; i < list.size(); i++) {
        count[list[i].part - 1]++;
        if (last > list[i].grade)
            level = i + 1, last = list[i].grade;
        if (high[list[i].part - 1] > list[i].grade)
            rank[list[i].part - 1] = count[list[i].part - 1], high[list[i].part - 1] = list[i].grade;
        printf("%s %d %d %d\n", list[i].no.c_str(), level, list[i].part, rank[list[i].part - 1]);
    }
    return 0;
}
