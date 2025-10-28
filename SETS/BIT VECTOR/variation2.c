#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct{
    unsigned int field: 8;
}SET;
// BIT FIELD


void initialize(SET* set);
void insert(SET* set, int elem);
void delete(SET* set, int elem);
bool find (SET set, int elem);
SET unionSet(SET A, SET B);
SET intersectionSet(SET A, SET B);
SET difference (SET A, SET B);
void display (SET A);


void initialize(SET* set){
    set = 0;
}

void insert(SET *set, int elem){
    
    set->field |= (1U << elem);
}

void delete(SET* set, int elem){
    set->field &= ~(1U << elem);
}

bool find (SET set, int elem){
    return (set.field & 1U << elem) != 0;
}

SET unionSet(SET A, SET B){
    SET C;
    C.field = A.field | B.field; 
    return C;
}

SET intersectionSet(SET A, SET B){
    SET C;
    C.field = A.field & B.field; 
    return C;
}

SET difference (SET A, SET B){
    SET C;
    C.field = A.field & ~B.field; 
    return C;
}

void display (SET A){
    int i;

    for (i = 0; i < 8; i++){
        if (find(A, i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main (){
    SET A;
    SET B;
    initialize(&A);
    insert(&A, 2);
    insert(&A, 1);

    display(A);

    initialize(&B);

    insert(&B, 7);
    insert(&B, 6);
    insert(&B, 4);

    display(B);

    printf("UNION\n");
    B = unionSet(A, B);
    display(B);
    return 0;
    
}
