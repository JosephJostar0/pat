#include <iostream>
#include <vector>
#define MAXM 101
std::vector<int> temp;
int coins[MAXM];
bool findAns(int top, int min = 1) {
    if (top == 0)
        return true;
    for (int i = min; i <= top; i++) {
        if (!coins[i])
            continue;
        coins[i]--;
        temp.push_back(i);
        if (findAns(top - i, i))
            return true;
        temp.pop_back();
        coins[i]++;
    }
    return false;
}

int main() {
    int N, M, i;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        if (t < MAXM)
            coins[t]++;
    }
    if (!findAns(M))
        printf("No Solution\n");
    else {
        printf("%d", temp[0]);
        for (i = 1; i < temp.size(); i++)
            printf(" %d", temp[i]);
    }
    return 0;
}