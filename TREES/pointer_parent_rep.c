#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int* arr;
    int count;
}Tree;

void initializeTree(Tree* tree){
    tree->arr = (int*) malloc(MAX * sizeof(int));
    tree->count = 0;
    int i;
    for (i = 0; i < MAX; i++){
        tree->arr[i] = -1;
    }

}


void insertValue(Tree* tree, int parent, int child){
    if (child >= 0 && child < MAX && parent < MAX){
        if (tree->arr[child] == -1){
            tree->count++;
        }
        tree->arr[child] = parent;
    }
    
}


void showTree(Tree tree){
    int i;
    for (i = 0; i < MAX; i++){
        if (tree.arr[i] != -1){
            printf("Parent: %d child: %d\n", tree.arr[i], i);
        }
            
    }
}


void freeTree(Tree* tree){
    free(tree->arr);
    tree->arr = NULL;
}

int main (){
    
    Tree tree;
    initializeTree(&tree);

    insertValue(&tree, -1, 0); 

    
    insertValue(&tree, 0, 1);
    insertValue(&tree, 0, 2);
    insertValue(&tree, 1, 4);
    insertValue(&tree, 1, 6);
    insertValue(&tree, 2, 3);

    showTree(tree);

    freeTree(&tree);
    return 0;
}