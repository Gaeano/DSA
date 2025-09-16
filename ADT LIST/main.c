#include <stdio.h>
#include <string.h>
#include "crudPracticeArrayList.h"
#include "crudPracticeLL.h"
#include "studtype.h"

int main (){
    StudPtr stud;
    ListLL * head = NULL;

    ListArr arr;

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

    strcpy(stud1->name.FName, "Nicole");
    strcpy(stud1->name.LName, "Heredia");
    strcpy(stud1->course, "BSCS");
    stud1->age = 1;
    stud1->id = 1;
    
    strcpy(stud2->name.FName, "Lukas");
    strcpy(stud2->name.LName, "Manlangit");
    strcpy(stud2->course, "BSCS");
    stud2->age = 24;
    stud2->id = 2;

    strcpy(stud3->name.FName, "Antoinette");
    strcpy(stud3->name.LName, "Luague");
    strcpy(stud3->course, "BSPHARM");
    stud3->age = 22;
    stud3->id = 4;
    
    strcpy(stud4->name.FName, "Jules");
    strcpy(stud4->name.LName, "Lada");
    strcpy(stud4->course, "BSIS");
    stud4->age = 23;
    stud4->id = 5;

    strcpy(unique->name.FName, "Alicia ");
    strcpy(unique->name.LName, "Bactasa");
    strcpy(unique->course, "BSIT");
    unique->age = 2;
    unique->id = 3;
    //array list

    printf("ARRAY LISTT\n");
    printf("------------------------------------\n");


    arr = initializeArr(arr);

    arr = insertPos(arr, stud1, 0);
    arr = insertPos(arr, stud2, 1);
    arr = insertPos(arr, stud3, 2);
    arr = insertSorted(arr, stud4);
    display(arr);
    arr = deletePos(arr, 1);
    display(arr);

    //linked list
    printf("\nLINKED LISTT\n");
    printf("------------------------------------\n");
    head = initialize();

    insertFirst(head, stud1);
    insertFirst(head, stud2);
    insertFirst(head, stud3);
    insertLast(head, stud4);
    insertPosLL(head, unique, 0);
    deleteLast(head);
    deleteStart(head);
    deletePosLL(head, 3);

    displayLL(head);

}