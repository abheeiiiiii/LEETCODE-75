#include <stdio.h>

char* removeStars(char* s) {
    int n = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '*') {
            if (n > 0) n--;
        } else {
            s[n++] = s[i];
        }
    }

    s[n] = '\0';
    return s;
}
