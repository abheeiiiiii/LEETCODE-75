#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to find GCD of two integers */
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Function to find GCD of strings */
char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    /* Check if str1 + str2 == str2 + str1 */
    char* s1 = (char*)malloc(len1 + len2 + 1);
    char* s2 = (char*)malloc(len1 + len2 + 1);

    strcpy(s1, str1);
    strcat(s1, str2);

    strcpy(s2, str2);
    strcat(s2, str1);

    if (strcmp(s1, s2) != 0) {
        free(s1);
        free(s2);
        return "";
    }

    free(s1);
    free(s2);

    int gcdLen = gcd(len1, len2);

    /* Allocate result */
    char* result = (char*)malloc(gcdLen + 1);
    strncpy(result, str1, gcdLen);
    result[gcdLen] = '\0';

    return result;
}

int main() {
    char str1[] = "ABCABC";
    char str2[] = "ABC";

    char* result = gcdOfStrings(str1, str2);
    printf("GCD of Strings: %s\n", result);
   printf("Hello, World!\n");
    return 0;
}
