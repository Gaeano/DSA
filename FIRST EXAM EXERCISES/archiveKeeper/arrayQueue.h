#include <stdio.h>
#include <stdbool.h>
#ifndef arrayQueue_H
#define arrayQueue_H
#define MAX 10
typedef struct{
    int id[MAX];
    int rear;
    int front;
}Queue;

void initQueue(Queue* q);
bool isEmpty(Queue *q);
bool isFull(Queue * q);
void enqueue(Queue *q, int num);
void dequeue(Queue* q);
int front(Queue* q);
void displayQueue(Queue *q);

void initQueue(Queue* q){
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue *q){
    return q->rear == -1;
}

bool isFull(Queue * q){
    return ((q->rear + 2) % MAX == q->front);
}

void enqueue(Queue *q, int num){
    if (isFull(q)){
        printf("Queue if maem\n");
    } else {
        if(q->rear == -1){
            q->id[q->front] = num;
            q->rear = q->front; //does this work??
        } else {
            q->rear = q->rear + 1 % MAX;
            q->id[q->rear] = num;
        }
    }
}

void dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    } else {
        if (q->rear == q->front){
            q->front = 0;
            q->rear = -1;
        } else {
            q->front = q->front + 1 % MAX;
        }
    }
}

int front(Queue* q){
    return q->id[q->front];
}

void displayQueue(Queue *q){
    Queue temp;

    for (temp = *q; !isEmpty(&temp); dequeue(&temp)){
        printf("%d\n", front(&temp));
    }
}

#endif