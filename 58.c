#include <stdio.h>
#include <stdlib.h>

void backtrack(int start, int k, int n, int* path, int pathSize,
               int** result, int* returnSize, int* returnColumnSizes) {
    
    if (pathSize == k && n == 0) {
        result[*returnSize] = (int*)malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            result[*returnSize][i] = path[i];
        }
        returnColumnSizes[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    if (pathSize > k || n < 0) return;

    for (int i = start; i <= 9; i++) {
        path[pathSize] = i;
        backtrack(i + 1, k, n - i, path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 100);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    int path[9];

    backtrack(1, k, n, path, 0, result, returnSize, *returnColumnSizes);

    return result;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    int returnSize;
    int* returnColumnSizes;

    int** result = combinationSum3(k, n, &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j != returnColumnSizes[i] - 1) printf(",");
        }
        printf("]");
        if (i != returnSize - 1) printf(", ");
        free(result[i]);
    }
    printf("]\n");

    free(result);
    free(returnColumnSizes);

    return 0;
}