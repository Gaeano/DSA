#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BITS (sizeof(unsigned int) * 8)

typedef struct{
   unsigned int* data;
    int size;
}Set;

Set un(Set A, Set B);
Set inter(Set A, Set B);
Set diff(Set A, Set B);
void addElem(Set* A, int elem);
int setContains(Set* A, int x);

void addElem(Set* A, int elem){
    int index = elem / BITS;
    A->data[index] |= 1U << (elem % BITS);

}

int setContains(Set* A, int x){
    return  (A->data[x / BITS] & (1U << (x % BITS))) != 0;
}


void printSet(Set A) {
    for (int i = 0; i < A.size; i++) {
        if (setContains(&A, i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

Set un(Set A, Set B){
    Set C;
    int i;
    C.size = A.size;
    C.data = (unsigned int*) calloc (C.size, sizeof(unsigned int));
    for (i = 0; i < C.size; i++){
        C.data[i] = A.data[i] | B.data[i];
    }
    return C;
}
Set inter(Set A, Set B){
    
    Set C;
    C.size = A.size;
    int i;
    C.data = (unsigned int*) calloc (C.size, sizeof(unsigned int));
    for (i = 0; i < C.size; i++){
        C.data[i] = A.data[i] & B.data[i];
    }
    return C;
}

Set diff(Set A, Set B){
    
    Set C;
    int i;
    C.size = A.size;
    C.data = (unsigned int*) calloc (C.size, sizeof(unsigned int));
    for (i = 0; i < C.size; i++){
        C.data[i] = A.data[i] & ~B.data[i];
    } 

    return C;
}




int main (){
    Set A;
    Set B;
    int size = 1;
    Set C;
    A.data = (unsigned int*) calloc(size , sizeof(unsigned int));
    B.data = (unsigned int*) calloc (size , sizeof(unsigned int));
    A.size = size * BITS;
    B.size = size * BITS;
    addElem(&A, 2);
    addElem(&A, 3);
    addElem(&A, 6);
    addElem(&A, 7);
    addElem(&A, 1);
    

    addElem(&B, 4);
    addElem(&B, 2);
    addElem(&B, 6);
    addElem(&B, 1);
    addElem(&B, 9);

    printf("Set A\n");
    printSet(A);
    printf("Set B\n");
    printSet(B);
    
    C = un(A, B);
    printf("Set C union\n");
    printSet(C);
    free(C.data);

    printf("Set C intersection\n");
    C = inter(A, B);
    printSet(C);
    free(C.data);
    
    printf("Set C difference\n");
    C = diff(A, B);
    printSet(C);
    free(C.data);

    free(A.data);
    free(B.data);
    return 0;
}
