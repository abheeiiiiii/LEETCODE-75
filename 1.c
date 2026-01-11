#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* mergeAlternately(char* word1, char* word2) {
    int n1 = strlen(word1), n2 = strlen(word2);
    char* result = (char*)malloc((n1 + n2 + 1) * sizeof(char));

    int i = 0, j = 0, k = 0;
    while (i < n1 || j < n2) {
        if (i < n1) result[k++] = word1[i++];
        if (j < n2) result[k++] = word2[j++];
    }
    result[k] = '\0'; 
    return result;
}
int main() {
    char word1[] = "abc";
    char word2[] = "pqr";
    char* merged = mergeAlternately(word1, word2);
    printf("Result: %s\n", merged);
    free(merged);
    printf("Hello, World!\n");
    return 0;
}
