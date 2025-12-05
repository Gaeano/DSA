#include <stdio.h>
#include <stdlib.h>

// Tree node structure
typedef struct TreeNode {
    int ripeness;           // Ripeness level (0-100)
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a new tree node
TreeNode* createNode(int ripeness) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->ripeness = ripeness;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct{
    TreeNode* arr[10];
    int top;
}Stack;

void initStack(Stack* s){
    s->top = -1;
}

void push(Stack* s, TreeNode* data){
    if (s->top < 10){
        s->arr[s->top+1] = data;
        s->top++;
    }
}

TreeNode* pop(Stack* s){
    if (s->top != -1){
        TreeNode* toReturn = s->arr[s->top];
        s->top--;
        return toReturn;
    }
}
// TODO: Implement removeRottenApples function
// Remove all nodes with ripeness < 20 from the tree
// Return the new root of the tree
TreeNode* removeRottenApples(TreeNode* root) {
    // Your code here
    TreeNode* toRemove[10];
    if (root == NULL){
        return NULL;
    }
    Stack s;
    initStack(&s);
    TreeNode* temp = root;
    int i = 0;
    int rottenCount = 0;
    while (temp != NULL || s.top != -1){
        while (temp != NULL){
            push(&s, temp);
            temp = temp->left;
        }
        
        temp = pop(&s);
        if (temp->ripeness < 20){
            toRemove[i] = temp;
            i++;
            rottenCount++;
        }
        temp = temp->right;
    }
    
    
    TreeNode** trav, *holder, **trav2;
    for (i = 0; i < rottenCount; i++){
        for (trav = &root; *trav != NULL && (*trav)->ripeness != toRemove[i]->ripeness;){
            trav = ((*trav)->ripeness > toRemove[i]->ripeness) ? &(*trav)->left : &(*trav)->right;
        }
        if (*trav != NULL){
            if ((*trav)->left == NULL){
                holder = *trav;
                *trav = holder->right;
                free(holder);
            } else if ((*trav)->right == NULL){
                holder = *trav;
                *trav = holder->left;
                free(holder);
            } else {
                for (trav2 = &(*trav)->right; (*trav2)->left != NULL && (*trav2)->ripeness != toRemove[i]->ripeness; trav2 = &(*trav2)->left){
                    
                }
                
                holder = *trav2;
                *trav2 = holder->right;
                (*trav)->ripeness = (*trav2)->ripeness;
                free(holder);
            }
        }
    }
    
    
    
    
    
    
    return root;
}

// Helper function to print tree (preorder)
void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->ripeness);
    printTree(root->left);
    printTree(root->right);
}

// Helper function to print tree structure (indented)
void printTreeStructure(TreeNode* root, int space) {
    if (root == NULL) return;
    
    space += 5;
    printTreeStructure(root->right, space);
    
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->ripeness);
    
    printTreeStructure(root->left, space);
}

// Helper function to free tree memory
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("========== REMOVE ROTTEN APPLES ==========\n\n");
    
    // Build test tree (Now a valid BST)
    //         50
    //        /  \
    //      15    80
    //     / \    / \
    //    10 25  60 90
    TreeNode* root = createNode(50);
    root->left = createNode(15);   // Rotten
    root->right = createNode(80);
    root->left->left = createNode(10); // Rotten
    root->left->right = createNode(25);
    root->right->left = createNode(60); // Not Rotten
    root->right->right = createNode(90);
    
    printf("Apple Tree (ripeness levels):\n");
    printf("Original tree structure:\n");
    printf("      50\n");
    printf("     /  \\\n");
    printf("    15    80\n");
    printf("   / \\    / \\\n");
    printf("  10 25  60 90\n\n");
    
    printf("Original tree (preorder): ");
    printTree(root);
    printf("\n\n");
    
    printf("Removing rotten apples (ripeness < 20)...\n");
    printf("Rotten apples to remove: 15, 10\n\n");
    
    root = removeRottenApples(root);
    
    printf("\nTree after removal (preorder): ");
    printTree(root);
    printf("\n\n");
    
    printf("Tree structure after removal:\n");
    printTreeStructure(root, 0);
    
    printf("\n========== EXPECTED OUTPUT ==========\n");
    // After removing 15 (which has two children 10 and 25, but 10 is also removed recursively),
    // 15 is replaced by its right child 25. 10 is deleted first by the recursion.
    // The final structure should be 50(L:25, R:80), and 80(L:60, R:90).
    printf("Tree after removal (preorder): 50 25 80 60 90\n");
    printf("Removed nodes: 15, 10\n");
    printf("\nExpected structure:\n");
    printf("      50\n");
    printf("     /  \\\n");
    printf("    25    80\n");
    printf("         / \\\n");
    printf("        60 90\n");
    
    // Clean up
    freeTree(root);
    
    return 0;
}