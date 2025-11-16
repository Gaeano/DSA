#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(char *arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    char *arr[] = {"Charlie", "Alice", "Bob", "Eve", "David", "Frank"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array of names: ");
    printArray(arr, n);

    // Perform Heap Sort (sorts alphabetically A-Z)
    heapSort(arr, n);

    printf("Sorted array of names:   ");
    printArray(arr, n);

    return 0;
}