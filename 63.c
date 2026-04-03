#include <stdio.h>

int uniquePaths(int m, int n) {
    long long res = 1;
    
    int k = (m - 1 < n - 1) ? m - 1 : n - 1;  // choose smaller
    
    for (int i = 1; i <= k; i++) {
        res = res * (m + n - 2 - k + i) / i;
    }
    
    return (int)res;
}

int main() {
    int m, n;

    printf("Enter rows (m): ");
    scanf("%d", &m);

    printf("Enter columns (n): ");
    scanf("%d", &n);

    int result = uniquePaths(m, n);

    printf("Number of unique paths: %d\n", result);

    return 0;
}