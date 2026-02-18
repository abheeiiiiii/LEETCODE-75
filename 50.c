#include <stdio.h>
#include <stdlib.h>

void logError(const char *msg) {
    FILE *fp = fopen("error_log.txt", "a");
    if (fp == NULL) return;
    fprintf(fp, "%s\n", msg);
    fclose(fp);
}

int main() {
    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Error: File not found\n");
        logError("Error: File not found");
        return 1;
    }

    int x;
    if (fscanf(fp, "%d", &x) != 1) {
        printf("Error: Invalid data in file\n");
        logError("Error: Invalid data in file");
        fclose(fp);
        return 1;
    }

    printf("Value = %d\n", x);

    fclose(fp);
    return 0;
}
