#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    int to;
    double val;
    struct Edge* next;
} Edge;

typedef struct {
    char* name;
    Edge* head;
} Node;

Node graph[100];
int nodeCount = 0;

int getIndex(char* name) {
    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(graph[i].name, name) == 0)
            return i;
    }
    graph[nodeCount].name = name;
    graph[nodeCount].head = NULL;
    return nodeCount++;
}

void addEdge(int u, int v, double val) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->val = val;
    e->next = graph[u].head;
    graph[u].head = e;
}

double dfs(int u, int target, int* visited) {
    if (u == target) return 1.0;

    visited[u] = 1;
    Edge* e = graph[u].head;

    while (e) {
        if (!visited[e->to]) {
            double res = dfs(e->to, target, visited);
            if (res != -1.0)
                return res * e->val;
        }
        e = e->next;
    }
    return -1.0;
}

/* ===== calcEquation function ===== */
double* calcEquation(char*** equations, int equationsSize, int* equationsColSize,
                     double* values, int valuesSize,
                     char*** queries, int queriesSize, int* queriesColSize,
                     int* returnSize) {

    nodeCount = 0;

    for (int i = 0; i < equationsSize; i++) {
        int u = getIndex(equations[i][0]);
        int v = getIndex(equations[i][1]);

        addEdge(u, v, values[i]);
        addEdge(v, u, 1.0 / values[i]);
    }

    double* ans = (double*)malloc(sizeof(double) * queriesSize);
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        char* start = queries[i][0];
        char* end = queries[i][1];

        int s = -1, t = -1;
        for (int j = 0; j < nodeCount; j++) {
            if (strcmp(graph[j].name, start) == 0) s = j;
            if (strcmp(graph[j].name, end) == 0) t = j;
        }

        if (s == -1 || t == -1) {
            ans[i] = -1.0;
        } else {
            int visited[100] = {0};
            ans[i] = dfs(s, t, visited);
        }
    }

    return ans;
}

/* ===== main function for local testing ===== */
int main() {
    char* eq1[] = {"a", "b"};
    char* eq2[] = {"b", "c"};
    char** equations[] = {eq1, eq2};
    int equationsColSize[] = {2,2};
    double values[] = {2.0, 3.0};

    char* q1[] = {"a", "c"};
    char* q2[] = {"b", "a"};
    char** queries[] = {q1, q2};
    int queriesColSize[] = {2,2};

    int returnSize;
    double* ans = calcEquation(equations, 2, equationsColSize,
                               values, 2,
                               queries, 2, queriesColSize,
                               &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%f\n", ans[i]);
    }

    free(ans);
    return 0;
}
