#include <stdio.h>

int longestSubarray(int* nums, int numsSize) {
    int left = 0, zeros = 0, maxLen = 0;

    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0)
            zeros++;

        while (zeros > 1) {
            if (nums[left] == 0)
                zeros--;
            left++;
        }

        if (right - left + 1 > maxLen)
            maxLen = right - left + 1;
    }

    return maxLen - 1;
}

int main() {
    int nums[] = {1, 1, 0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = longestSubarray(nums, numsSize);
    printf("Longest subarray of 1s after deleting one element: %d\n", result);

    return 0;
}
