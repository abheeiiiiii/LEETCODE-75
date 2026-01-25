#include <stdlib.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(sizeof(int) * asteroidsSize);
    int top = -1;

    for (int i = 0; i < asteroidsSize; i++) {
        int a = asteroids[i];
        int alive = 1;

        while (alive && top >= 0 && stack[top] > 0 && a < 0) {
            if (stack[top] < -a) {
                top--;
            } else if (stack[top] == -a) {
                top--;
                alive = 0;
            } else {
                alive = 0;
            }
        }

        if (alive) {
            stack[++top] = a;
        }
    }

    *returnSize = top + 1;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = stack[i];
    }

    free(stack);
    return result;
}
