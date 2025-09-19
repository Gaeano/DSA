#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "weaverQueue.h"
#define MAX 3

void checkValidity(Queue* q);
void merge(Queue* q, Queue* q2);

int main(){
    Queue q[MAX];

    int i;
    for (i = 0; i < MAX; i++){
        initQueue(&q[i]);
    }   
    
     //first chain
    
    enqueue(&q[0], 101);
    enqueue(&q[0], 205);
    enqueue(&q[0], 333);

    //second chain
    
    enqueue(&q[1], 777);

    //third chain
    
    enqueue(&q[2], 444);
    enqueue(&q[2], 555);
    enqueue(&q[2], 666);
    createCycle(&q[2]);
    
    for(i = 0; i < MAX; i++){
        // checkValidity(&q[i]);
        display(&q[i]);
        checkValidity(&q[i]);
    }
    merge(&q[0], &q[1]);
    return 0;
}

void checkValidity(Queue* q){
    int count = 0;
    if (!isEmpty(q)){
        if (checkCycle(q)) {
            printf("--Partially Accessible (Infinite loop detected - knowldege trapped)\n");
        } else {
            Queue temp;
                printf("--Accessible (%d Fragments reachable)\n", q->size);
        }
    }
}

void merge(Queue* q, Queue* q2){
    if (!isEmpty(q) && !isEmpty(q2)){
        for (; !isEmpty(q2); dequeue(q2)){
            enqueue(q, front(q2));
        }
        printf("MERGED: ");
        display(q);
    }
}
