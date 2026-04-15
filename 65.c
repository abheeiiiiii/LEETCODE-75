#include <stdio.h>

int maxProfit(int* prices, int pricesSize, int fee) {
    if (pricesSize == 0) return 0;

    int hold = -prices[0];
    int cash = 0;

    for (int i = 1; i < pricesSize; i++) {
        int prev_cash = cash;
        if (hold + prices[i] - fee > cash)
            cash = hold + prices[i] - fee;
        if (prev_cash - prices[i] > hold)
            hold = prev_cash - prices[i];
    }

    return cash;
}

int main() {
    int prices[] = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    int n = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, n, fee);
    printf("%d\n", result);

    return 0;
}