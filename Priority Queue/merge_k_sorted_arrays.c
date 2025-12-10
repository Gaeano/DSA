#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_HEAP_SIZE 1000

typedef struct {
    int value;
    int arrayIndex;
    int elementIndex;
} HeapNode;

typedef struct {
    HeapNode data[MAX_HEAP_SIZE];
    int size;
} MinHeap;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// TODO: Implement these functions
void minHeapify(MinHeap* heap, int idx) {
    // Your code here
    int parent = (idx - 1) / 2;
    
    if (parent < heap->size && heap->data[idx].value < heap->data[parent].value){
        swap(&heap->data[parent], &heap->data[idx]);
        minHeapify(heap, parent);
    }
}

void downHeapify(MinHeap * heap, int idx){
    int smallest = idx;
    
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < heap->size && heap->data[left].value < heap->data[smallest].value){
        smallest = left;
    }
    
    if (right < heap->size && heap->data[right].value < heap->data[smallest].value){
        smallest = right;
    }
    
    if (smallest != idx){
        swap(&heap->data[smallest], &heap->data[idx]);
        downHeapify(heap, smallest);
    }
}

void insertHeap(MinHeap* heap, HeapNode node) {
    // Your code here
    heap->data[heap->size] = node;
    minHeapify(heap, heap->size);
    heap->size++;
}

HeapNode extractMin(MinHeap* heap) {
    // Your code here
    HeapNode min = heap->data[0];
    
    heap->data[0] = heap->data[heap->size-1];
    
    heap->size--;
    
    downHeapify(heap, 0);
    
    return min;
    
}



int* mergeKArrays(int** arrays, int* sizes, int k, int* resultSize) {
    // Your code here
    int i, j;
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    
    
    for (i = 0; i < k ; i++){
        for (j = 0; j < sizes[i]; j++){
            HeapNode node = {arrays[i][j], i, j};
            insertHeap(heap, node);
        }
    }
    
    int orig = heap->size;
    int* results = malloc (heap->size * sizeof(int));
    for (i = 0; i < orig; i++){
        HeapNode node = extractMin(heap);
        results[i] = node.value;
    }
    heap->size = orig;
    *resultSize = heap->size;
    free(heap);
    return results;
}

int main() {
    // Test case: 3 sorted arrays
    int arr1[] = {1, 4, 7};
    int arr2[] = {2, 5, 8};
    int arr3[] = {3, 6, 9};
    int* arrays[] = {arr1, arr2, arr3};
    int sizes[] = {3, 3, 3};
    int k = 3;
    int resultSize;
    
    int* result = mergeKArrays(arrays, sizes, k, &resultSize);
    
    printf("Merged array: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result);
    return 0;
}