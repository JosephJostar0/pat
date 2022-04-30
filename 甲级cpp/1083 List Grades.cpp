#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
class Student {
public:
    char name[16];
    char id[16];
    int  grade;
};
std::vector<Student> stu_vector;

bool cmp(Student stu1, Student stu2) { return stu1.grade > stu2.grade; }

int main() {
    long long N, i;
    int       grade1, grade2, out = 0;
    scanf("%lld", &N);
    Student stu;
    for (i = 0; i < N; i++) {
        scanf("%s %s %d", stu.name, stu.id, &stu.grade);
        stu_vector.push_back(stu);
    }
    scanf("%d %d", &grade1, &grade2);
    std::sort(stu_vector.begin(), stu_vector.end(), cmp);
    for (i = 0; i < N; i++) {
        if (stu_vector[i].grade < grade1)
            break;
        if (stu_vector[i].grade <= grade2)
            printf("%s %s\n", stu_vector[i].name, stu_vector[i].id), out = 1;
    }
    if (!out)
        printf("NONE\n");
    return 0;
}
