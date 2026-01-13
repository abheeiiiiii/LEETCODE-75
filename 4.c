#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            if ((i == 0 || flowerbed[i - 1] == 0) &&
                (i == flowerbedSize - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;
                n--;
            }
        }
    }
    return n <= 0;
}

int main() {
    int flowerbed[] = {1, 0, 0, 0, 1};
    int n = 1;
    int size = sizeof(flowerbed) / sizeof(flowerbed[0]);

    if (canPlaceFlowers(flowerbed, size, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
