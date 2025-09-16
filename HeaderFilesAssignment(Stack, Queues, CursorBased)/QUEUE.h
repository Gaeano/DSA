#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "STUDTYPE.h"
#include "cursorBased.h"
#ifndef QUEUE_H
#define QUEUE_H
#define MAX 10


//array
typedef struct {
    StudPtr arr[MAX];
    int rear;
    int front;
}ArrQueue;

//linked list
typedef struct node {
    StudPtr data;
    struct node *next;
}node;

typedef struct {
    node* rear;
    node* front;
}LLqueueList;

typedef struct{
    ArrQueue *AQ;
    LLqueueList* LQ;
    VHeap vh;
}Queue;


void initQueue(Queue** q){
    *q = (Queue*) malloc (sizeof(Queue));
    if(*q == NULL){
        printf("memory alloc failed");
        } else {
        (*q)->AQ  = (ArrQueue*) malloc (sizeof(ArrQueue));
        (*q)->LQ = (LLqueueList*) malloc (sizeof(LLqueueList));
    }
}


//array
void AqInitialize(Queue* q){
    q->AQ->front = -1; //no elemenets in the queue
    q->AQ->rear = -1;
}

bool AqIsEmpty(Queue * q){
    return ((q->AQ->rear + 1) % MAX == q->AQ->front); //if true empty sha
}

bool AqIsFull(Queue * q){
    return ((q->AQ->rear + 2) % MAX == q->AQ->front);
}

void AqEnqueue(Queue * q, StudPtr data){
    
    if (!AqIsFull(q)){
        if(q->AQ->front == -1){ //queue is initially empty, assign the front with 0
            q->AQ->front = 0; 
        }
        q->AQ->rear = (q->AQ->rear + 1) % MAX;
        q->AQ->arr[q->AQ->rear] = data;
    }
}

void AqDequeue(Queue * q){
    if (!AqIsEmpty(q)){
        q->AQ->front = (q->AQ->front + 1) % MAX;

    }
}

StudPtr AqTop(Queue * q){
    if (AqIsEmpty(q)){
        printf("queue is empty");
        exit(1);
    } else {
        return q->AQ->arr[q->AQ->front];
    }
    
}
// linked list



void LQueueInitialize(Queue * q){
    q->LQ->rear = NULL;
    q->LQ->front = NULL;
}

node* createNode(StudPtr data){
    node * newNode = (node*) malloc (sizeof(node));
    if (newNode == NULL){
        printf("memory alloc failed");
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;

}

bool LQisEmpty(Queue * q){
    return (q->LQ->front == NULL);
}


void LQEnqueue(Queue* q, StudPtr data){
    node* newNode = createNode(data);

    if(LQisEmpty(q)){
        q->LQ->front = newNode;
        q->LQ->rear = newNode;
    } else {
        q->LQ->rear->next = newNode;
        q->LQ->rear= newNode;
    }
}

void LQDequeue(Queue * q){
    if (LQisEmpty(q)){
        printf("nothing to dequeueuu");
        exit(1);
    } else {
        node* temp;

        temp = q->LQ->front;

        q->LQ->front = temp->next;
        
    }
}


StudPtr front(Queue* q){
    if(!LQisEmpty(q)){
        return q->LQ->front->data;
    } else {
        printf("empty man sha bro bro");
        exit(1);
    }
}

bool checkUniqueArrayQ(Queue* q, StudPtr data){
    StudPtr ArrQueue = AqTop(q);
    return strcmp(ArrQueue->name.LName, data->name.LName) != 0;
 
    //HEEBHHDBW
}

bool checkUniqueLLQ(Queue* q,StudPtr data){
    StudPtr LLQueueTop = front(q);
    return strcmp(LLQueueTop->name.LName, data->name.LName) != 0;
    //HAHDAWHABDA
}



void enqueueUnique  (Queue* q, StudPtr data){
    Queue temp, temp2;

    ArrQueue tempArr =(*q->AQ);
    temp.LQ = NULL;
    LLqueueList tempListQ = (*q->LQ);
    temp2.AQ = NULL;

    for (temp.AQ = &tempArr; !AqIsEmpty(&temp) && checkUniqueArrayQ(&temp, data); AqDequeue(&temp)){}

    if(AqIsEmpty(&temp)){
        AqEnqueue(q, data);
    } else {
        printf("%s data is not unique, could not add to Array queue\n", data->name.LName);
    }


    for (temp2.LQ = &tempListQ; !LQisEmpty(&temp2) && checkUniqueLLQ(&temp2, data); LQDequeue(&temp2)){}


    if(LQisEmpty(&temp2)){
        LQEnqueue(q, data);
    } else {
        printf("%s data is not unique, could not add to Linked List queue\n", data->name.LName);
    }

}

void displayQueue(Queue * Q){
     Queue temp, temp2;
        temp = (*Q);
        temp2 = (*Q);
        ArrQueue tempArr = (*Q->AQ);
        LLqueueList tempList = (*Q->LQ);
        temp.LQ = NULL;
        temp2.AQ = NULL;
        temp.AQ = &tempArr;
        temp2.LQ = &tempList;

        printf("ARRAY QUEUE\n");
            while(!AqIsEmpty(&temp)){
                StudPtr data = AqTop(&temp);
                printf("%-15s %-15s %-10s %-5d\n",
                    data->name.FName,
                    data->name.LName,
                    data->Course,
                    data->YrLvl);
                AqDequeue(&temp);
            }
            printf("-------------------------------\n");

            
        printf("Linked List QUEUE\n");
        for (node* cur = temp2.LQ->front; cur != NULL; cur = cur->next){
            printf("%-15s %-15s %-10s %-5d\n",
                    cur->data->name.FName,
                    cur->data->name.LName,
                    cur->data->Course,
                    cur->data->YrLvl);
        }

            printf("-------------------------------\n");
}


void dequeueUnique(Queue* q, StudPtr data){
    Queue* temp = (Queue*) malloc (sizeof(Queue));
            if(temp == NULL){
                printf("memory alloc failed");
                exit(1);
            }
            temp->AQ = (ArrQueue*) malloc (sizeof(ArrQueue));
            AqInitialize(temp);

            while(!AqIsEmpty(q) && checkUniqueArrayQ(q, data)){
                StudPtr tempData = AqTop(q);
                AqEnqueue(temp, tempData);
                AqDequeue(q);
            }

            if(!AqIsEmpty(q)){ //if its not empty, data is found u pop the data
                AqDequeue(q);
                while( !AqIsEmpty(temp)){
                    StudPtr giveMeBackMyData = AqTop(temp);
                    AqEnqueue(q, giveMeBackMyData);
                    AqDequeue(temp);
                }
                printf("data %s successfully popped in Array Queue\n", data->name.LName);
            } else { //data is not found
                printf("data does not exist in the Array Queue\n");
            }
        //linked list

            Queue *temp2 = (Queue*) malloc (sizeof(Queue));
            if(temp2 == NULL){
                printf("memory alloc failed");
                exit(1);
            }
            temp2->LQ = (LLqueueList*) malloc (sizeof(LLqueueList));
            LQueueInitialize(temp2);
            while(!LQisEmpty(q)&& checkUniqueLLQ(q, data)){
                StudPtr holdMyData = front(q);
                LQEnqueue(temp2, holdMyData);
                LQDequeue(q);
            }

            if(!LQisEmpty(q)){
                LQDequeue(q);

                while(!LQisEmpty(temp2)){
                    StudPtr canIHaveMyDataBack = front(temp2);
                    LQEnqueue(q, canIHaveMyDataBack);
                    LQDequeue(temp2);
                }
            
                printf("data %s successfully popped in Linked List Queue\n\n", data->name.LName);
            } else {
                printf("data does not exist in the Linked Queue\n");
            }
}

#endif
