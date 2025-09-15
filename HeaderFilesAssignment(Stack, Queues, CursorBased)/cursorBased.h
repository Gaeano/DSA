#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QUEUE.h"
#include "STUDTYPE.h"
#ifndef cursorBased_H
#define cursorBased_H   
#define MAX 10

typedef struct{
    StudPtr elem;
    int next;
}HeapSpace[MAX];

// typedef struct{
//     HeapSpace H;
//     int avail;
// }stackCB;

// typedef struct{
//     HeapSpace H;
//     int avail;
// }queueCB;

// typedef struct{
//     stackCB* s;
//     queueCB* q;
// }VHeap;

typedef struct{
   HeapSpace H;
    int avail;
}VHeap;



typedef struct{
    int stakList;
    int queueList;
}List;



// void CBinitStack(Stack **s);
void initHeap(VHeap* vh);
int allocSpaceS(VHeap* vh);
int allocSpaceQ(VHeap* vh);
void deallocS(VHeap* vh, int index);
void deallocQ(VHeap* vh, int index);
void pushCursor(VHeap* vh, int* L, StudPtr data);
void popCursor(VHeap* vh, int* L, StudPtr data);
StudPtr top(VHeap* vh, int L);
void displayListS(VHeap* vh, int L);
void CBpushUnique(VHeap *vh, int* L, StudPtr data);
bool checkUniqueCBStak(VHeap * vh, int L, StudPtr data);

// void CBinitStack(Stack **s){
//     (*s)->vh = (VHeap*) malloc (sizeof(VHeap));
// }
 
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

int allocSpaceQ(VHeap* vh){
    int retVal = vh->avail;
    if (vh->avail != -1){
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

void popCursor(VHeap* vh, int* L, StudPtr data){
    int temp;

    temp = *L; //equate to head
    *L = vh->H[temp].next; //new head is the next of head yesyes
    deallocS(vh, temp);

}



StudPtr top(VHeap* vh, int L){
    return vh->H[L].elem;
}


void displayListS(VHeap* vh, int L){
printf("Cursor Based Stack\n");

    for (; L != -1; L = vh->H[L].next){
        StudPtr data = top(vh, L);
        printf("%-15s %-15s %-10s %-5d\n",
                    data->name.FName,
                    data->name.LName,
                    data->Course,
                    data->YrLvl);
    }
}

bool checkUniqueCBStak(VHeap * vh, int L, StudPtr data){
    StudPtr IhaveData = top(vh, L);
    return strcmp(IhaveData->name.LName, data->name.LName) != 0;
}

void CBpushUnique(VHeap *vh, int* L, StudPtr data){
    int temp = allocSpaceS(vh);
    int* trav;

    if (temp != -1){
        for (trav = L; *trav != -1 && checkUniqueCBStak(vh, *trav, data); trav = &vh->H[*trav].next){
        }

        if (*trav == -1){ //insert if data is unique
            pushCursor(vh, L, data);
        } else {
            printf("%s data is not unique, could not add to CB Stack\n", data->name.LName);

        }    

    }
}
 





#endif
