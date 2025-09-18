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





#endif