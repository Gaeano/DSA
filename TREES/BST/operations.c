#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node{
    int elem;
    struct node* LC;
    struct node* RC;
}BST;


void insert (BST** B, int data);
void delete (BST** B, int data);
bool isMember(BST* B, int data);
int minimum(BST* B);
int maxmimum (BST* B);
// void preorder (BST* B);
// void postorder(BST* B);
void inorder(BST* B);

void inorder(BST* B){
    if (B != NULL){
        inorder(B->LC);
        printf("%d ", B->elem);
        inorder(B->RC);
    }
}

bool isMember(BST* B, int data){
    if (B != NULL){
    if (B->elem == data){
            return true; //data exists
        } else {
            return false;
        }
    } 

}

void insert (BST** B, int data){
    BST** trav;


    for (trav = B; *trav != NULL && (*trav)->elem != data;){
        trav = ((*trav)->elem > data) ? &(*trav)->LC : &(*trav)->RC;
    }

    if (*trav == NULL){
        *trav = malloc (sizeof(BST));
        if (*trav != NULL){
            (*trav)->elem = data;
            (*trav)->RC = NULL;
            (*trav)->LC = NULL;
        }
    }
}

void delete (BST** B, int data){
    BST** trav, **trav2, *holder;

    for (trav = B; *trav != NULL && (*trav)->elem != data;){
        trav = ((*trav)->elem > data) ? &(*trav)->LC : &(*trav)->RC;
    }

    if (*trav != NULL){
        if ((*trav)->LC == NULL){
            holder = *trav;
            *trav = holder->RC;
            free(holder);
        } else if ((*trav)->RC == NULL){
            holder = *trav;
            *trav = holder->LC;
            free(holder);
        } else {
            for (trav2 = &(*trav)->RC; (*trav2)->LC !=  NULL; trav2 = &(*trav2)->LC){}

            holder = *trav2;
            *trav2 = holder->RC;
            (*trav)->elem = holder->elem;
            free(holder);
        }
    }
}

int minimum(BST* B){
   
    if (B == NULL){
    return 0;
   }

    while (B->LC != NULL){
        B = B->LC;
    }
    
    return B->elem;


}

int maxmimum (BST* B){
    if (B == NULL){
    return 0;
   }

    while (B->RC != NULL){
        B = B->RC;
    }
    
    return B->elem;


}


int main(){
    BST *myTree = NULL; // Start with an empty tree

    printf("--- 1. BST Population ---\n");
    int dataToInsert[] = {50, 30, 70, 20, 40, 60, 80};
    int i;
    for (i = 0; i < 7; i++) {
        insert(&myTree, dataToInsert[i]);
        printf("Inserted %d\n", dataToInsert[i]);
    }
    
    printf("\n--- 2. Inorder Traversal (Expected: 20 30 40 50 60 70 80) ---\n");
    printf("Result: ");
    inorder(myTree);
    printf("\n");

    printf("\n--- 3. Property Checks (Based on Your Logic) ---\n");
    printf("Minimum value: %d\n", minimum(myTree));
    printf("Maximum value: %d\n", maxmimum(myTree));
    
    printf("Is 50 a member (Root check only)? %s\n", isMember(myTree, 50) ? "Yes" : "No");
    printf("Is 30 a member (Root check only)? %s\n", isMember(myTree, 30) ? "Yes" : "No");
    
    printf("\n--- 4. Deletion Test (Delete Root: 50) ---\n");
    delete(&myTree, 50);
    printf("After deleting 50: ");
    inorder(myTree);
    printf("\n");

    printf("\n--- 5. Deletion Test (Delete Leaf: 20) ---\n");
    delete(&myTree, 20);
    printf("After deleting 20: ");
    inorder(myTree);
    printf("\n");
    
    return 0;
}