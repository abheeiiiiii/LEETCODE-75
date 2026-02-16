#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int findKthLargest(int* nums, int numsSize, int k) {
    srand(time(NULL));
    int target = numsSize - k;
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];

        int lt = left, i = left, gt = right;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(&nums[i], &nums[lt]);
                i++;
                lt++;
            } else if (nums[i] > pivot) {
                swap(&nums[i], &nums[gt]);
                gt--;
            } else {
                i++;
            }
        }

        if (target >= lt && target <= gt)
            return pivot;
        else if (target < lt)
            right = lt - 1;
        else
            left = gt + 1;
    }

    return -1;
}

int main() {
    int nums[] = {3,2,1,5,6,4};
    int k = 2;
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = findKthLargest(nums, n, k);
    printf("%d\n", result);

    return 0;
}
