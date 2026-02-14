#include <stdio.h>
#include <stdlib.h>

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    int m = mazeSize;
    int n = mazeColSize[0];

    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int queue[10000][3];
    int front = 0, rear = 0;

    queue[rear][0] = entrance[0];
    queue[rear][1] = entrance[1];
    queue[rear][2] = 0;
    rear++;

    maze[entrance[0]][entrance[1]] = '+';

    while (front < rear) {
        int r = queue[front][0];
        int c = queue[front][1];
        int steps = queue[front][2];
        front++;

        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (maze[nr][nc] == '+') continue;

            if (nr == 0 || nc == 0 || nr == m-1 || nc == n-1)
                return steps + 1;

            maze[nr][nc] = '+';
            queue[rear][0] = nr;
            queue[rear][1] = nc;
            queue[rear][2] = steps + 1;
            rear++;
        }
    }

    return -1;
}

int main() {
    char* row1[] = {"+", "+", "."};
    char* row2[] = {".", ".", "."};
    char* row3[] = {"+", "+", "+"};

    char** maze[] = {row1, row2, row3};
    int mazeColSize[] = {3,3,3};
    int entrance[] = {1,0};

    int ans = nearestExit(maze, 3, mazeColSize, entrance, 2);
    printf("%d\n", ans);

    return 0;
}
