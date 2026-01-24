#include <stdbool.h>
#include <string.h>

bool closeStrings(char* word1, char* word2) {
    int freq1[26] = {0}, freq2[26] = {0};
    int len1 = strlen(word1), len2 = strlen(word2);

    if (len1 != len2) return false;

    for (int i = 0; i < len1; i++) {
        freq1[word1[i] - 'a']++;
        freq2[word2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if ((freq1[i] == 0) != (freq2[i] == 0))
            return false;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (freq1[i] > freq1[j]) {
                int t = freq1[i];
                freq1[i] = freq1[j];
                freq1[j] = t;
            }
            if (freq2[i] > freq2[j]) {
                int t = freq2[i];
                freq2[i] = freq2[j];
                freq2[j] = t;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i])
            return false;
    }

    return true;
}
