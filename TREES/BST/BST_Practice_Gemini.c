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
        printf("%d", temp->elem);
        temp = temp->RC;
    }


}

// --- YOUR PRACTICE FUNCTIONS (FILL THESE IN) ---

// Problem 1: Count Leaf Nodes
// Returns the number of nodes that have NO children.
int countLeaves(BST* B) { 
    // TODO: Write your logic here
    int count = 0;
    BST* trav, *trav2, *holder;
    //for the left subtree
    for (trav = B->LC; trav != NULL; trav = trav->LC){ 

        for(trav2 = trav->RC; trav2 != NULL;){
            if (trav2->RC != NULL && trav2->LC != NULL){
                trav2 = trav2->RC;
                holder = trav2->LC;
            } else if (trav2->LC != NULL && trav2->RC == NULL){
                trav2 = trav2->LC;
            } else if (trav2->LC != NULL && trav2->LC == NULL){
                trav2 = trav2->RC;
            }

            if (trav2->LC == NULL && trav2->RC == NULL){ //if a node has no children (its a leaf)
                count++;
                holder = NULL;
            }
            trav2 = holder;
        }

        if (trav->LC == NULL && trav->RC == NULL){ //if a node has no children (its a leaf)
                count++;
        }

        free(holder);
        
    }
    
    //for the right subtree
    for (trav = B->RC; trav != NULL; trav = trav->RC){ 

        for(trav2 = trav->LC; trav2 != NULL;){
            if (trav2->RC != NULL && trav2->LC != NULL){
                trav2 = trav2->RC;
                holder = trav2->LC;
            } else if (trav2->LC != NULL && trav2->RC == NULL){
                trav2 = trav2->LC;
            } else if (trav2->RC != NULL && trav2->LC == NULL) {
                trav2 = trav2->RC;
            }

            if (trav2->LC == NULL && trav2->RC == NULL){ //if a node has no children (its a leaf)
                count++;
                holder = NULL;
            }
            trav2 = holder;
        }

        if (trav->LC == NULL && trav->RC == NULL){ //if a node has no children (its a leaf)
            count++;
        }

        free(holder);
        
    }

    return count; // Placeholder
}

// Problem 2: Find Tree Height (Edges)
// Returns the number of edges on the longest path from root to leaf.
// Empty tree = -1, Root only = 0.
int getHeight(BST* B) {
    // TODO: Write your logic here
    int maximumHeight = 0;
    int count = 0;

    BST* trav, *trav2, *holder;
    //for the left subtree
    for (trav = B->LC; trav != NULL; trav = trav->LC){ 
        count++;
        for(trav2 = trav->RC; trav2 != NULL;){
            count++;
            holder = NULL;
            if (trav2->RC != NULL && trav2->LC != NULL){
                trav2 = trav2->RC;
                holder = trav2->LC;
            } else if (trav2->LC != NULL && trav2->RC == NULL){
                trav2 = trav2->LC;
            } else if (trav2->LC != NULL && trav2->LC == NULL){
                trav2 = trav2->RC;
            }

            trav2 = holder;
        }


        if (count > maximumHeight){
            maximumHeight = count;
        }
        count = 1; //reset to 1, since the root is automatically counted

        free(holder);
        
    }
    count = 0;
    //for the right subtree
    for (trav = B->RC; trav != NULL; trav = trav->RC){ 
        count++;
        for(trav2 = trav->LC; trav2 != NULL;){
            count++;
            holder = NULL;
            if (trav2->RC != NULL && trav2->LC != NULL){
                trav2 = trav2->RC;
                holder = trav2->LC;
            } else if (trav2->LC != NULL && trav2->RC == NULL){
                trav2 = trav2->LC;
            } else if (trav2->RC != NULL && trav2->LC == NULL) {
                trav2 = trav2->RC;
            }
            trav2 = holder;
        }

         if (count > maximumHeight){
            maximumHeight = count;
        }
        
        count = 1; //reset to 1, since the root is automatically counted

        free(holder);
        
    }

    
    return maximumHeight; // Placeholder
}

// Problem 3: Lowest Common Ancestor
// Returns the pointer to the node that is the lowest ancestor of n1 and n2.
// Assume n1 and n2 exist in the tree.
BST* findLCA(BST* B, int n1, int n2) {
    // TODO: Write your logic here
    BST* ancestor, *trav;
    int finalAncestor;
    int ancestor1[10];
    int ancestor2[10];
    int ancestor1Count = 0; //serves as count
    int ancestor2Count = 0; //serves as count
    //for n1
    for (trav = B; trav != NULL && trav->elem != n1; ancestor1Count++){
        ancestor1[ancestor1Count] = trav->elem;
        trav = (trav->elem > n1)? trav->LC : trav->RC;
    }

    //for n2
    for (trav = B; trav != NULL && trav->elem != n1; ancestor2Count++){
        ancestor2[ancestor2Count] = trav->elem;
        trav = (trav->elem > n1)? trav->LC : trav->RC;
    }

    //compare and find where the similar iz
    int i, j, found = 0;   
    int sumOfCount = ancestor1Count + ancestor2Count;

    for (i = 0; i < sumOfCount && found == 0; i++){
        for (j = i; j < sumOfCount && found == 0; j++){
            if (ancestor1[i] == ancestor2[j]){
                found = 1;
                finalAncestor = ancestor1[i];
            }
        }
    }

    for (trav = B; trav != NULL && trav->elem != finalAncestor;){
        trav = (trav->elem > n1)? trav->LC : trav->RC;
    }

    if (trav != NULL){
        ancestor = trav;
    }

    return ancestor; // Placeholder
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

    if (B == NULL){
        return true;
    }

    int prev = -1;




    return isValidHelper(B, &prev); // Placeholder
}

// Problem 5: Destroy Tree
// Frees ALL memory and sets the root pointer to NULL.
void destroyTree(BST** B) {
    // TODO: Write your logic here
    if (*B == NULL){
        return;
    }

    destroyTree(&(*B)->LC);
    destroyTree(&(*B)->RC);

    free(*B);

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
    int leaves = countLeaves(myTree);
    printf("Your Answer: %d\n", leaves);
    printf("Expected:    4\n"); 

    // 3. Test Height
    printf("\n--- Test 2: Tree Height ---\n");
    int height = getHeight(myTree);
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
