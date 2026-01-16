#include <stdio.h>
#include <stdlib.h>

char* reverseWords(char* s) {
    int n = 0;
    while (s[n] != '\0') n++;

    char* res = (char*)malloc(n + 1);
    int k = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            int end = i;
            while (i >= 0 && s[i] != ' ') i--;

            for (int j = i + 1; j <= end; j++)
                res[k++] = s[j];

            res[k++] = ' ';
        }
    }

    if (k > 0) k--;
    res[k] = '\0';

    return res;
}

int main() {
    char s[] = "the sky is blue";

    char* result = reverseWords(s);

    printf("Reversed Words: \"%s\"\n", result);

    free(result);
    return 0;
}
