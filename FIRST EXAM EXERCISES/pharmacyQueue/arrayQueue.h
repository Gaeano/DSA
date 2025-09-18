#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef arrayQueue_H
#define arrayQueue_H
#define MAX 10

typedef struct {
    int num[MAX];
    int front;
    int rear;
}Queue;


Queue* initialize(){
    Queue* q = (Queue*) malloc (sizeof(Queue));

    q->front = 0;
    q->rear = -1;
    

    return q;

    // Queue* priority = (Queue*) malloc (sizeof(Queue));
    // Queue* regular = (Queue*) malloc (sizeof(Queue));

    // priority->front = - 1;
    // priority->rear = -1;

    // regular->front  = -1;
    // regular->rear = -1;
}


bool isFull(Queue* q){
return ((q->rear + 2) % MAX) == q->front;
}

bool isEmpty(Queue* q){
    return ((q->rear + 1) % MAX) == q->front;
}

void enqueue(Queue* q, int value){
    if (!isFull(q)){
        q->rear = (q->rear + 1) % MAX;
        q->num[q->rear] = value;
         
    } else {
        printf("Queue is full !\n");
    }
}


void dequeue(Queue *q){
    if (!isEmpty(q)){
        if (q->front == q->rear){
            q->front = 0;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        
    } else {
        printf("Nothing to dequeue, queue is empty!\n");
    }
}

void display(Queue* q){
    Queue temp;
    temp.front = q->front;
    temp.rear = q->rear;
    // printf("front: %d rear: %d\n", q->front, q->rear);
    // printf("tempfront: %d tempRear: %d\n", temp.front, temp.rear);
    if (isEmpty(q)){
        printf("queue is empty!\n");
    } else {
        for (temp = *q; !isEmpty(&temp); dequeue(&temp)){
            printf("Number: %d\n", temp.num[temp.front]);
        }
    }
    

    // printf("Calling customer: %d\n", q->num[q->front]);
    // dequeue(q);
}

int front (Queue* q){
    return q->num[q->front];
}
#endif 