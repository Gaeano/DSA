#include <stdio.h>
#include <stdlib.h>
#ifndef crudPracticeArrayList_H
#define crudPracticeArrayList_H
#include "studtype.h"
#define MAX 10

typedef struct {
    StudPtr elem[MAX];
    int count;
}ListArr;



ListArr initializeArr(ListArr l){ //initialize list
    l.count = 0;

    return l;
}

ListArr insertPos(ListArr l, StudPtr data, int position){
    int ite;

    if (position > l.count || position < 0){
        printf("invalid position maemm");
    } else if (l.count == MAX ){
        printf("Array is full oh no!");
    } else {
        for (ite = l.count; ite >= position; ite--){
            l.elem[ite] = l.elem[ite - 1];
        }

            l.count++;
            l.elem[position] = data;
        }   
        return l;

}

ListArr deletePos(ListArr l, int position){
    int ite;
    if (position < 0 || position >= l.count){
        printf("invalid position :((");
    } else {
        for (ite = position; ite < l.count - 1; ite++){
            l.elem[ite] = l.elem[ite + 1];
        }
        l.count--;

        printf("\ndata sucessfully deleted at position %d\n\n", position);
    }

    return l;
}

int locate(ListArr l, StudPtr data){
    int ite, ret = -1;

    for (ite = 0; ite < l.count && ret == -1; ite++){
        if (l.elem[ite]->id == data->id){
            ret = ite;
        }
    }

    return ret;
}

ListArr insertSorted (ListArr l, StudPtr data){
    int ite, pos = l.count;
    if (l.count == MAX){
        printf("array is full madam oh no !");
    } else { //change this shit

        for (ite = 0 ; ite < l.count && l.elem[ite]->id < data->id; ite++){
            pos++;
        }
        pos = ite;
       
        for (ite = l.count; ite > pos; ite--){
            l.elem[ite] = l.elem[ite - 1];
        }

        l.count++;
        l.elem[pos] = data;

    }

    return l;
}

void display(ListArr l){
    int ite;

    printf("%-15s %-15s %-10s %-5s %-5s\n", "First Name", "Last Name", "Course", "Yr", "ID");
        printf("-------------------------------------------------------\n");
    
    for (ite = 0; ite < l.count; ite++){
        printf("%-15s %-15s %-10s %-5d %-5d\n",
                    l.elem[ite]->name.FName,
                    l.elem[ite]->name.LName,
                    l.elem[ite]->course,
                    l.elem[ite]->age,
                    l.elem[ite]->id);
    }


}

#endif