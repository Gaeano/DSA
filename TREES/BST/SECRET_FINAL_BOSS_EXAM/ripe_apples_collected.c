#include <stdio.h>
#include <stdlib.h>

#define MAX_APPLES 100

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
    TreeNode* arr[MAX_APPLES];
    int top;
}Stack;

void initStack(Stack* s){
    s->top = -1;
}

void push(Stack* s, TreeNode* data){
    if (s->top != MAX_APPLES){
        s->arr[s->top+1] = data;
        s->top++;
    }
}

int isStackEmpty(Stack* s){
    return (s->top < 0) ? 1 : 0;
}

TreeNode* pop(Stack* s){
    if (!isStackEmpty(s)){
        TreeNode* toReturn = s->arr[s->top];
        s->top--;
        return toReturn;
    }
    
  
}

// TODO: Implement collectRipeApples function
// Collect all apples with ripeness >= 90
// Use any traversal method (preorder, inorder, postorder)
//using preOrderTraversal
void collectRipeApples(TreeNode* root, int result[], int* count) {
    // Your code here
    if (root == NULL){
        return;
    }
    
    Stack s;
    initStack(&s);
    
    push(&s, root);
    
    while (!isStackEmpty(&s)){
        TreeNode* current = pop(&s);
        if (current->ripeness >= 90){
            result[*count] = current->ripeness;
            (*count)++;
        }
        
        if (current->right != NULL){
            push(&s, current->right);
        }
        
        if (current->left != NULL){
            push(&s, current->left);
        }
    }
}

// Helper function to print tree (preorder)
void printTree(TreeNode* root) {
    if (root == NULL) {
        printf("null ");
        return;
    }
    printf("%d ", root->ripeness);
    printTree(root->left);
    printTree(root->right);
}

// Helper function to free tree memory
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("========== COLLECT RIPE APPLES ==========\n\n");
    
    // Build test tree
    //        95
    //       /  \
    //      85   92
    //     / \   / \
    //    50 88 91 100
    TreeNode* root = createNode(95);
    root->left = createNode(85);
    root->right = createNode(92);
    root->left->left = createNode(50);
    root->left->right = createNode(88);
    root->right->left = createNode(91);
    root->right->right = createNode(100);
    
    printf("Apple Tree (ripeness levels):\n");
    printf("Tree structure:\n");
    printf("        95\n");
    printf("       /  \\\n");
    printf("      85   92\n");
    printf("     / \\   / \\\n");
    printf("    50 88 91 100\n\n");
    
    printf("Tree (preorder traversal): ");
    printTree(root);
    printf("\n\n");
    
    printf("Collecting ripe apples (ripeness >= 90)...\n\n");
    
    int ripeApples[MAX_APPLES];
    int count = 0;
    collectRipeApples(root, ripeApples, &count);
    
    printf("Ripe apples collected: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", ripeApples[i]);
    }
    printf("\n");
    printf("Total ripe apples: %d\n", count);
    
    printf("\n========== EXPECTED OUTPUT ==========\n");
    printf("Ripe apples collected: 95 92 91 100\n");
    printf("Total ripe apples: 4\n");
    printf("\nNote: Order may vary depending on traversal method used\n");
    
    // Clean up
    freeTree(root);
    
    return 0;
}