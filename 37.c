#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxLen;

void dfs(struct TreeNode* node, int dir, int len) {
    if (!node) return;

    if (len > maxLen)
        maxLen = len;

    if (dir == 0) {
        dfs(node->right, 1, len + 1);
        dfs(node->left, 0, 1);
    } else {
        dfs(node->left, 0, len + 1);
        dfs(node->right, 1, 1);
    }
}

int longestZigZag(struct TreeNode* root) {
    if (!root) return 0;

    maxLen = 0;
    dfs(root->left, 0, 1);
    dfs(root->right, 1, 1);

    return maxLen;
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);
    root->right->left->right = newNode(4);

    printf("%d\n", longestZigZag(root));
    return 0;
}
