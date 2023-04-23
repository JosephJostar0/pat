#include <iostream>
#include <unordered_map>
#define MAXN 50001
int N, pre[MAXN], temp, step;
std::unordered_map<int, int> alter_in;
int make_tree(int l = 0, int r = N) {
    if (l == r)
        return -1;
    int root = pre[step++];
    int root_id = alter_in[root];
    int lson = make_tree(l, root_id);
    int rson = make_tree(root_id + 1, r);
    if (lson == rson && rson == -1) {
        printf("%d", root);
        exit(0);
    }
    return root;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", pre + i);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        alter_in[temp] = i;
    }
    make_tree();
    return 0;
}
