#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef cursorBased_H
#define cursorBased_H   
#define MAX 10

//mofo is an array but behaves like a linked list
typedef struct{
    char elem;
    int next;
}HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

typedef int List; //index of the thingy


void initHeap(VHeap * vh){
    int i;

    for (i = 0; i < MAX - 1; i++){
        vh->H[i].next = i+1;
    }

    vh->H[i].next = -1;
    vh->avail  = 0;
}


int allocSpace(VHeap* vh){
    int retVal = vh->avail;
    if(vh->avail != -1){ //not full
        vh->avail = vh->H[retVal].next;
    }
    return retVal;
}
















#endif