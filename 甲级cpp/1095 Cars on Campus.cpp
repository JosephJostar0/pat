#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class CarRecord {
public:
    char plate[8];
    int  time;
    bool type; // in为true out为false
    void getAll() {
        int  h, m, s;
        char how[4];
        scanf("%s %d:%d:%d %s", plate, &h, &m, &s, how);
        time = h * 3600 + m * 60 + s;
        type = strcmp("in", how) == 0;
    }
};

bool cmp(CarRecord c1, CarRecord c2) {
    if (strcmp(c1.plate, c2.plate))
        return strcmp(c1.plate, c2.plate) < 0;
    return c1.time < c2.time;
}
std::unordered_map<std::string, int> parkTime;

int main() {
    int N, K;
    int i, park_max = 0, p = 0, q = 0, h, m, s, t, parking = 0;
    scanf("%d %d", &N, &K);
    std::vector<CarRecord>   carRecords(N);
    std::vector<int>         in_time, out_time;
    std::vector<std::string> park_long;
    for (i = 0; i < N; i++)
        carRecords[i].getAll();
    std::sort(carRecords.begin(), carRecords.end(), cmp);
    for (i = 0; i < N - 1; i++)
        if (carRecords[i].type && !carRecords[i + 1].type && !strcmp(carRecords[i].plate, carRecords[i + 1].plate)) {
            in_time.push_back(carRecords[i].time);
            out_time.push_back(carRecords[i + 1].time);
            parkTime[carRecords[i].plate] += carRecords[i + 1].time - carRecords[i].time;
            if (parkTime[carRecords[i].plate] > park_max) {
                park_long.clear();
                park_max = parkTime[carRecords[i].plate];
                park_long.push_back(carRecords[i].plate);
            } else if (parkTime[carRecords[i].plate] == park_max)
                park_long.push_back(carRecords[i].plate);
        }
    std::sort(in_time.begin(), in_time.end());
    std::sort(out_time.begin(), out_time.end());
    for (i = 0; i < K; i++) {
        scanf("%d:%d:%d", &h, &m, &s);
        t = h * 3600 + m * 60 + s;
        while (p < in_time.size() && in_time[p] <= t)
            parking++, p++;
        while (q < out_time.size() && out_time[q] <= t)
            parking--, q++;
        printf("%d\n", parking);
    }
    for (i = 0; i < park_long.size(); i++)
        printf("%s ", park_long[i].c_str());
    printf("%02d:%02d:%02d", park_max / 3600, park_max % 3600 / 60, park_max % 3600 % 60);
    return 0;
}
