#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    std::string id;
    int         grade;
    Student() { grade = -1; }
} man, woman;

int main() {
    int N, i, j;
    int min = 101, max = -1;
    std::cin >> N;
    std::string n, id, g;
    for (i = 0; i < N; i++) {
        std::cin >> n >> g >> id >> j;
        if (g == "F" && j > max) {
            max         = j;
            woman.name  = n;
            woman.id    = id;
            woman.grade = j;
        } else if (g == "M" && j < min) {
            min       = j;
            man.name  = n;
            man.id    = id;
            man.grade = j;
        }
    }
    if (man.grade != -1 && woman.grade != -1)
        std::cout << woman.name << ' ' << woman.id << std::endl
                  << man.name << ' ' << man.id << std::endl
                  << (woman.grade - man.grade);
    else if (man.grade != -1)
        std::cout << "Absent\n" << man.name << ' ' << man.id << "\nNA";
    else
        std::cout << woman.name << ' ' << woman.id << "\nAbsent\nNA";
    return 0;
}
