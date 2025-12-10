#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct node{
    int data;
    struct node* LC;
    struct node* RC;
}BST;

typedef struct{
    BST* elems[MAX];
    int top;
}Stack;

void initializeStack(Stack* s){
    s->top = -1;
}

void push(Stack* s, BST* root){
    if (s->top < MAX - 1){
        s->elems[s->top+1] = root;
        s->top++;
    }
}

BST* pop(Stack* s){
    if (s->top != -1){
        BST* toReturn = s->elems[s->top];
        s->top--;
        return toReturn;
    }
    
}


BST* createNode(int data){
    BST* newNode = malloc (sizeof(BST));
    newNode->data = data;
    newNode->LC = NULL;
    newNode->RC = NULL;
    
    return newNode;
}


void insertToBST(BST** root, int data){
    BST** trav;
    
    for (trav = root; *trav != NULL && (*trav)->data != data;){
        trav = ((*trav)->data > data) ? &(*trav)->LC : &(*trav)->RC;
    }
    
    if (*trav == NULL){
        *trav = createNode(data);
        printf("inserted %d to tree\n", data);
    }
    
    
}

void deleteInBST(BST** root, int data){
    int found = 0;
    if (*root == NULL){
        return;
    }
    
    BST** trav, **trav2, *holder;
    
    for (trav = root; *trav != NULL && (*trav)->data != data;){
        trav = ((*trav)->data > data) ? &(*trav)->LC : &(*trav)->RC;
    }
    
    if (*trav != NULL){
        if ((*trav)->LC == NULL){
            holder = *trav;
            *trav = holder->RC;
            found = 1;
            free(holder);
        } else if ((*trav)->RC == NULL){
            holder = *trav;
            *trav = holder->LC;
            found = 1;
            free(holder);
        } else {
            for (trav2 = &(*trav)->RC; (*trav2)->LC != NULL && (*trav2)->data != data; trav2 = &(*trav2)->LC){
                
            }
            
            
            holder = *trav2;
            *trav2 = holder->RC;
            (*trav)->data = holder->data;
            found = 1;
            free(holder);
        }
    }
    
    if (found == 0){
        printf("-> data %d does not exist in the tree\n", data);
    } else {
        printf("-> data %d successfully deleted from the tree\n", data);
    }
    
}

void preorder(BST* root){
    Stack s;
    
    
    initializeStack(&s);
    
    push(&s, root);
    
    while (s.top != -1){
        BST* current = pop(&s);
        printf("%d ", current->data);
        
        if (current->RC != NULL){
            push(&s, current->RC);
        }
        
        if (current->LC != NULL){
            push(&s, current->LC);
        }
    }
}

void inorder(BST* root){
    if (root == NULL){
        return;
    }
    
    BST* temp = root;
    Stack s;
    initializeStack(&s);
    
    while (temp != NULL || s.top != -1){
        while (temp != NULL){
            push(&s, temp);
            temp = temp->LC;
        }
        
        temp = pop(&s);
        printf("%d ", temp->data);
        temp = temp->RC;
    }
}

void freeTree(BST** root){
    Stack s1;
    Stack s2;
    
    
    initializeStack(&s1);
    initializeStack(&s2);
    
    push(&s1, *root);
    
    while (s1.top != -1){
        BST* current = pop(&s1);
        push(&s2, current);
        
        if (current->LC != NULL){
            push(&s1, current->LC);
        }
        
        if (current->RC != NULL){
            push(&s1, current->RC);
        }
    }
    
    while (s2.top != -1){
        BST* current = pop(&s2);
        printf("freeing current %d\n", current->data);
        free(current);
    }
    
    *root = NULL;
}

bool isItABST(BST* root){
    if (root == NULL){
        return false;
    }
    
    Stack s;
    BST* temp = root;
    BST* prev = NULL;
    
    initializeStack(&s);
    while (temp != NULL || s.top != -1){
        while (temp != NULL){
            push(&s, temp);
            temp = temp->LC;
        }
        
        temp = pop(&s);
        
        if (prev != NULL && prev->data > temp->data){
            return false;
        }
        
        prev = temp;
        
        temp = temp->RC;
        
    }
    
    return true;
}




int main (){
    
    int arr[MAX] = {50, 20, 60, 15, 25, 55, 65, 10, 30, 90};
    BST* root = NULL;
    
    
    printf("Enter the numbers you want to input into the tree\n");
    int num;
    int i;
    // for (i = 0; i < MAX; i++){
    //     scanf("%d", &num);
        
    //     arr[i] = num;
    // }
    
    for (i = 0; i < MAX; i++){
        insertToBST(&root, arr[i]);
    }
    
    
    printf("==PREORDER TRAVERSAL\n");
    preorder(root);
    
    printf("\n==INORDER TRAVERSAL\n");
    inorder(root);
    
    printf("\n");
    
    bool answer = isItABST(root);
    printf("is it a bst? ");
    if (answer){
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    printf("==Delete from tree\n");
    
    deleteInBST(&root, 15);
    deleteInBST(&root, 2);
    
     printf("==PREORDER TRAVERSAL\n");
    preorder(root);
    
    printf("\n==INORDER TRAVERSAL\n");
    inorder(root);
    
    printf("\n");
    
    printf("\n");
    freeTree(&root);
    
    if (root == NULL){
        printf("\nsuccessfully freed Tree\n");
    }
    
    return 0;
    
}