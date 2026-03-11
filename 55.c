#include <stdio.h>

int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int peak = findPeakElement(nums, n);

    printf("Peak element index: %d\n", peak);
    printf("Peak element value: %d\n", nums[peak]);

    return 0;
}