#include <stdio.h>
#include <string.h>

int compress(char* chars, int charsSize) {
    int idx = 0;

    for (int i = 0; i < charsSize; ) {
        char ch = chars[i];
        int count = 0;

        while (i < charsSize && chars[i] == ch) {
            i++;
            count++;
        }

        chars[idx++] = ch;

        if (count > 1) {
            char buffer[12];
            int len = sprintf(buffer, "%d", count);
            for (int j = 0; j < len; j++) {
                chars[idx++] = buffer[j];
            }
        }
    }
    return idx;
}

int main() {
    char chars[] = {'a','a','b','b','c','c','c'};
    int size = sizeof(chars) / sizeof(chars[0]);

    int newLength = compress(chars, size);

    printf("Compressed Length: %d\n", newLength);
    printf("Compressed Array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%c ", chars[i]);
    }

    return 0;
}
