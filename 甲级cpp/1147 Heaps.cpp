#include <iostream>
#include <unordered_map>
#define MAXN 1001
int M, N, nodes[MAXN], max_h, min_h, flag;
std::unordered_map<int, std::pair<int, int>> tree;
void check_tree(int index) {
    int son1 = index * 2 + 1, son2 = index * 2 + 2;
    if (son1 < N) {
        if (son2 < N) {
            if (nodes[index] <= nodes[son1])
                if (nodes[index] <= nodes[son2])
                    min_h++;
            if (nodes[index] >= nodes[son1])
                if (nodes[index] >= nodes[son2])
                    max_h++;
            check_tree(son1), check_tree(son2);
        } else {
            if (nodes[index] <= nodes[son1])
                min_h++;
            if (nodes[index] >= nodes[son1])
                max_h++;
            check_tree(son1);
        }
    } else
        min_h++, max_h++;
}

void post_order(int root = 0) {
    if (root < N) {
        post_order(root * 2 + 1);
        post_order(root * 2 + 2);
        if (flag)
            printf(" %d", nodes[root]);
        else {
            flag = 1;
            printf("%d", nodes[root]);
        }
    }
}

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++) {
        tree.clear(), max_h = 0, min_h = 0, flag = 0;
        for (int j = 0; j < N; j++)
            scanf("%d", nodes + j);
        check_tree(0);
        if (max_h == N)
            printf("Max Heap\n");
        else if (min_h == N)
            printf("Min Heap\n");
        else
            printf("Not Heap\n");
        post_order();
        printf("\n");
    }
    return 0;
}
