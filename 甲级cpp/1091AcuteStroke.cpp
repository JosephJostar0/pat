#include <iostream>
#include <queue>
class Node {
public:
    int x, y, z;
    void setAll(int i, int j, int k) { x = i, y = j, z = k; }
};

int M, N, L, T;
int visit[1286][128][60], map[1286][128][60];
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
bool check(Node temp) {
    int x = temp.x, y = temp.y, z = temp.z;
    if (x >= M || x < 0 || y >= N || y < 0 || z >= L || z < 0)
        return false;
    if (visit[x][y][z] || !map[x][y][z])
        return false;
    visit[x][y][z] = 1;
    return true;
}

int BFS(int x, int y, int z) {
    Node node, temp;
    std::queue<Node> q;
    visit[x][y][z] = 1;
    node.setAll(x, y, z);
    q.push(node);
    int cnt = 0;
    while (q.size()) {
        node = q.front();
        q.pop();
        cnt++;

        for (int t = 0; t < 6; t++) {
            temp.x = node.x + X[t];
            temp.y = node.y + Y[t];
            temp.z = node.z + Z[t];
            if (check(temp))
                q.push(temp);
        }
    }
    return cnt >= T ? cnt : 0;
}

int main() {
    int i, j, k, ans = 0;
    scanf("%d%d%d%d", &M, &N, &L, &T);
    for (k = 0; k < L; k++)
        for (i = 0; i < M; i++)
            for (j = 0; j < N; j++)
                scanf("%d", &map[i][j][k]);
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < L; k++)
                if (!visit[i][j][k] && map[i][j][k])
                    ans += BFS(i, j, k);
    printf("%d", ans);
    return 0;
}
