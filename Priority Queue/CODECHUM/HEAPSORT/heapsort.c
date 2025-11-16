#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write your functions here
int lastNdx;

void swap(char **a, char **b){
    char* temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}


void heapify (char *arr[], int n, int i){
    int parent = ((i - 1) / 2);
    
    if (strcmp(arr[parent], arr[i]) < 0){
        swap(&arr[parent], &arr[i]);
        heapify(arr, n, parent);
    }
    
}

void downHeapify(char* arr[], int i){
    int left = 2*i + 1;
        int right = 2*i + 2;
        int max = i;
        
        if (left <= lastNdx && strcmp(arr[left], arr[max]) > 0){
            max = left;
        }
        
        if (right <= lastNdx && strcmp(arr[right], arr[max]) > 0){
            max = right;
        }
        
        if (max != i){
            swap(&arr[max], &arr[i]);
            downHeapify(arr, max);
        }
}

char* deleteMax (char* arr[]){
    char* orig = arr[0];
    
    
    arr[0] =arr[lastNdx];
    lastNdx--;
    if (lastNdx >= 0){
        downHeapify(arr, 0);
    }
    
    return orig;
}

void heapSort(char *arr[], int n){
    int orig;
    char* catcher;
    int i;
    lastNdx = n-1;

    for (i = 0 ; i < n; i++){
        heapify(arr, n, i);
    }
    orig = lastNdx;

    while (lastNdx != -1){
        catcher = deleteMax(arr);
        arr[lastNdx+1] = catcher;
    }
    
    lastNdx = orig;
    
    
}