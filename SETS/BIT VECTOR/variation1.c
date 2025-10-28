#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define BITS (sizeof(int) * 8)

typedef unsigned char SET;
// COMPUTER WORD


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
    
    *set |= (1U << (elem % BITS));
}

void delete(SET* set, int elem){
    *set &= ~(1U << (elem % BITS));
}

bool find (SET set, int elem){
    return (set & 1U << (elem % BITS)) != 0;
}

SET unionSet(SET A, SET B){
    return A | B;
}

SET intersectionSet(SET A, SET B){
    return A & B;
}

SET difference (SET A, SET B){
    return A & ~B;
}

void display (SET A){
    int i;

    for (i = 0; i <= BITS; i++){
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
