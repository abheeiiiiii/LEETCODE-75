#include <stdio.h>

#define MOD 1000000007

int numTilings(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    long a = 1, b = 1, c = 2, d;

    for (int i = 3; i <= n; i++) {
        d = (2 * c % MOD + a % MOD) % MOD;
        a = b;
        b = c;
        c = d;
    }

    return (int)c;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", numTilings(n));

    return 0;
}