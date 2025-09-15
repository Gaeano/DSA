#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STACK.h"
#include "QUEUE.h"
#include "STUDTYPE.h"
#include "cursorBased.h"

int main (){
    Stack* S;
    Queue* Q;
   

    StudPtr stud1 = (StudPtr) malloc (sizeof(Studtype));
    if (stud1 == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    StudPtr stud2 = (StudPtr) malloc (sizeof(Studtype));
    if (stud2 == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    StudPtr stud3 = (StudPtr) malloc (sizeof(Studtype));
    if (stud3 == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    StudPtr stud4 = (StudPtr) malloc (sizeof(Studtype));
    if (stud4 == NULL){
        printf("memory alloc failed");
        exit(1);
    }

    StudPtr unique = (StudPtr) malloc (sizeof(Studtype));
    if (unique == NULL){
        printf("memory alloc failed");
        exit(1);
    }


    //populate studs
    strcpy(stud1->name.FName, "Nicole");
    strcpy(stud1->name.LName, "Heredia");
    strcpy(stud1->Course, "BSCS");
    stud1->YrLvl = 1;
    
    strcpy(stud2->name.FName, "Lukas");
    strcpy(stud2->name.LName, "Manlangit");
    strcpy(stud2->Course, "BSCS");
    stud2->YrLvl = 4;

    strcpy(stud3->name.FName, "Antoinette");
    strcpy(stud3->name.LName, "Luague");
    strcpy(stud3->Course, "BSPHARM");
    stud3->YrLvl = 2;
    
    strcpy(stud4->name.FName, "Jules");
    strcpy(stud4->name.LName, "Lada");
    strcpy(stud4->Course, "BSIS");
    stud4->YrLvl = 3;
    
    strcpy(unique->name.FName, "Alicia ");
    strcpy(unique->name.LName, "Bactasa");
    strcpy(unique->Course, "BSIT");
    unique->YrLvl = 2;

    initStack(&S);
    initQueue(&Q);
   
    ArrInitialize(S);
    ArrPush(S, stud1);
    ArrPush(S, stud2);
    ArrPush(S, stud3);
    ArrPush(S, stud4);
    


    LlInitialize(S);
    LLpush(S, stud1);
    LLpush(S, stud2);
    LLpush(S, stud3);
    LLpush(S, stud4);



    AqInitialize(Q);
    AqEnqueue(Q, stud1);
    AqEnqueue(Q, stud2);
    AqEnqueue(Q, stud3);
    AqEnqueue(Q, stud4);

    
    LQueueInitialize(Q);
    LQEnqueue(Q, stud1);
    LQEnqueue(Q, stud2);
    LQEnqueue(Q, stud3);
    LQEnqueue(Q, stud4);

       
    
    pushUnique(S, unique);
    enqueueUnique(Q, unique);
 

    displayStack(S);
    displayQueue(Q);

    printf("POPOPPOP\n");
    popUnique(S, unique);
    dequeueUnique(Q, unique);
    displayStack(S);

    displayQueue(Q);
    initHeap(&S->vh);
    List stak;
    stak.stakList = -1;

    

    pushCursor(&S->vh, &stak.stakList, stud1);
    pushCursor(&S->vh, &stak.stakList, stud2);
    pushCursor(&S->vh, &stak.stakList, stud3);
    pushCursor(&S->vh, &stak.stakList, stud4);
    CBpushUnique(&S->vh, &stak.stakList, unique);
    displayListS(&S->vh, stak.stakList);


    free(S->SA);
    free(S->SL);
    free(Q->AQ);    
    free(Q->LQ);
    free(S);
    free(Q);

    return 0;
}
