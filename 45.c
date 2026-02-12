#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

typedef struct {
    int to;
    int cost;
    int next;
} Edge;

Edge graph[MAXN * 2];
int head[MAXN];
int visited[MAXN];
int idx = 0;
int ans = 0;

void addEdge(int u, int v, int cost) {
    graph[idx].to = v;
    graph[idx].cost = cost;
    graph[idx].next = head[u];
    head[u] = idx++;
}

void dfs(int u) {
    visited[u] = 1;
    for (int i = head[u]; i != -1; i = graph[i].next) {
        int v = graph[i].to;
        int cost = graph[i].cost;
        if (!visited[v]) {
            ans += cost;
            dfs(v);
        }
    }
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    for (int i = 0; i < n; i++) {
        head[i] = -1;
        visited[i] = 0;
    }

    idx = 0;
    ans = 0;

    for (int i = 0; i < connectionsSize; i++) {
        int a = connections[i][0];
        int b = connections[i][1];

        addEdge(a, b, 1);
        addEdge(b, a, 0);
    }

    dfs(0);
    return ans;
}

int main() {
    int n = 6;
    int data[5][2] = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    int* connections[5];

    for (int i = 0; i < 5; i++)
        connections[i] = data[i];

    int colSize[5] = {2,2,2,2,2};

    printf("Answer = %d\n", minReorder(n, connections, 5, colSize));
    return 0;
}
