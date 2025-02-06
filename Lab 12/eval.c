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
        if(isPrime(current->val)){
        printf("%d ", current->val);}
        current = current->right;
    }
    printf("\n");
}

int isPrime(int n){
    int flag = 1;
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            flag = 0;
        }
    }
    if(flag){
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int arr[20];
    TreeNode* root1;
    printf("Enter the numbers(-1 to stop): ");
    for(int i=0;arr[i]!=-1;i++){
        scanf("%d", &arr[i]);
        if(arr[i]==-1){
            break;
        }
        //scanf("%d", &arr[i]);
        root1 = createNode(arr[i]);
    }




   TreeNode* root = createNode(5);
    root->left = createNode(18);
    root->right = createNode(45);
    root->left->left = createNode(21);
    root->left->right = createNode(19);
    root->right->left = createNode(9);
    root->right->right = createNode(7);

    printf("Prime numbers: ");
    inOrderTraversal(root);

    return 0;
    }


