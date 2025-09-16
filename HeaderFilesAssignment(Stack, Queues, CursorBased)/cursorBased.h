#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "STUDTYPE.h"
#ifndef cursorBased_H
#define cursorBased_H   
#define MAX 10

typedef struct{
    StudPtr elem;
    int next;
}HeapSpace[MAX];

typedef struct{
   HeapSpace H;
    int avail;
}VHeap;


typedef struct{
    int stakList;
    int queueListFront;
    int queueListRear;
}List;



void CBinitStack(List *L);
void initHeap(VHeap* vh);
int allocSpaceS(VHeap* vh);
void deallocS(VHeap* vh, int index);
void pushCursor(VHeap* vh, int* L, StudPtr data);
void popCursor(VHeap* vh, int* L);
StudPtr top(VHeap* vh, int L);
void displayListS(VHeap* vh, int L);
void CBpushUnique(VHeap *vh, int* L, StudPtr data);
 void popUniqueCB(VHeap *vh, StudPtr data, int* L);
bool checkUniqueCBStak(VHeap * vh, int L, StudPtr data);
bool isCBStakEmpty(int L);
//queue
void CBinitQueue(List *L);
int allocSpaceQ(VHeap* vh);
void deallocQ(VHeap* vh, int index);
void enqueueCB(VHeap *vh, int* front , int* rear, StudPtr data);
void dequeueCB(VHeap *vh, int* front, int* rear);
void CBenqueueUnique(VHeap * vh , int *front, int* rear, StudPtr data);
bool checkUniqueCBQueue(VHeap * vh, int l, StudPtr data);
bool isCBQueueEmpty(int front, int rear);
void CBdequeueUnique(VHeap* vh, int *front, int* rear , StudPtr data);
void displayQ(VHeap* vh, int front);
StudPtr frontCB (VHeap vh, int l);



void CBinitStack(List *L){
    L->stakList = -1;
}
 
void CBinitQueue(List *L){
    L->queueListRear = -1;
    L->queueListFront = -1;
}

void initHeap(VHeap * vh){
    int i;

    for (i = 0; i < MAX - 1; i++){
        vh->H[i].next = i+1;
    }

    vh->H[i].next = -1;
    vh->avail  = 0;
}


int allocSpaceS(VHeap* vh){
    int retVal = vh->avail;
    if(vh->avail != -1){ //not full
        vh->avail = vh->H[retVal].next;
    }
    return retVal;
}


void deallocS (VHeap * vh, int index){
    if (index != -1 && index < MAX){
        vh->H[index].next = vh->avail;
        vh->avail = index;
    }
}



void pushCursor(VHeap* vh, int* L, StudPtr data){
    int temp = allocSpaceS(vh);
   
    if(temp != - 1){
        vh->H[temp].elem = data;
        vh->H[temp].next = *L;
        *L = temp;
    }
   
}

void popCursor(VHeap* vh, int* L){
    int temp;

    temp = *L; //equate to head
    *L = vh->H[temp].next; //new head is the next of head yesyes
    deallocS(vh, temp);

}



StudPtr top(VHeap* vh, int L){
    return vh->H[L].elem;
}


void displayListS(VHeap* vh, int L){
        printf("%-15s %-15s %-10s %-5s\n", "First Name", "Last Name", "Course", "Yr");
        printf("-------------------------------------------------------\n");
printf("Cursor Based Stack\n");

VHeap temp = *vh; //make copy of the heap
int tempList = L; //copy of "index"

    for (; tempList != -1; popCursor(&temp, &tempList)){
        StudPtr data = top(&temp, tempList);
        printf("%-15s %-15s %-10s %-5d\n",
                    data->name.FName,
                    data->name.LName,
                    data->Course,
                    data->YrLvl);
    }
            printf("-------------------------------\n");

}

bool checkUniqueCBStak(VHeap * vh, int L, StudPtr data){
    StudPtr IhaveData = top(vh, L);
    return strcmp(IhaveData->name.LName, data->name.LName) != 0;
}

void CBpushUnique(VHeap *vh, int* L, StudPtr data){
    VHeap tempList = *vh;
    int temp = allocSpaceS(vh);
    int trav;

    if (temp != -1){
        for (trav = *L; trav != -1 && checkUniqueCBStak(&tempList, trav, data); popCursor(&tempList, &trav)){
        }

        if (trav == -1){ //insert if data is unique
            pushCursor(vh, L, data);
        } else {
            printf("%s data is not unique, could not add to CB Stack\n", data->name.LName);

        }    

    }
}


bool isCBStakEmpty(int L){
    return L == -1;
}

 void popUniqueCB(VHeap *vh, StudPtr data, int* L){
        int trav = *L;
        int tempList = -1;
            VHeap *temp = (VHeap*) malloc (sizeof(VHeap));
            if(temp == NULL){
                printf("memory alloc failed");
                exit(1);
            }
            initHeap(temp);

            while(!isCBStakEmpty(trav) && checkUniqueCBStak(vh, trav ,data)){
                StudPtr holdMyData = top(vh, trav);
                pushCursor(temp, &tempList, holdMyData);
                popCursor(vh, &trav);
            }

            if(!isCBStakEmpty(trav)){
            popCursor(vh, &trav);

                while(!isCBStakEmpty(tempList)){
                    StudPtr canIHaveMyDataBack = top(temp, tempList);
                    pushCursor(vh,  &trav, canIHaveMyDataBack);
                    popCursor(temp, &tempList);
                }
            
                *L = trav;
                printf("data %s successfully popped in Linked List Stack\n\n", data->name.LName);
            } else {
                printf("data does not exist in the Linked Stack\n");
            }

    }

int allocSpaceQ(VHeap* vh){
    int retVal = vh->avail;
    if (vh->avail != -1){
        vh->avail = vh->H[retVal].next;
    }
    return retVal;
}

bool isCBQueueEmpty(int front, int rear) {
    return (front == -1 && rear == -1);
}

void deallocQ(VHeap* vh, int index){
    if(index != -1 && index < MAX -1){
        vh->H[index].next = vh->avail;
        vh->avail = index;
        
    }
}

void enqueueCB(VHeap *vh, int* front , int* rear, StudPtr data){
    int temp = allocSpaceQ(vh);
    if (temp != -1){
          vh->H[temp].elem = data;
          vh->H[temp].next = -1;
        if(*rear == -1){
          *front = temp;
          *rear = temp;
        } else {
            vh->H[*rear].next = temp;
            *rear = temp;
        }
    }
    
}

void dequeueCB(VHeap *vh, int* front, int* rear){
 
 if(!isCBQueueEmpty(*front, *rear)){
        int temp = *front;
        *front = vh->H[*front].next;
        if(*front == -1) { 
            *rear = -1;
        }
        deallocQ(vh, temp);
    }

}

StudPtr frontCB (VHeap vh, int l){
    return vh.H[l].elem;
}

bool checkUniqueCBQueue(VHeap * vh, int l, StudPtr data){
    StudPtr tempData = frontCB(*vh, l);
    return strcmp(data->name.LName, tempData->name.LName) != 0;
}

void CBenqueueUnique(VHeap * vh , int *front, int* rear, StudPtr data){
    if(!isCBQueueEmpty(*front, *rear)){
        VHeap temp = *vh;
        int tempList = *front;
        int temprear = *rear;
        for (; tempList != -1 && checkUniqueCBQueue(vh, tempList, data); dequeueCB(&temp, &tempList, &temprear)){}

        if (tempList == -1){
            enqueueCB(vh, front, rear, data);
        } else {
            printf("%s data is not unique, could not add to Cursor Based Queue\n", data->name.LName);
        }
    }
}

void displayQ(VHeap* vh, int front){
    printf("%-15s %-15s %-10s %-5s\n", "First Name", "Last Name", "Course", "Yr");
        printf("-------------------------------------------------------\n");
printf("Cursor Based Queue\n");

    VHeap temp = *vh;
    int trav;
    int travrear = -1;
    for (trav = front; trav != -1; trav = temp.H[trav].next){
        StudPtr data = frontCB(temp, trav); 
        
        printf("%-15s %-15s %-10s %-5d\n",
                    data->name.FName,
                    data->name.LName,
                    data->Course,
                    data->YrLvl);
    }
                printf("-------------------------------\n");

}


void CBdequeueUnique(VHeap* vh, int *front, int* rear, StudPtr data) {
    int tempFront = *front;
    int tempRear = *rear;

    int tempList = -1;
    int tempRearList = -1;

    VHeap temp;
    initHeap(&temp); 
    
    while (!isCBQueueEmpty(tempFront, tempRear) && checkUniqueCBQueue(vh, tempFront, data)) {
        StudPtr holdMyData = frontCB(*vh, tempFront);
        enqueueCB(&temp, &tempList, &tempRearList, holdMyData);
        dequeueCB(vh, &tempFront, &tempRear);
    }

    if (!isCBQueueEmpty(tempFront, tempRear)) {
        dequeueCB(vh, &tempFront, &tempRear); 

        tempFront = -1;
    tempRear = -1;

        while (!isCBQueueEmpty(tempList, tempRearList)) {
    StudPtr dataBack = frontCB(temp, tempList);
    enqueueCB(vh, &tempFront, &tempRear, dataBack);
    printf("Re-enqueue: front=%d, rear=%d\n", tempFront, tempRear);
    dequeueCB(&temp, &tempList, &tempRearList);
}


        *front = tempFront;
        *rear = tempRear;
        printf("Data %s successfully dequeued in Cursor Based Queue\n\n", data->name.LName);
    } else {
        printf("Data does not exist in Cursor Based Queue\n");
    }
}

#endif
