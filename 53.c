#include <stdio.h>

// Global variable to simulate picked number
int pick = 6;

// Simulated guess API
int guess(int num) {
    if (num > pick)
        return -1;
    else if (num < pick)
        return 1;
    else
        return 0;
}

int guessNumber(int n) {
    int left = 1, right = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = guess(mid);

        if (res == 0)
            return mid;
        else if (res == -1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    int n = 10;     // range 1 to n
    pick = 6;       // change this to test different cases

    int result = guessNumber(n);
    printf("Picked number is: %d\n", result);

    return 0;
}