#include <stdio.h>
#include <stdlib.h>
#define BITS (sizeof(unsigned char  )*8)

typedef unsigned char SET;

SET un(SET A, SET B);
SET inter(SET A, SET B);
SET diff(SET A, SET B);
SET merge(SET A, SET B);
SET addElem(SET A, int elem);
int setContains(SET A, int x);
void display(SET A);

SET un(SET A, SET B){
    return A | B;
}

SET inter(SET A, SET B){
    return A & B;
}

SET diff(SET A, SET B){
    return A & (~B);
}

SET addElem(SET A, int elem){
    return A |= 1U << elem % BITS;
}

int setContains(SET A, int x){
    return (A & 1U << (x % BITS)) != 0;
}

SET merge(SET A, SET B){
    return un(A, B);
}

void display(SET A) {
    int i;
    for (i = 0; i < BITS; i++){
        if (setContains(A, i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main (){
    SET A = 0; SET B = 0;

    A = addElem(A, 1);
    A = addElem(A, 2);
    A = addElem(A, 4);
    A = addElem(A, 6);

    B = addElem(B, 2);
    B = addElem(B, 1);
    B = addElem(B, 3);
    B = addElem(B, 4);

    display(A);
    display(B);
    SET C = 0;
    printf("UNION:\n");
    C = un(A, B);
    display(C);
    printf("INTERSECTION\n");
    C = inter(A, B);
    display(C);
    printf("DIFFERENCE\n");
    C = diff(A, B);
    display(C);
    printf("MERGE\n");
    C = merge(A, B);
    display(C);


    return 0;
}