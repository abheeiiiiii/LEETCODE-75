#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    int freq[2001] = {0};

    for (int i = 0; i < arrSize; i++) {
        freq[arr[i] + 1000]++;
    }

    int seen[2001] = {0};

    for (int i = 0; i < 2001; i++) {
        if (freq[i] > 0) {
            if (seen[freq[i]])
                return false;
            seen[freq[i]] = 1;
        }
    }

    return true;
}
