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

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    int* result = (int*)malloc(sizeof(int) * 1000);
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        int rightVal = 0;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            rightVal = node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        result[(*returnSize)++] = rightVal;
    }

    return result;
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);

    int returnSize;
    int* result = rightSideView(root, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    free(result);
    return 0;
}
