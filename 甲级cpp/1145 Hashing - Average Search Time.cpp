#include <iostream>
#include <unordered_map>
int MSize, N, M, cnt, place[10007];
std::unordered_map<int, int> take;
bool isPrime(int size) {
    for (int i = 2; i * i <= size; i++)
        if (size % i == 0)
            return false;
    return size >= 2;
}

int my_place(int key) {
    int index = key % MSize;
    cnt = 1;
    for (int i = 0; i < MSize; i++, cnt++)
        if (place[(index + i * i) % MSize] == 0)
            return (index + i * i) % MSize;
    return -1;
}

bool my_push(int num) {
    int index = my_place(num);
    if (index == -1)
        return false;
    place[index] = 1;
    take[num] = cnt;
    return true;
}

int main() {
    scanf("%d%d%d", &MSize, &N, &M);
    while (!isPrime(MSize))
        MSize++;
    int num, search = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        if (!my_push(num))
            printf("%d cannot be inserted.\n", num);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        if (take[num])
            search += take[num];
        else {
            my_place(num);
            search += cnt;
        }
    }
    printf("%.1f", search * 1.0 / M);
    return 0;
}
