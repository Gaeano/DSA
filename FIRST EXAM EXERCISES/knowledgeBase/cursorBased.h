#include <stdio.h>
#include <string.h>
#ifndef cursorBased_H
#define cursorBased_H
#define MAX 20

typedef struct{
    char title[64];
    int id;
    char content[50];
}Article;


typedef struct{
    Article art;
    int next;
}Heapspace;

typedef struct{
    Heapspace H[MAX];
    int avail;
}VHeap;

typedef int List;
void initHeap(VHeap* heap);
int allocSpace (VHeap *heap);
void deallocSpace(VHeap *heap, int idx);

void initHeap(VHeap* heap){
    int i;
    for (i = 0; i < MAX - 1; i++){
        heap->H[i].next = i+1;
    }
    heap->H[i].next = -1;
    heap->avail = 0;
}

int allocSpace (VHeap *heap){
    int retVal;

    if(heap->avail != -1){
        retVal = heap->avail;
        heap->avail = heap->H[retVal].next;
    }

    return retVal;
}

void deallocSpace(VHeap *heap, int idx){
    if (idx != -1 && idx < MAX ){
        heap->H[idx].next = heap->avail;
        heap->avail = idx;
    }
}


#endif