#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[1] - y[1];
}

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    if (intervalsSize == 0)
    {
        return 0;
    }

    qsort(intervals, intervalsSize, sizeof(int *), compare);

    int removeCount = 0;

    int end = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] < end)
        {
            removeCount++;
        }
        else
        {
            end = intervals[i][1];
        }
    }

    return removeCount;
}

int main()
{
    int intervalsSize;

    printf("Enter number of intervals: ");
    scanf("%d", &intervalsSize);

    int **intervals = (int **)malloc(intervalsSize * sizeof(int *));
    int *intervalsColSize = (int *)malloc(intervalsSize * sizeof(int));

    for (int i = 0; i < intervalsSize; i++)
    {
        intervals[i] = (int *)malloc(2 * sizeof(int));
        intervalsColSize[i] = 2;

        printf("Enter start and end of interval %d: ", i + 1);
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    int result = eraseOverlapIntervals(intervals, intervalsSize, intervalsColSize);

    printf("Minimum intervals to remove = %d\n", result);

    for (int i = 0; i < intervalsSize; i++)
    {
        free(intervals[i]);
    }

    free(intervals);
    free(intervalsColSize);

    return 0;
}
