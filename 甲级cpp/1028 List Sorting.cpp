#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
int C;
class Student {
public:
    char save[3][10];
    int  grade;
    void getAll() {
        std::cin >> save[0] >> save[1] >> grade;
        sprintf(save[2], "%02d", grade);
    }
};

bool cmp(Student stu1, Student stu2) {
    if (strcmp(stu1.save[C], stu2.save[C]) == 0)
        return stu1.save[0] < stu2.save[0];
    return strcmp(stu1.save[C], stu2.save[C]) < 0;
}

int main() {
    std::vector<Student> stu_vector;
    Student              student;
    int                  N, i;
    std::cin >> N >> C;
    for (i = 0; i < N; i++) {
        student.getAll();
        stu_vector.push_back(student);
    }
    C--;
    std::sort(stu_vector.begin(), stu_vector.end(), cmp);
    for (i = 0; i < N; i++)
        printf("%s %s %d\n", stu_vector[i].save[0], stu_vector[i].save[1], stu_vector[i].grade);
    return 0;
}
