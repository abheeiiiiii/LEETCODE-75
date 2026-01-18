#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    int i;
    double windowSum = 0;

    for (i = 0; i < k; i++)
        windowSum += nums[i];

    double maxSum = windowSum;

    for (i = k; i < numsSize; i++) {
        windowSum += nums[i];
        windowSum -= nums[i - k];
        if (windowSum > maxSum)
            maxSum = windowSum;
    }

    return maxSum / k;
}

int main() {
    int nums[] = {1, 12, -5, -6, 50, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 4;

    printf("%lf\n", findMaxAverage(nums, numsSize, k));
    return 0;
}
