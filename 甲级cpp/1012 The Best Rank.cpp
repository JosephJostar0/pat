#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int now = 0;

class Student {
public:
    int  id;
    int  grade[4];
    int  level[4];
    void set() {
        cin >> id >> grade[1] >> grade[2] >> grade[3];
        grade[0] = grade[1] + grade[2] + grade[3];
        level[0] = 1, level[1] = 1, level[2] = 1, level[3] = 1;
    }
};

bool cmp(Student s1, Student s2) { return s1.grade[now] > s2.grade[now]; }

int main() {
    Student student;
    char    sign[4] = {'A', 'C', 'M', 'E'};
    int     N, M;
    int     i, j, k, t, p, q;
    cin >> N >> M;
    vector<Student> list;
    for (i = 0; i < N; i++) {
        student.set();
        list.push_back(student);
    }
    for (now = 0; now < 4; now++) {
        sort(list.begin(), list.end(), cmp);
        for (i = 1; i < N; i++) {
            if (list[i].grade[now] == list[i - 1].grade[now])
                list[i].level[now] = list[i - 1].level[now];
            else
                list[i].level[now] = i + 1;
        }
    }
    for (i = 0; i < M; i++) {
        cin >> k;
        p = 0, q = N + 1;
        for (j = 0; j < N; j++)
            if (list[j].id == k)
                break;
        if (j == N) {
            printf("N/A\n");
            continue;
        }
        for (t = 0; t < 4; t++)
            if (list[j].level[t] < q)
                q = list[j].level[t], p = t;
        printf("%d %c\n", q, sign[p]);
    }
    return 0;
}
