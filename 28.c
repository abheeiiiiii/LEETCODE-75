#include <stdio.h>
#include <string.h>

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);

    int rQueue[n], dQueue[n];
    int rFront = 0, rBack = 0;
    int dFront = 0, dBack = 0;

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R')
            rQueue[rBack++] = i;
        else
            dQueue[dBack++] = i;
    }

    while (rFront < rBack && dFront < dBack) {
        int rIndex = rQueue[rFront++];
        int dIndex = dQueue[dFront++];

        if (rIndex < dIndex)
            rQueue[rBack++] = rIndex + n;
        else
            dQueue[dBack++] = dIndex + n;
    }

    return (rFront < rBack) ? "Radiant" : "Dire";
}

int main() {
    char senate[] = "RDD";
    printf("%s\n", predictPartyVictory(senate));
    return 0;
}
