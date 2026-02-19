#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n1;
    int n2;
} Pair;

int cmp(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    return p2->n2 - p1->n2;
}

void heapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) break;
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent;
    }
}

void heapifyDown(int* heap, int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index) break;

        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;
        index = smallest;
    }
}

long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    int n = nums1Size;

    Pair* arr = (Pair*)malloc(sizeof(Pair) * n);
    for (int i = 0; i < n; i++) {
        arr[i].n1 = nums1[i];
        arr[i].n2 = nums2[i];
    }

    qsort(arr, n, sizeof(Pair), cmp);

    int* heap = (int*)malloc(sizeof(int) * k);
    int heapSize = 0;
    long long sum = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        if (heapSize < k) {
            heap[heapSize] = arr[i].n1;
            sum += arr[i].n1;
            heapifyUp(heap, heapSize);
            heapSize++;
        } else if (arr[i].n1 > heap[0]) {
            sum -= heap[0];
            heap[0] = arr[i].n1;
            sum += arr[i].n1;
            heapifyDown(heap, heapSize, 0);
        }

        if (heapSize == k) {
            long long score = sum * arr[i].n2;
            if (score > ans)
                ans = score;
        }
    }

    free(arr);
    free(heap);
    return ans;
}

int main() {
    int nums1[] = {1, 3, 3, 2};
    int nums2[] = {2, 1, 3, 4};
    int k = 3;

    int n = sizeof(nums1) / sizeof(nums1[0]);

    long long result = maxScore(nums1, n, nums2, n, k);
    printf("%lld\n", result);

    return 0;
}
