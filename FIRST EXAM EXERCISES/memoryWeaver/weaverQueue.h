#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#ifndef weaverQueue_H
#define weaverQueue_H


typedef struct node{
    int fragmentID;
    struct node* next;
}Node;



typedef struct{
    Node* anchorPoint;
    Node* rear;
    int size;
}Queue;

Node* createNode(int data);
void initQueue(Queue* q);
bool isEmpty(Queue *q);
void enqueue(Queue* q, int id);
void dequeue(Queue *q);
int front(Queue* q);
void display(Queue* q);
void createCycle(Queue* q);
bool checkCycle(Queue* q);

void initQueue(Queue* q){
    q->anchorPoint = NULL;
    q->rear = NULL;
    q->size = 0;
}

Node* createNode(int data){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (newNode == NULL){
        printf("memory alloc failed");
        exit(1);
    }

    newNode->fragmentID = data;
    newNode->next = NULL;

    return newNode;
}

bool isEmpty(Queue *q){
    return q->anchorPoint == NULL;
}

void enqueue(Queue* q, int id){
    Node* newNode = createNode(id);

    if (q->anchorPoint == NULL){
        q->anchorPoint = newNode;
        q->rear = q->anchorPoint;
        q->size++;
    } else{
        q->rear->next = newNode;
        q->rear = newNode;
        q->size++;
         
    }
        
    
}

void dequeue(Queue *q){
    if (!isEmpty(q)){
        Node* temp = q->anchorPoint;
        q->anchorPoint = temp->next;
        q->size--;
        // free(temp);
    }
}

int front(Queue* q){
    return q->anchorPoint->fragmentID;
}

bool checkCycle(Queue* q){
    return q->rear->next == q->anchorPoint;
}


void display(Queue* q){
    Queue temp;
    int i = 0;
    if (checkCycle(q)){
        printf("Cycle detected cant display! ");
    } else {
        for(temp = *q; !isEmpty(&temp); dequeue(&temp)){
            printf("Fragment: %d ", front(&temp));
            if (i < q->size - 1){
                printf("-> ");
            }
            i++;
        }
    }
    
}
void createCycle(Queue* q){
    if(q->rear != NULL){
        q->rear->next = q->anchorPoint;
    }
}


#endif