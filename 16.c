#include <stdio.h>

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, zeros = 0, maxLen = 0;

    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0)
            zeros++;

        while (zeros > k) {
            if (nums[left] == 0)
                zeros--;
            left++;
        }

        int currLen = right - left + 1;
        if (currLen > maxLen)
            maxLen = currLen;
    }

    return maxLen;
}

int main() {
    int nums[] = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = longestOnes(nums, size, k);
    printf("Longest subarray length: %d\n", result);

    return 0;
}
