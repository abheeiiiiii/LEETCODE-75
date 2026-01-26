#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    int n = strlen(s);
    int numStack[1000], numTop = -1;
    char* strStack[1000];
    int strTop = -1;

    char* curr = (char*)calloc(1, sizeof(char));
    int currLen = 0;

    for (int i = 0; i < n; ) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            numStack[++numTop] = num;
        } 
        else if (s[i] == '[') {
            strStack[++strTop] = curr;
            curr = (char*)calloc(1, sizeof(char));
            currLen = 0;
            i++;
        } 
        else if (s[i] == ']') {
            int repeat = numStack[numTop--];
            char* prev = strStack[strTop--];

            int prevLen = strlen(prev);
            char* temp = (char*)malloc(prevLen + repeat * currLen + 1);
            strcpy(temp, prev);

            for (int r = 0; r < repeat; r++) {
                strcat(temp, curr);
            }

            free(prev);
            free(curr);
            curr = temp;
            currLen = strlen(curr);
            i++;
        } 
        else {
            curr = (char*)realloc(curr, currLen + 2);
            curr[currLen++] = s[i++];
            curr[currLen] = '\0';
        }
    }
    return curr;
}
