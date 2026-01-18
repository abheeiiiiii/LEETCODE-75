#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxOperations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int left = 0;
    int right = numsSize - 1;
    int operations = 0;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == k) {
            operations++;
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    return operations;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int k = 5;
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n", maxOperations(nums, size, k));
    return 0;
}
