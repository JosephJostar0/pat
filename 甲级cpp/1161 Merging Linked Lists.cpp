#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 100001
int data[MAXN], next[MAXN];
std::vector<int> v, v1, v2;
int main() {
    int N, i, add1, add2;
    scanf("%d%d%d", &add1, &add2, &N);
    for (i = 0; i < N; i++) {
        int current;
        scanf("%d", &current);
        scanf("%d%d", data + current, next + current);
    }
    for (int temp = add1; temp != -1; temp = next[temp])
        v1.push_back(temp);
    for (int temp = add2; temp != -1; temp = next[temp])
        v2.push_back(temp);
    if (v2.size() > v1.size())
        std::swap(v1, v2);
    std::reverse(v2.begin(), v2.end());
    i = 2;
    printf("%05d %d ", v1[0], data[v1[0]]);
    printf("%05d\n%05d %d ", v1[1], v1[1], data[v1[1]]);
    printf("%05d\n%05d %d ", v2[0], v2[0], data[v2[0]]);
    for (int j = 1; j < v2.size(); j++) {
        for (int k = 0; k < 2; k++, i++)
            printf("%05d\n%05d %d ", v1[i], v1[i], data[v1[i]]);
        printf("%05d\n%05d %d ", v2[j], v2[j], data[v2[j]]);
    }
    while (i < v1.size())
        printf("%05d\n%05d %d ", v1[i], v1[i], data[v1[i]]), i++;
    printf("-1");
    return 0;
}
