#include <stdio.h>

long long calculateHours(int* piles, int pilesSize, int k) {
    long long hours = 0;
    for (int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k;
    }
    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1, right = piles[0];
    for (int i = 1; i < pilesSize; i++) {
        if (piles[i] > right) right = piles[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long hours = calculateHours(piles, pilesSize, mid);

        if (hours <= h) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int piles[] = {3, 6, 7, 11};
    int h = 8;
    int n = sizeof(piles) / sizeof(piles[0]);

    printf("%d\n", minEatingSpeed(piles, n, h));
    return 0;
}