#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[idx++] = nums[i];
        }
    }

    while (idx < numsSize) {
        nums[idx++] = 0;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int size = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, size);

    printf("Array after moving zeroes: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
