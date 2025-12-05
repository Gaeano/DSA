#include <stdio.h>
#include <stdlib.h>

#define FOREST_SIZE 5

// Tree node structure
typedef struct TreeNode {
    int value;              // Value of the apple
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a new tree node
TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// TODO: Implement plantAppleSeeds function
// Plant new apple trees (with initial value 10) at specified indices in the forest
// If index already has a tree, add the seed as a new node in that tree
// If index is empty (NULL), create a new tree with the seed
void plantAppleSeeds(TreeNode* forest[], int forestSize, int seedIndices[], int numSeeds) {
    // Your code here
    // Hint: For planting in existing tree, you might want to insert at the leftmost available position
    // For empty spots, just create a new single-node tree
    int i, j;
    for (i = 0; i < numSeeds; i++){
        int data = seedIndices[i];
        
       
   
        if (forest[data] == NULL){
            forest[data] = createNode(10);
        } else {
            TreeNode **trav;
            TreeNode* newNode = createNode(10);
            
            for (trav = &forest[data]; (*trav)->left != NULL; trav = &(*trav)->left){
                
            }
            
            (*trav)->left = newNode;
           
        }
            
        
    }
    
}

// Helper function to print tree (preorder)
void printTree(TreeNode* root) {
    if (root == NULL) {
        printf("empty ");
        return;
    }
    printf("%d ", root->value);
    if (root->left != NULL || root->right != NULL) {
        printTree(root->left);
        printTree(root->right);
    }
}

// Helper function to count nodes in tree
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Helper function to free tree memory
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("========== PLANT APPLE SEEDS IN FOREST ==========\n\n");
    
    // Initialize forest
    TreeNode* forest[FOREST_SIZE];
    
    // Tree 0: Small tree
    forest[0] = createNode(50);
    forest[0]->left = createNode(30);
    forest[0]->right = createNode(70);
    
    // Tree 1: Another tree
    forest[1] = createNode(60);
    forest[1]->left = createNode(40);
    forest[1]->right = createNode(80);
    
    // Tree 2: Empty spot
    forest[2] = NULL;
    
    // Tree 3: Single node tree
    forest[3] = createNode(45);
    
    // Tree 4: Empty spot
    forest[4] = NULL;
    
    printf("Original Forest:\n");
    printf("================\n");
    for (int i = 0; i < FOREST_SIZE; i++) {
        printf("Tree %d: ", i);
        printTree(forest[i]);
        printf("\n");
    }
    
    printf("\nPlanting apple seeds (value=10) at indices: 2, 4\n\n");
    
    int seedIndices[] = {2, 4};
    int numSeeds = 2;
    
    plantAppleSeeds(forest, FOREST_SIZE, seedIndices, numSeeds);
    
    printf("Forest After Planting:\n");
    printf("======================\n");
    for (int i = 0; i < FOREST_SIZE; i++) {
        printf("Tree %d: ", i);
        printTree(forest[i]);
        printf(" (nodes: %d)\n", countNodes(forest[i]));
    }
    
    printf("\nPlanting apple seeds (value=10) at indices: 0, 1, 3\n\n");
    numSeeds = 3;
    int theIndicesTobePlantedNew[] = {0, 1, 3};
    
    plantAppleSeeds(forest, FOREST_SIZE, theIndicesTobePlantedNew, numSeeds);
    
    printf("Forest After Planting:\n");
    printf("======================\n");
    for (int i = 0; i < FOREST_SIZE; i++) {
        printf("Tree %d: ", i);
        printTree(forest[i]);
        printf(" (nodes: %d)\n", countNodes(forest[i]));
    }
    
    printf("\n========== EXPECTED OUTPUT ==========\n");
    printf("Forest After Planting:\n");
    printf("Tree 0: 50 30 70 (nodes: 3) [unchanged]\n");
    printf("Tree 1: 60 40 80 (nodes: 3) [unchanged]\n");
    printf("Tree 2: 10 (nodes: 1) [NEW - seed planted]\n");
    printf("Tree 3: 45 (nodes: 1) [unchanged]\n");
    printf("Tree 4: 10 (nodes: 1) [NEW - seed planted]\n");
    
    // Clean up
    for (int i = 0; i < FOREST_SIZE; i++) {
        freeTree(forest[i]);
    }
    
    return 0;
}
