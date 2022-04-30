#include <algorithm>
#include <iostream>
#include <vector>
int N, M, K;
class Student {
public:
    int  Ge, Gi, sum, id;
    int  choices[5];
    void getAll(int i) {
        int j;
        scanf("%d %d", &Ge, &Gi);
        for (j = 0; j < K; j++)
            scanf("%d", &choices[j]);
        sum = Ge + Gi;
        id  = i;
    }
};

class School {
public:
    int              place;
    int              latest;
    std::vector<int> offer;
    School() { latest = place = 0; }
    void giveOffer(int id, int rank) {
        offer.push_back(id);
        latest = rank;
        place--;
    }
    void outResult() {
        bool flag = false;
        int  i;
        std::sort(offer.begin(), offer.end());
        for (i = 0; i < offer.size(); i++) {
            if (flag)
                printf(" ");
            printf("%d", offer[i]);
            flag = true;
        }
        printf("\n");
    }
};

bool cmp(Student stu1, Student stu2) {
    if (stu1.sum != stu2.sum)
        return stu1.sum > stu2.sum;
    if (stu1.Ge != stu2.Ge)
        return stu1.Ge > stu2.Ge;
    return stu1.id < stu2.id;
}

int main() {
    int i, j, preGe = -1, preSum = -1, preRank = -1;
    scanf("%d %d %d", &N, &M, &K);
    std::vector<School>  schools(M);
    std::vector<Student> stu_vector(N);
    for (i = 0; i < M; i++)
        scanf("%d", &schools[i].place);
    for (i = 0; i < N; i++)
        stu_vector[i].getAll(i);
    std::sort(stu_vector.begin(), stu_vector.end(), cmp);
    for (i = 0; i < N; i++) {
        if (!(preSum == stu_vector[i].sum && preGe == stu_vector[i].Ge)) {
            preRank = i;
            preSum  = stu_vector[i].sum;
            preGe   = stu_vector[i].Ge;
        }
        for (j = 0; j < K; j++) {
            if (schools[stu_vector[i].choices[j]].latest == preRank) {
                schools[stu_vector[i].choices[j]].giveOffer(stu_vector[i].id, preRank);
                break;
            } else if (schools[stu_vector[i].choices[j]].place > 0) {
                schools[stu_vector[i].choices[j]].giveOffer(stu_vector[i].id, preRank);
                break;
            }
        }
    }
    for (i = 0; i < M; i++)
        schools[i].outResult();
    return 0;
}
