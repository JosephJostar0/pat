#include <iostream>
#include <queue>
#include <string>
#define MAXN 31
#define MAXV 1001
int N, temp, isFull;
int post[MAXN], in[MAXN];
int isSon[MAXV], node[MAXV][2], rank[MAXV];
int getTree(int l = 0, int r = N) {
    if (l == r)
        return -1;
    int i;
    for (i = l; i < r; i++)
        if (in[i] == post[temp])
            break;
    if (i == r)
        return -1;
    temp--;
    node[in[i]][1] = getTree(i + 1, r);
    node[in[i]][0] = getTree(l, i);
    isSon[node[in[i]][0]] = isSon[node[in[i]][1]] = 1;
    return in[i];
}

int levelOrder(int root = post[N - 1]) {
    int level = 0, last = root, flag = 1, pre, temp;
    std::queue<int> q;
    q.push(root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        rank[temp] = level;
        if (node[temp][0] == -1 || node[temp][1] == -1)
            if (node[temp][0] != node[temp][1])
                flag = 0;

        for (int i = 0; i < 2; i++)
            if (node[temp][i] != -1)
                q.push(node[temp][i]), pre = node[temp][i];
        if (temp == last) {
            level++;
            last = pre;
        }
    }
    return flag;
}

void isTrue() {
    int a, b, flag = 0, i;
    std::string line;
    std::getline(std::cin, line);
    if (line.find("root") != -1) {
        sscanf(line.c_str(), "%d is the root", &a);
        if (!isSon[a])
            flag = 1;
    } else if (line.find("siblings") != -1) {
        sscanf(line.c_str(), "%d and %d are siblings", &a, &b);
        for (i = 0; i < N; i++) {
            if (node[in[i]][0] == a && node[in[i]][1] == b)
                flag = 1;
            else if (node[in[i]][0] == b && node[in[i]][1] == a)
                flag = 1;
        }
    } else if (line.find("parent") != -1) {
        sscanf(line.c_str(), "%d is the parent of %d", &a, &b);
        if (node[a][0] == b || node[a][1] == b)
            flag = 1;
    } else if (line.find("left") != -1) {
        sscanf(line.c_str(), "%d is the left child of %d", &a, &b);
        if (node[b][0] == a)
            flag = 1;
    } else if (line.find("right") != -1) {
        sscanf(line.c_str(), "%d is the right child of %d", &a, &b);
        if (node[b][1] == a)
            flag = 1;
    } else if (line.find("level") != -1) {
        sscanf(line.c_str(), "%d and %d are on the same level", &a, &b);
        if (rank[a] == rank[b])
            flag = 1;
    } else {
        if (isFull)
            flag = 1;
    }
    printf("%s\n", flag ? "Yes" : "No");
}

int main() {
    int M, i, t;
    std::fill(node[0], node[0] + MAXV * 2, -1);
    scanf("%d", &N), temp = N - 1;
    for (i = 0; i < N; i++)
        scanf("%d", post + i);
    for (i = 0; i < N; i++)
        scanf("%d", in + i);
    getTree();
    isFull = levelOrder();
    scanf("%d\n", &M);
    for (i = 0; i < M; i++)
        isTrue();
    return 0;
}
