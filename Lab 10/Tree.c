#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int val;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &val);

    if (val == -1) return NULL;

    struct Node* node = createNode(val);
    printf("Enter left child of %d:\n", val);
    node->left = createTree();
    printf("Enter right child of %d:\n", val);
    node->right = createTree();

    return node;
}

void printTree(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
    struct Node* root = createTree();
    printf("Tree (pre-order traversal): ");
    printTree(root);
    return 0;
}

