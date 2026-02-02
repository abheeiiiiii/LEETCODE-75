#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countFromNode(struct TreeNode* root, long sum) {
    if (root == NULL) return 0;
    return (root->val == sum)
         + countFromNode(root->left, sum - root->val)
         + countFromNode(root->right, sum - root->val);
}

int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) return 0;
    return countFromNode(root, targetSum)
         + pathSum(root->left, targetSum)
         + pathSum(root->right, targetSum);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(-3);
    root->left->left = newNode(3);
    root->left->right = newNode(2);
    root->right->right = newNode(11);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(-2);
    root->left->right->right = newNode(1);

    int targetSum = 8;
    printf("%d\n", pathSum(root, targetSum));

    return 0;
}
