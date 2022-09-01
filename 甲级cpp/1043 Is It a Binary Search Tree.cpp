#include <iostream>
#include <vector>
#define MAXN 1000 + 1
class BST {
public:
    int data;
    BST *l, *r;
    BST() { l = NULL, r = NULL; }
} * root;

void insert(BST *&root, int key) {
    if (root == NULL) {
        root = new BST;
        root->data = key;
        return;
    }
    if (key >= root->data)
        insert(root->r, key);
    else
        insert(root->l, key);
}

int flag = 0, seq[MAXN];
std::vector<int> v;

void postOrder(BST *root) {
    if (root) {
        postOrder(root->l);
        postOrder(root->r);
        if (flag)
            printf(" ");
        printf("%d", root->data);
        flag = 1;
    }
}

void postOrder_mirror(BST *root) {
    if (root) {
        postOrder_mirror(root->r);
        postOrder_mirror(root->l);
        if (flag)
            printf(" ");
        printf("%d", root->data);
        flag = 1;
    }
}

void preOrder(BST *root) {
    if (root) {
        v.push_back(root->data);
        preOrder(root->l);
        preOrder(root->r);
    }
}

void preOrder_mirror(BST *root) {
    if (root) {
        v.push_back(root->data);
        preOrder_mirror(root->r);
        preOrder_mirror(root->l);
    }
}

bool isBST(BST *root) {
    v.clear();
    preOrder(root);
    for (int i = 0; i < v.size(); i++)
        if (v[i] != seq[i])
            return false;
    return true;
}

bool isMirror(BST *root) {
    v.clear();
    preOrder_mirror(root);
    for (int i = 0; i < v.size(); i++)
        if (v[i] != seq[i])
            return false;
    return true;
}

int main() {
    int N, i;
    scanf("%d", &N);
    root = NULL;
    for (i = 0; i < N; i++) {
        scanf("%d", seq + i);
        insert(root, seq[i]);
    }
    if (isBST(root)) {
        printf("YES\n");
        postOrder(root);
    } else if (isMirror(root)) {
        printf("YES\n");
        postOrder_mirror(root);
    } else
        printf("NO\n");
    return 0;
}
