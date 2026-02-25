#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    qsort(potions, potionsSize, sizeof(int), cmp);

    int* result = (int*)malloc(sizeof(int) * spellsSize);
    *returnSize = spellsSize;

    for (int i = 0; i < spellsSize; i++) {
        long long need = (success + spells[i] - 1) / spells[i];
        int left = 0, right = potionsSize - 1, pos = potionsSize;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)potions[mid] >= need) {
                pos = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        result[i] = potionsSize - pos;
    }

    return result;
}

int main() {
    int spells[] = {5, 1, 3};
    int potions[] = {1, 2, 3, 4, 5};
    long long success = 7;

    int spellsSize = sizeof(spells) / sizeof(spells[0]);
    int potionsSize = sizeof(potions) / sizeof(potions[0]);

    int returnSize;
    int* result = successfulPairs(spells, spellsSize, potions, potionsSize, success, &returnSize);

    printf("Successful pairs:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}