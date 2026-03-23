#include <stdio.h>

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int a = 0, b = 1, c = 1, d;

    for (int i = 3; i <= n; i++) {
        d = a + b + c;  // Tn = Tn-1 + Tn-2 + Tn-3
        a = b;
        b = c;
        c = d;
    }

    return c;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int result = tribonacci(n);

    printf("Tribonacci(%d) = %d\n", n, result);

    return 0;
}