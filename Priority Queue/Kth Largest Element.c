#include <stdio.h>

#define MAX 5

void swap (int* a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void upHeapify (int* arr, int size, int index){
    int parent = (index - 1) /2;

    if (arr[parent] < arr[index]){
        swap(&arr[parent], &arr[index]);
        index = parent;
        upHeapify(arr, size, index);
    }
}

void downHeapify(int* arr, int size, int index){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != index){
        swap(&arr[largest], &arr[index]);
        downHeapify(arr, size, largest);
    }
}

int extractMax(int* arr, int* size){
    int max = arr[0];
    (*size)--;
    arr[0] = arr[*size];

    downHeapify(arr, *size, 0);

    return max;
}

void buildMaxHeap(int* arr, int size){
    int parent = (size - 1) / 2;
    int i;
    for (i = parent; i >= 0; i--){
        downHeapify(arr, size, i);
    }

}


int main (){
    int arr[MAX] = {3, 3, 3, 7, 7};

    buildMaxHeap(arr, MAX);

    int k;
    int i;
    printf("CONTENTS OF ARRAY\n");
    for (i = 0; i < MAX; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the kth largest element you want to find: ");
    scanf("%d", &k);    

    int largest = arr[k-1];

    printf("The largest element is %d\n", largest);

    return 0;

}