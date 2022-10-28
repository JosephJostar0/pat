#include <iostream>
#include <unordered_map>
#include <vector>
#define MISS 0xbaddeadbeef
class Son {
public:
    int64_t son[2];
    Son() { son[0] = son[1] = MISS; }
    void clear() { son[0] = son[1] = MISS; }
    bool isLeaf() { return son[0] == son[1] && son[0] == MISS; }
} node;
std::unordered_map<int, Son> heap;
std::vector<std::vector<int>> out;
std::vector<int> v, path;
void outHeap(int64_t temp = v[0]) {
    if (temp == MISS)
        return;
    else {
        path.push_back(temp);
        if (heap[temp].isLeaf())
            out.push_back(path);
        outHeap(heap[temp].son[1]);
        outHeap(heap[temp].son[0]);
        path.pop_back();
    }
}

int main() {
    int N, i, t, signMax = 1, signMin = 1;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &t);
        v.push_back(t);
    }
    for (i = 0; i < N; i++) {
        node.clear();
        int child = i * 2 + 1;
        for (int k = 0; k < 2; k++, child++)
            if (child < N) {
                if (v[i] < v[child])
                    signMax = 0;
                else if (v[i] > v[child])
                    signMin = 0;
                node.son[k] = v[child];
            }
        heap[v[i]] = node;
    }
    outHeap();
    for (i = 0; i < out.size(); i++) {
        path = out[i];
        printf("%d", path[0]);
        for (int j = 1; j < path.size(); j++)
            printf(" %d", path[j]);
        printf("\n");
    }
    if (signMax)
        printf("Max Heap");
    else if (signMin)
        printf("Min Heap");
    else
        printf("Not Heap");
    return 0;
}
