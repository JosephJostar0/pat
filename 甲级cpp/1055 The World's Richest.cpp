#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
class Rich {
public:
    char name[10];
    int  age, worth;
    void getAll() { scanf("%s %d %d", name, &age, &worth); }
};
std::unordered_map<int, int> map;
std::vector<Rich>            rich_vector, result_vector;

bool cmp(Rich r1, Rich r2) {
    if (r1.worth != r2.worth)
        return r1.worth > r2.worth;
    if (r1.age != r2.age)
        return r1.age < r2.age;
    return strcmp(r1.name, r2.name) < 0;
}

int main() {
    Rich rich;
    int  i, N, K;
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) {
        rich.getAll();
        rich_vector.push_back(rich);
    }
    std::sort(rich_vector.begin(), rich_vector.end(), cmp);
    for (i = 0; i < N; i++)
        if (map[rich_vector[i].age] < 100)
            result_vector.push_back(rich_vector[i]), map[rich_vector[i].age]++;
    int needed, min_age, max_age, j, out_num;
    for (i = 1; i <= K; i++) {
        scanf("%d %d %d", &needed, &min_age, &max_age);
        out_num = 0;
        printf("Case #%d:\n", i);
        for (j = 0; out_num < needed && j < result_vector.size(); j++)
            if (result_vector[j].age >= min_age && result_vector[j].age <= max_age) {
                out_num++;
                printf("%s %d %d\n", result_vector[j].name, result_vector[j].age, result_vector[j].worth);
            }
        if (!out_num)
            printf("None\n");
    }
    return 0;
}
