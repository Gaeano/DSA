#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// --- STRUCTURE DEFINITION ---
typedef struct node{
    int elem;
    struct node* LC;
    struct node* RC;
} BST;


typedef struct{
    BST* node[MAX];
    int top;
}Stack;

typedef struct{
    BST* node[MAX];
    int front;
    int rear;
}Queue;


void initializeQ(Queue* q){
    q->front = 0;
    q->rear = -1;
}

int isFullQ(Queue q){
    return ((q.rear + 2) % MAX) == q.front;
}

int isEmptyQ(Queue q){
    return ((q.rear + 1) % MAX) == q.front;
}

void enqueue(Queue* q , BST* data){
    if (!isFullQ(*q)){
        q->rear = (q->rear + 1) % MAX;
        q->node[q->rear] = data;
    }
}

BST* dequeue(Queue* q){
    BST* toReturn;
    if (!isEmptyQ(*q)){
        toReturn = q->node[q->front];
        q->front = (q->front + 1) % MAX;
    }

    return toReturn;


}
void initialize(Stack * s){
    s->top = 0;
}

bool isEmpty(Stack s){
    return (s.top == 0);
}

BST* pop(Stack* s){
    if (!isEmpty(*s)){
        BST* data = s->node[s->top-1];
        s->top--;
        return data;
    }
    
}

void push(Stack * s, BST* data){
    if (s->top < MAX){
        s->node[s->top] = data;
        s->top++;

    }
}

BST* peek (Stack * s){
    return s->node[s->top-1];
}



// --- HELPER FUNCTIONS (ALREADY WRITTEN FOR YOU) ---

// 1. Corrected Insert Function (Double Pointer)
void insert(BST** B, int data) {
    BST** trav = B;
    while (*trav != NULL && (*trav)->elem != data) {
        trav = (data < (*trav)->elem) ? &(*trav)->LC : &(*trav)->RC;
    }
    if (*trav == NULL) {
        *trav = (BST*)malloc(sizeof(BST));
        if (*trav != NULL) {
            (*trav)->elem = data;
            (*trav)->LC = NULL; // Vital initialization
            (*trav)->RC = NULL; // Vital initialization
        }
    }
}

// 2. Display Function
// void inorder(BST* B) {
//     if (B != NULL) {
//         inorder(B->LC);
//         printf("%d ", B->elem);
//         inorder(B->RC);
//     }
// }

void inorder(BST* B) {
    Stack s;
    BST* temp = B;
    initialize(&s);

    while (temp != NULL || !isEmpty(s)){
        while (temp != NULL){
            push(&s, temp);
            temp = temp->LC;
        }

     
        temp = pop(&s);  
        printf("%d ", temp->elem);
        temp = temp->RC;
    }


}


// --- YOUR PRACTICE FUNCTIONS (FILL THESE IN) ---

// Problem 1: Count Leaf Nodes
// Returns the number of nodes that have NO children.
int countLeavesIte(BST* B) { 
    // TODO: Write your logic here
    int count = 0;
    
    Stack s;
    initialize(&s);

    push(&s, B);

    while (!isEmpty(s)){
        BST* current = pop(&s);
        if (current->LC == NULL && current->RC == NULL){
            count++;
            break;
        }

        if (current->RC != NULL){
            push(&s, current->RC);
        }

        if (current->LC != NULL){
            push(&s, current->LC);
        }

    }

    return count; // Placeholder
}


int countLeavesRec(BST* B) { 
    // TODO: Write your logic here
    

    if (B == NULL){
        return 0;
    }

    if (B->LC == NULL && B->RC == NULL){
        return 1;
    } 

   int leftCount = countLeavesRec(B->LC);
   int rightCount = countLeavesRec(B->RC);

    return (leftCount + rightCount);
    
    
}

int getHeightRec(BST* B){
    if (B == NULL){
        return -1;
    }


    int leftCount = getHeightRec(B->LC);
    int rightCount = getHeightRec(B->RC);

    if (leftCount > rightCount){
        return leftCount + 1;
    } else {
        return rightCount + 1;
    }
}

// Problem 2: Find Tree Height (Edges)
// Returns the number of edges on the longest path from root to leaf.
// Empty tree = -1, Root only = 0.
int getHeightIte(BST* B) {
    // TODO: Write your logic here
     int maximumHeight = 0;
    Queue q;
    initializeQ(&q);

    enqueue(&q, B);

    while (!isEmptyQ(q)){
        BST* current = dequeue(&q);
        maximumHeight++;
        
        if (current->LC != NULL){
            enqueue(&q, current->LC);
        }
        
        if (current->RC != NULL){
            enqueue(&q, current->RC);
        }
        
    }

    return maximumHeight; // Placeholder
}

// Problem 3: Lowest Common Ancestor
// Returns the pointer to the node that is the lowest ancestor of n1 and n2.
// Assume n1 and n2 exist in the tree.
BST* findLCA(BST* B, int n1, int n2) {
    // TODO: Write your logic here
    
    if (B == NULL){
        return B;
    }
    BST* trav;
    for (trav = B; trav != NULL;){
        if (n1 < trav->elem && n2 < trav->elem){
            trav = trav->LC;
        } else if (n1 > trav->elem && n2 > trav->elem){
            trav = trav->RC;
        } else {
            return trav;
        }


    }

    return NULL;
    
}

// Problem 4: Check if Valid BST
// Returns true if the tree satisfies the BST property (Left < Node < Right) for ALL nodes.
// Hint: Use the Inorder Traversal property.

bool isValidHelper (BST* B, int* prev){
    if (B == NULL){
        return true;
    }

    if (!isValidHelper(B->LC, prev)){
        return false;
    }

    if (B->elem <= *prev){
        return false;
    }
    *prev = B->elem;

    return isValidHelper(B->RC, prev);
}


bool isValidBST(BST* B) {
    // TODO: Write your logic here

    Stack s;
    initialize(&s);
    BST* temp = B;
    BST* prev = NULL;
    while (temp != NULL || !isEmpty(s)){
        while (temp != NULL){
            push(&s, temp);
            temp = temp->LC;
        }

        temp = pop(&s);
        if (prev != NULL && temp->elem <= prev->elem){
            return false;
        }

        prev = temp;
        temp = temp->RC;
        
    }


    

    return true;


}

// Problem 5: Destroy Tree
// Frees ALL memory and sets the root pointer to NULL.
void destroyTree(BST** B) {
    // TODO: Write your logic here
   Stack s1;
   Stack s2;

   initialize(&s1);
   initialize(&s2);

   push(&s1, *B);

    while (!isEmpty(s1)){
        BST* current = pop(&s1);
        push(&s2, current);

        if (current->LC != NULL){
            push(&s1, current->LC);
        }

        if (current->RC != NULL){
            push(&s1, current->RC);
        }
    }   

    while (!isEmpty(s2)){
        BST* current = pop(&s2);
        free(current);

    }
    *B = NULL;

}
// --- MAIN FUNCTION (TESTS) ---

int main() {
    BST* myTree = NULL;
    Stack s;

    initialize(&s);

    // 1. Build the Tree
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        insert(&myTree, values[i]);
    }

    printf("--- Current Tree (Inorder) ---\n");
    inorder(myTree);
    printf("\n\n");

    // 2. Test Count Leaves
    printf("--- Test 1: Count Leaves ---\n");
    int leaves = countLeavesRec(myTree);
    printf("Your Answer: %d\n", leaves);
    printf("Expected:    4\n"); 

    // 3. Test Height
    printf("\n--- Test 2: Tree Height ---\n");
    int height = getHeightRec(myTree);
    printf("Your Answer: %d\n", height);
    printf("Expected:    2\n"); 

    // 4. Test Lowest Common Ancestor (LCA)
    printf("\n--- Test 3: Find LCA ---\n");
    BST* lca = findLCA(myTree, 20, 40);
    if (lca != NULL) printf("LCA of 20 & 40: %d (Expected: 30)\n", lca->elem);
    else printf("LCA of 20 & 40: NULL (Error)\n");

    lca = findLCA(myTree, 20, 80);
    if (lca != NULL) printf("LCA of 20 & 80: %d (Expected: 50)\n", lca->elem);
    else printf("LCA of 20 & 80: NULL (Error)\n");

    // 5. Test isValidBST
    printf("\n--- Test 4: Is Valid BST ---\n");
    // Original Tree is valid
    bool valid = isValidBST(myTree);
    printf("Original Tree Valid? %s (Expected: Yes)\n", valid ? "Yes" : "No");
    
    // Force a violation for testing: Change 40 to 100 (100 is in left subtree of 50, violating BST property)
    if(myTree->LC->RC != NULL) myTree->LC->RC->elem = 100; 
    
    valid = isValidBST(myTree);
    printf("Broken Tree Valid?   %s (Expected: No)\n", valid ? "Yes" : "No");

    // Fix it back for destruction
    if(myTree->LC->RC != NULL) myTree->LC->RC->elem = 40; 

    // 6. Test Destroy Tree
    printf("\n--- Test 5: Destroy Tree ---\n");
    destroyTree(&myTree);
    if (myTree == NULL) {
        printf("Tree pointer is NULL. (Success)\n");
    } else {
        printf("Tree pointer is NOT NULL. (Failed)\n");
    }

    return 0;
}
