#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void collect(struct TreeNode* root, int* arr, int* idx) {
    if (!root) return;
    if (!root->left && !root->right) {
        arr[(*idx)++] = root->val;
        return;
    }
    collect(root->left, arr, idx);
    collect(root->right, arr, idx);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int a[200], b[200];
    int i = 0, j = 0;
    collect(root1, a, &i);
    collect(root2, b, &j);
    if (i != j) return false;
    for (int k = 0; k < i; k++) {
        if (a[k] != b[k]) return false;
    }
    return true;
}

int main() {
    return 0;
}
