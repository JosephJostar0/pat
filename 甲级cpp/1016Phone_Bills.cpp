#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Record {
public:
    char name[25];
    int  month, day, hour, min;
    bool type; // true为接通,false为挂断
    void getValue() {
        char how[10];
        scanf("%s", name);
        scanf("%d:%d:%d:%d", &month, &day, &hour, &min);
        scanf("%s", how);
        type = strcmp(how, "on-line") == 0;
    }
};

vector<Record> records;
Record         record;
int            money[24];

bool cmp(Record r1, Record r2) {
    int t = strcmp(r1.name, r2.name);
    if (t != 0)
        return t < 0;
    else if (r1.month != r2.month)
        return r1.month < r2.month;
    else if (r1.day != r2.day)
        return r1.day < r2.day;
    else if (r1.hour != r2.hour)
        return r1.hour < r2.hour;
    return r1.min < r2.min;
}

int getCost(Record start, Record over, int &min) {
    double cost = 0;
    min         = 0;
    while (start.day < over.day || start.hour < over.hour || start.min < over.min) {
        min++;
        cost += money[start.hour];
        start.min++;
        if (start.min == 60) {
            start.min = 0;
            start.hour++;
        }
        if (start.hour == 24) {
            start.hour = 0;
            start.day++;
        }
    }
    return cost;
}

int main() {
    int N, i, p, q, total, people, isPrint, min, cost;
    for (i = 0; i < 24; i++)
        scanf("%d", &money[i]);
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        record.getValue();
        records.push_back(record);
    }
    sort(records.begin(), records.end(), cmp);
    for (i = 0; i < N; i = people) {
        for (people = i, isPrint = 0; people < N && strcmp(records[people].name, records[i].name) == 0; people++) {
            if (isPrint == 0 && records[people].type == true)
                isPrint = 1;
            else if (isPrint == 1 && records[people].type == false)
                isPrint = 2;
        }
        if (isPrint != 2)
            continue;
        printf("%s %02d\n", records[i].name, records[i].month);
        total = 0, p = -1, q = -1;
        while (i < people) {
            if (records[i].type == true)
                p = i;
            else if (records[i].type == false)
                q = i;
            if (p != -1 && q != -1 && p + 1 == q) {
                cost = getCost(records[p], records[q], min);
                total += cost;
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", records[p].day, records[p].hour, records[p].min,
                       records[q].day, records[q].hour, records[q].min, min, (double)cost / 100.0);
                p = -1, q = -1;
            }
            i++;
        }
        printf("Total amount: $%.2f\n", (double)total / 100.0);
    }
    return 0;
}
