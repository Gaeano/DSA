#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 8
typedef bool SET[MAX];


void initialize(SET* set);
void insert(SET* set, int elem);
void delete(SET* set, int elem);
bool find (SET set, int elem);
void unionSet(SET A, SET B,  SET C);
void intersectionSet(SET A, SET B,  SET C);
void difference (SET A, SET B,  SET C);
void display (SET A);


void initialize(SET* set){
    for (int i = 0; i < MAX; i++){
        (*set)[i] = false;
    }
}

void insert(SET *set, int elem){
    (*set)[elem] = true;
}

void delete(SET* set, int elem){
    (*set)[elem] = false;
}

bool find (SET set, int elem){
    return (set[elem] == true);
}

void unionSet(SET A, SET B,  SET C){
   

    for (int i = 0; i < MAX; i++){
        C[i] = A[i] | B[i];
    }
    
}

void intersectionSet(SET A, SET B, SET C){
   

    for (int i = 0; i < MAX; i++){
        C[i] = A[i] | B[i];
    }
    
}

void difference (SET A, SET B, SET C){
    

    for (int i = 0; i < MAX; i++){
        C[i] = A[i] | B[i];
    }
    
}

void display (SET A){
    int i;

    for (i = 0; i <= MAX; i++){
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
    SET C;
    unionSet(A, B, C);
    display(C);
    return 0;
    
}
