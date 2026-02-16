#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r;
    int c;
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    Node queue[rows * cols];
    int front = 0, rear = 0;
    int fresh = 0;

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2)
                queue[rear++] = (Node){i, j};
            else if (grid[i][j] == 1)
                fresh++;
        }
    }

    if (fresh == 0) return 0;

    int minutes = 0;

    while (front < rear) {
        int size = rear - front;
        int rotted = 0;

        for (int i = 0; i < size; i++) {
            Node curr = queue[front++];

            for (int d = 0; d < 4; d++) {
                int nr = curr.r + dir[d][0];
                int nc = curr.c + dir[d][1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    queue[rear++] = (Node){nr, nc};
                    fresh--;
                    rotted = 1;
                }
            }
        }

        if (rotted) minutes++;
    }

    return fresh == 0 ? minutes : -1;
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int* gridColSize = (int*)malloc(sizeof(int));
    gridColSize[0] = cols;

    int result = orangesRotting(grid, rows, gridColSize);
    printf("%d\n", result);

    for (int i = 0; i < rows; i++)
        free(grid[i]);
    free(grid);
    free(gridColSize);

    return 0;
}
