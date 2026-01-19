#include <stdio.h>
#include <stdbool.h>

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(char* s, int k) {
    int count = 0, maxCount = 0;

    for (int i = 0; i < k; i++) {
        if (isVowel(s[i]))
            count++;
    }

    maxCount = count;

    for (int i = k; s[i] != '\0'; i++) {
        if (isVowel(s[i]))
            count++;
        if (isVowel(s[i - k]))
            count--;

        if (count > maxCount)
            maxCount = count;
    }

    return maxCount;
}

int main() {
    char s[] = "abciiidef";
    int k = 3;

    int result = maxVowels(s, k);
    printf("Maximum number of vowels in any substring of length %d: %d\n", k, result);

    return 0;
}
