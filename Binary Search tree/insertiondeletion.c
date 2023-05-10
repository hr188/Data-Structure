#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int d) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = d;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertIntoBst(Node* root, int d) {
    if (root == NULL) {
        root = createNode(d);
        return root;
    }
    if (d > root->data) {
        root->right = insertIntoBst(root->right, d);
    } else {
        root->left = insertIntoBst(root->left, d);
    }
    return root;
}

void takeInput(Node** root) {
    int data;
    scanf("%d", &data);
    while (data != -1) {
        *root = insertIntoBst(*root, data);
        scanf("%d", &data);
    }
}

int main() {
    Node* root = NULL;
    takeInput(&root);
    return 0;
}
