#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int maxLevelSum(struct TreeNode* root) {
    if (!root) return 0;

    struct TreeNode* queue[20000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int level = 0;
    int maxLevel = 1;
    long long maxSum = root->val;

    while (front < rear) {
        int levelSize = rear - front;
        long long currSum = 0;
        level++;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            currSum += node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        if (currSum > maxSum) {
            maxSum = currSum;
            maxLevel = level;
        }
    }

    return maxLevel;
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(7);
    root->right = newNode(0);
    root->left->left = newNode(7);
    root->left->right = newNode(-8);

    int result = maxLevelSum(root);
    printf("%d\n", result);

    return 0;
}
