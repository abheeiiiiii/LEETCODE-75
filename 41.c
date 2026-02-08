#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;

    if (root->val == val) return root;
    else if (val < root->val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    int val = 2;

    struct TreeNode* result = searchBST(root, val);

    if (result != NULL)
        printf("Found subtree root with value: %d\n", result->val);
    else
        printf("Value not found in BST\n");

    return 0;
}
