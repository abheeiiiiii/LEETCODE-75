#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mapping[] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char* digits, int index, char* current, char** result, int* returnSize) {
    if (digits[index] == '\0') {
        current[index] = '\0';
        result[*returnSize] = (char*)malloc(index + 1);
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    char *letters = mapping[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;

    if (!digits || strlen(digits) == 0) {
        return NULL;
    }

    int maxSize = 1;
    for (int i = 0; digits[i]; i++) {
        int len = strlen(mapping[digits[i] - '0']);
        maxSize *= len;
    }

    char** result = (char**)malloc(sizeof(char*) * maxSize);
    char current[5];

    backtrack(digits, 0, current, result, returnSize);

    return result;
}

int main() {
    char digits[10];
    scanf("%s", digits);

    int returnSize = 0;
    char** result = letterCombinations(digits, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", result[i]);
        if (i != returnSize - 1) printf(", ");
        free(result[i]);
    }
    printf("]\n");

    free(result);
    return 0;
}