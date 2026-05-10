#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

char*** suggestedProducts(char** products, int productsSize, char* searchWord,
                          int* returnSize, int** returnColumnSizes) {

    qsort(products, productsSize, sizeof(char*), compare);

    int n = strlen(searchWord);

    char*** result = (char***)malloc(n * sizeof(char**));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    char prefix[1001];

    for (int i = 0; i < n; i++) {

        prefix[i] = searchWord[i];
        prefix[i + 1] = '\0';

        result[i] = (char**)malloc(3 * sizeof(char*));

        int count = 0;

        for (int j = 0; j < productsSize && count < 3; j++) {

            if (strncmp(products[j], prefix, i + 1) == 0) {

                result[i][count] =
                    (char*)malloc(strlen(products[j]) + 1);

                strcpy(result[i][count], products[j]);

                count++;
            }
        }

        (*returnColumnSizes)[i] = count;
    }

    *returnSize = n;

    return result;
}

int main() {

    char* products[] = {
        "mobile",
        "mouse",
        "moneypot",
        "monitor",
        "mousepad"
    };

    int productsSize = 5;

    char searchWord[] = "mouse";

    int returnSize;

    int* returnColumnSizes;

    char*** ans = suggestedProducts(
        products,
        productsSize,
        searchWord,
        &returnSize,
        &returnColumnSizes
    );

    printf("Output:\n");

    for (int i = 0; i < returnSize; i++) {

        printf("[");

        for (int j = 0; j < returnColumnSizes[i]; j++) {

            printf("\"%s\"", ans[i][j]);

            if (j != returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }

        printf("]\n");
    }

    for (int i = 0; i < returnSize; i++) {

        for (int j = 0; j < returnColumnSizes[i]; j++) {
            free(ans[i][j]);
        }

        free(ans[i]);
    }

    free(ans);
    free(returnColumnSizes);

    return 0;
}