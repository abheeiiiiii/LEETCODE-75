#include <stdio.h>
#include <stdlib.h>

void dfs(int** isConnected, int n, int city, int* visited) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, n, i, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int* visited = (int*)calloc(n, sizeof(int));
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            dfs(isConnected, n, i, visited);
        }
    }

    free(visited);
    return count;
}

int main() {
    int n = 3;

    int data[3][3] = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    int* isConnected[3];
    for (int i = 0; i < n; i++) {
        isConnected[i] = data[i];
    }

    int colSize[3] = {3,3,3};

    int result = findCircleNum(isConnected, n, colSize);
    printf("Provinces = %d\n", result);

    return 0;
}
