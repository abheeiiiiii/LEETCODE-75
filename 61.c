#include <stdio.h>

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int prev1 = 0; 
    int prev2 = 0; 

    for (int i = 0; i < numsSize; i++) {
        int take = prev2 + nums[i];
        int skip = prev1;

        int curr = (take > skip) ? take : skip;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;

  
    printf("Enter number of houses: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter money in each house:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int result = rob(nums, n);
    printf("Maximum money you can rob: %d\n", result);

    return 0;
}