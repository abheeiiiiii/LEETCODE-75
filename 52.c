#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *arr;
    int size;
} MinHeap;

// Create heap
MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->arr = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    return h;
}

// Push into heap
void push(MinHeap* h, int val) {
    int i = h->size++;
    h->arr[i] = val;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->arr[p] <= h->arr[i]) break;
        int temp = h->arr[p];
        h->arr[p] = h->arr[i];
        h->arr[i] = temp;
        i = p;
    }
}

// Pop min from heap
int pop(MinHeap* h) {
    int root = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;
    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;

        if (l < h->size && h->arr[l] < h->arr[smallest])
            smallest = l;
        if (r < h->size && h->arr[r] < h->arr[smallest])
            smallest = r;

        if (smallest == i) break;

        int temp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = temp;
        i = smallest;
    }
    return root;
}

// Main logic function
long long totalCost(int* costs, int costsSize, int k, int candidates) {
    MinHeap* left = createHeap(costsSize);
    MinHeap* right = createHeap(costsSize);

    int i = 0, j = costsSize - 1;

    // Fill initial heaps
    for (int c = 0; c < candidates && i <= j; c++)
        push(left, costs[i++]);

    for (int c = 0; c < candidates && i <= j; c++)
        push(right, costs[j--]);

    long long total = 0;

    for (int hire = 0; hire < k; hire++) {
        int lmin = (left->size > 0) ? left->arr[0] : INT_MAX;
        int rmin = (right->size > 0) ? right->arr[0] : INT_MAX;

        if (lmin <= rmin) {
            total += pop(left);
            if (i <= j) push(left, costs[i++]);
        } else {
            total += pop(right);
            if (i <= j) push(right, costs[j--]);
        }
    }

    return total;
}

// Driver code for VS Code
int main() {
    int costs[] = {3, 2, 7, 7, 1, 2};
    int n = sizeof(costs) / sizeof(costs[0]);
    int k = 2;
    int candidates = 2;

    long long result = totalCost(costs, n, k, candidates);
    printf("Total cost = %lld\n", result);

    return 0;
}