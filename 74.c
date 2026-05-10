#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int* answer = (int*)malloc(sizeof(int) * temperaturesSize);

    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);

    int top = -1;

    for (int i = 0; i < temperaturesSize; i++)
    {
        answer[i] = 0;
    }

    for (int i = 0; i < temperaturesSize; i++)
    {
        while (top != -1 &&
               temperatures[i] > temperatures[stack[top]])
        {
            int index = stack[top--];

            answer[index] = i - index;
        }

        stack[++top] = i;
    }

    free(stack);

    *returnSize = temperaturesSize;

    return answer;
}

int main()
{
    int temperaturesSize;

    printf("Enter number of days: ");
    scanf("%d", &temperaturesSize);

    int* temperatures = (int*)malloc(sizeof(int) * temperaturesSize);

    printf("Enter temperatures:\n");

    for (int i = 0; i < temperaturesSize; i++)
    {
        scanf("%d", &temperatures[i]);
    }

    int returnSize;

    int* result = dailyTemperatures(
        temperatures,
        temperaturesSize,
        &returnSize
    );

    printf("Output:\n");

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(temperatures);
    free(result);

    return 0;
}
