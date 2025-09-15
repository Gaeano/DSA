#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef CB_H
#define CB_H

#define MAX 10

typedef struct{
    char FName[24];
    char LName[16];
    char MI;
}Name;

typedef struct{
    Name name;
    char Course[8];
    int YrLvl;
    int id;
}Studtype, *StudPtr;


typedef struct{
    StudPtr elem;
    int next;
}Heapspace;

typedef struct{
    Heapspace H[MAX];
    int avail;
}VHeap;

typedef int List;

int allocSpace(VHeap * VH);
void dealloc(VHeap *VH, int index);
void initHeap(VHeap* VH);
void insertSorted(VHeap *VH, StudPtr data, List* L);
void displayList(VHeap * VH, List L);
void deleteValue(VHeap *VH, int data, List* L);
void insertFirst(VHeap *VH, List* L, StudPtr data);
void insertLast(VHeap* VH, List* L, StudPtr data);


void initHeap(VHeap* VH){
    int i;
    for (i = 0 ; i < MAX - 1; i++){
        VH->H[i].next = i+1;
    }
    VH->H[i].next = -1;
    VH->avail = 0;
}

int allocSpace(VHeap * VH){ //gets the new available space index.
    int retVal = VH->avail;

    if (VH->avail != -1){
        VH->avail = VH->H[retVal].next;
    }
    return retVal;
}


void dealloc(VHeap *VH, int index){
    if (index != -1 && index < MAX){
        VH->H[index].next = VH->avail; //this index will be freed and be Available
        VH->avail = index; //new avail is the index 
    }
}


void insertSorted(VHeap *VH, StudPtr data, List* L){
    List temp = allocSpace(VH);
    List* trav;

    if (temp != -1){
        for (trav = L; *trav != -1 && VH->H[*trav].elem->id < data->id; trav = &VH->H[*trav].next){

        }

        VH->H[temp].elem = data;
        VH->H[temp].next = *trav;
        *trav = temp;

    }
}

void displayList(VHeap * VH, List L){
        printf("%-15s %-15s %-10s %-5s %-5s\n", "First Name", "Last Name", "Course", "Yr", "ID");
        printf("-------------------------------------------------------\n");

    for (; L != -1; L = VH->H[L].next){
        StudPtr data = VH->H[L].elem;
        printf("%-15s %-15s %-10s %-5d %-5d\n",
                    data->name.FName,
                    data->name.LName,
                    data->Course,
                    data->YrLvl,
                    data->id);
        }

} 


void deleteValue(VHeap *VH, int data, List* L){
    List* trav;
    List prev = -1;
    int sucess = 1;

    for (trav = L; *trav != -1 && VH->H[*trav].elem->id != data; trav = &VH->H[*trav].next){
        prev = *trav;
    }

    List temp = *trav;
    VH->H[prev].next = VH->H[temp].next;
    dealloc(VH, temp);



}

void insertFirst(VHeap *VH, List* L, StudPtr data){
    List temp = allocSpace(VH);

    if (temp != -1){
        VH->H[temp].elem = data;
        VH->H[temp].next = *L;
        *L = temp;
    }
}

void insertLast(VHeap* VH, List* L, StudPtr data){
    List temp = allocSpace(VH);
    List * trav;
    for (trav = L; *trav != -1; trav = &VH->H[*trav].next){
    }

    VH->H[temp].elem = data;
    VH->H[temp].next = -1;
    *trav = temp;

}
#endif