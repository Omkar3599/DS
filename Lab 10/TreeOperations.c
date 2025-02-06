#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderTraversal(TreeNode* root) {
    TreeNode* stack[100];
    int top = -1;
    TreeNode* current = root;

    while (top != -1 || current) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->val);
        current = current->right;
    }
    printf("\n");
}

void postOrderTraversal(TreeNode* root) {
    TreeNode* stack[100];
    int top = -1;
    TreeNode* current = root;
    TreeNode* lastVisited = NULL;

    while (top != -1 || current) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }
        TreeNode* peekNode = stack[top];
        if (peekNode->right && lastVisited != peekNode->right) {
            current = peekNode->right;
        } else {
            printf("%d ", peekNode->val);
            lastVisited = stack[top--];
        }
    }
    printf("\n");
}

void preOrderTraversal(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        TreeNode* current = stack[top--];
        printf("%d ", current->val);

        if (current->right) stack[++top] = current->right;
        if (current->left) stack[++top] = current->left;
    }
    printf("\n");
}

TreeNode* findParent(TreeNode* root, int value) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return NULL;
    }
    if ((root->left && root->left->val == value) || (root->right && root->right->val == value)) {
        return root;
    }
    TreeNode* parent = findParent(root->left, value);
    if (parent) return parent;
    return findParent(root->right, value);
}

int printDepth(TreeNode* root) {
    if (root == NULL) return 0;
    int leftDepth = printDepth(root->left);
    int rightDepth = printDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int printAncestors(TreeNode* root, int value) {
    if (root == NULL) return 0;
    if (root->val == value) return 1;

    if (printAncestors(root->left, value) || printAncestors(root->right, value)) {
        printf("%d ", root->val);
        return 1;
    }
    return 0;
}

int countLeafNodes(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("In-order traversal: ");
    inOrderTraversal(root);

    printf("Post-order traversal: ");
    postOrderTraversal(root);

    printf("Pre-order traversal: ");
    preOrderTraversal(root);

    int valueToFind = 5;
    TreeNode* parent = findParent(root, valueToFind);
    if (parent) {
        printf("Parent of %d: %d\n", valueToFind, parent->val);
    } else {
        printf("Parent of %d: NULL\n", valueToFind);
    }

    printf("Depth of the tree: %d\n", printDepth(root));

    printf("Ancestors of %d: ", valueToFind);
    printAncestors(root, valueToFind);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
