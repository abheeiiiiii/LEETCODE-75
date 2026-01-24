#include <stdlib.h>

int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int count = 0;

    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridSize; c++) {
            int k = 0;
            while (k < gridSize && grid[r][k] == grid[k][c]) {
                k++;
            }
            if (k == gridSize)
                count++;
        }
    }

    return count;
}
