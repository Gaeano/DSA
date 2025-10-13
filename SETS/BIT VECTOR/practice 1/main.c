#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BITS (sizeof(unsigned int) * 8)
int count = 0;
typedef unsigned int SET;

void insertElement (SET* set, int x);
void removeElement (SET* set, int x);
bool isMember (SET* set, int x);
void displaySet(SET* set);

void insertElement (SET* set, int x){
    *set |= (1U << (x % BITS)); //insert
}

void removeElement (SET* set, int x){
    *set &= ~(1U << (x % BITS)); //remove uses &= and negate it
}

bool isMember (SET* set, int x){
    return ((*set & (1U << (x % BITS))) != 0)  ;
}

void displaySet(SET* set){
    int i;
    for (i = 0; i < BITS; i++){
        if (isMember(set, i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main (){

    SET* set = (SET*) calloc (1, sizeof(SET));

    insertElement(set, 2);
    insertElement(set, 1);
    insertElement(set, 5);
    insertElement(set, 8);
    insertElement(set, 3);

    displaySet(set);

    printf("--REMOVE AN ELEMENT--\n");
    removeElement(set, 1);
    
    displaySet(set);


    return 0;

}