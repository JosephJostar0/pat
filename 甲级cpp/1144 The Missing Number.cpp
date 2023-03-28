#include <iostream>
#include <unordered_map>
std::unordered_map<int, int> map;
int main() {
    int N, temp = 1, num;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        map[num] = 1;
        while (map[temp])
            temp++;
    }
    printf("%d", temp);
    return 0;
}
