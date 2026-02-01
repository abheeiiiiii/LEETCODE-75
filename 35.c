#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs(struct TreeNode* root, int maxSoFar) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;

    if (root->val >= maxSoFar) {
        count = 1;
        maxSoFar = root->val;
    }

    count += dfs(root->left, maxSoFar);
    count += dfs(root->right, maxSoFar);

    return count;
}

int goodNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return dfs(root, root->val);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->left->left = newNode(3);
    root->right->left = newNode(1);
    root->right->right = newNode(5);

    printf("%d\n", goodNodes(root));

    return 0;
}
