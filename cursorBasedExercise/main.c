#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cb.h"

int main (){
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

    StudPtr stud5 = (StudPtr) malloc (sizeof(Studtype));
    if (stud5 == NULL){
        printf("memory alloc failed");
        exit(1);
    }

    //populate studs
    strcpy(stud1->name.FName, "Nicole");
    strcpy(stud1->name.LName, "Heredia");
    strcpy(stud1->Course, "BSCS");
    stud1->YrLvl = 1;
    stud1->id = 1;
    
    strcpy(stud2->name.FName, "Lukas");
    strcpy(stud2->name.LName, "Manlangit");
    strcpy(stud2->Course, "BSCS");
    stud2->YrLvl = 4;
    stud2->id = 2;

    strcpy(stud3->name.FName, "Antoinette");
    strcpy(stud3->name.LName, "Luague");
    strcpy(stud3->Course, "BSPHARM");
    stud3->YrLvl = 2;
    stud3->id = 4;
    
    strcpy(stud4->name.FName, "Jules");
    strcpy(stud4->name.LName, "Lada");
    strcpy(stud4->Course, "BSIS");
    stud4->YrLvl = 3;
    stud4->id = 5;
    
    strcpy(stud5->name.FName, "Sofia ");
    strcpy(stud5->name.LName, "Atillo");
    strcpy(stud5->Course, "BSPT");
    stud5->YrLvl = 2;
    stud5->id = 7;


    strcpy(unique->name.FName, "Alicia ");
    strcpy(unique->name.LName, "Bactasa");
    strcpy(unique->Course, "BSIT");
    unique->YrLvl = 2;
    unique->id = 3;

    VHeap H;
    List L = -1; //list is empty
    initHeap(&H);

    insertSorted(&H, stud1, &L);
    insertSorted(&H, stud2, &L);
    insertSorted(&H, stud3, &L);
    insertSorted(&H, stud4, &L);
    insertSorted(&H, unique, &L);
    deleteValue(&H, 3, &L);

    // insertFirst(&H, &L, stud1);
    // insertFirst(&H, &L, stud2);
    // insertFirst(&H, &L, stud4);
    // insertLast(&H, &L, unique);
    // insertSorted(&H, stud5, &L);

    displayList(&H, L);
}