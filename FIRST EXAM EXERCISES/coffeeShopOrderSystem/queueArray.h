#include <stdio.h>
#include <stdbool.h>
#ifndef queueArray_H
#define queueArray_H
#define MAX 10
typedef struct{
    int arr[MAX];
    int rear;
    int front;
}Queue;

//order enqueue
//serve  dequeue

void initQueue(Queue * q);
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue *q, int data);
void dequeue(Queue* q);
int front(Queue * q);
void display (Queue* q);

void initQueue(Queue * q){
    q->front = 0;
    q->rear = -1;
}
bool isEmpty(Queue* q){
    return ((q->rear + 1) % MAX == q->front);
}

bool isFull(Queue* q){
    return ((q->rear + 2) % MAX == q->front);
}

void enqueue(Queue *q, int data){
    if (!isFull(q)){
        if (q->rear == -1){
            q->arr[q->front] = data;
            q->rear = (q->rear + 1) % MAX;
            printf("ORDER: %d\n", data);
        } else {
            q->rear = (q->rear + 1) % MAX;
            q->arr[q->rear] = data;
            printf("ORDER: %d\n", data);
        }
    }
}

void dequeue(Queue* q){

    if(isEmpty(q)){
        printf("NO_ORDER\n");
    } else {
        if (q->rear == q->front){
            // printf("SERVE: %d", front(q));
            q->front = 0;
            q->rear = -1;
        } else {
            // printf("SERVE: %d", front(q));
            q->front = (q->front + 1) % MAX;
        }
    }
       
}

int front(Queue * q){
    return q->arr[q->front];
}

void display (Queue* q){
    Queue temp;

    for (temp = *q; !isEmpty(&temp); dequeue(&temp)){
        printf("%d\n", front(&temp));
    }
}

#endif
