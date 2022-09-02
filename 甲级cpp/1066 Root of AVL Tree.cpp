#include <iostream>
class Node {
public:
    int data, height;
    Node *left, *right;
    Node() { height = 1, left = NULL, right = NULL; }
};

int getHeight(Node *root) {
    if (root == NULL)
        return 0;
    return root->height;
}

void updateHeight(Node *&root) {
    int l = getHeight(root->left), r = getHeight(root->right);
    root->height = 1 + std::max(l, r);
}

int getFactor(Node *root) { return getHeight(root->left) - getHeight(root->right); }

void lTurn(Node *&root) {
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void rTurn(Node *&root) {
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(Node *&root, int key) {
    if (root == NULL) {
        root = new Node;
        root->data = key;
    } else if (key < root->data) {
        insert(root->left, key);
        updateHeight(root);
        if (getFactor(root) == 2) {
            if (getFactor(root->left) == 1) {
                rTurn(root);
            } else {
                lTurn(root->left);
                rTurn(root);
            }
        }
    } else {
        insert(root->right, key);
        updateHeight(root);
        if (getFactor(root) == -2) {
            if (getFactor(root->right) == -1) {
                lTurn(root);
            } else {
                rTurn(root->right);
                lTurn(root);
            }
        }
    }
}

int main() {
    int N, i, t;
    Node *node = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &t);
        insert(node, t);
    }
    printf("%d", node->data);
    return 0;
}
