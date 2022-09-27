#include <iostream>
#include <string>
#define MAXN 21
using namespace std;
string arr[MAXN];
int child[MAXN][2], isSon[MAXN];
void postOrder(int root) {
    if (root != -1) {
        printf("(");
        if (child[root][0] > 0) {
            postOrder(child[root][0]);
            postOrder(child[root][1]);
            printf("%s", arr[root].c_str());
        } else {
            printf("%s", arr[root].c_str());
            postOrder(child[root][1]);
        }
        printf(")");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, i, dad;
    cin >> N;
    for (i = 1; i <= N; i++) {
        cin >> arr[i] >> child[i][0] >> child[i][1];
        if (child[i][0] > 0)
            isSon[child[i][0]] = 1;
        if (child[i][1] > 0)
            isSon[child[i][1]] = 1;
    }
    for (dad = 1; dad <= N; dad++)
        if (!isSon[dad])
            break;
    postOrder(dad);
    return 0;
}
