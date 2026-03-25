#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize) {
    int prev2 = cost[0];
    int prev1 = cost[1];
    
    for (int i = 2; i < costSize; i++) {
        int curr = cost[i] + (prev1 < prev2 ? prev1 : prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1 < prev2 ? prev1 : prev2;
}

int main() {
    int n;
    scanf("%d", &n);

    int cost[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }

    int result = minCostClimbingStairs(cost, n);
    printf("%d\n", result);

    return 0;
}