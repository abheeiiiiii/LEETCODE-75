#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int *x = *(int **)a;
    int *y = *(int **)b;

    if (x[1] < y[1])
        return -1;

    if (x[1] > y[1])
        return 1;

    return 0;
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize)
{
    if (pointsSize == 0)
    {
        return 0;
    }

    qsort(points, pointsSize, sizeof(int *), compare);

    int arrows = 1;

    long long end = points[0][1];

    for (int i = 1; i < pointsSize; i++)
    {
        if (points[i][0] > end)
        {
            arrows++;
            end = points[i][1];
        }
    }

    return arrows;
}

int main()
{
    int pointsSize;

    printf("Enter number of balloons: ");
    scanf("%d", &pointsSize);

    int **points = (int **)malloc(pointsSize * sizeof(int *));
    int *pointsColSize = (int *)malloc(pointsSize * sizeof(int));

    for (int i = 0; i < pointsSize; i++)
    {
        points[i] = (int *)malloc(2 * sizeof(int));
        pointsColSize[i] = 2;

        printf("Enter xstart and xend for balloon %d: ", i + 1);
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int result = findMinArrowShots(points, pointsSize, pointsColSize);

    printf("Minimum arrows needed = %d\n", result);

    for (int i = 0; i < pointsSize; i++)
    {
        free(points[i]);
    }

    free(points);
    free(pointsColSize);

    return 0;
}