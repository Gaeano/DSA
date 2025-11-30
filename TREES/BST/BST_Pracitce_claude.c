
#include <stdio.h>
#include <stdlib.h>


// Tree structure (assuming you have this already)
typedef struct BST {
    int data;
    struct BST* LC;  // Left Child
    struct BST* RC;  // Right Child
} BST;

BST* createNode(int data){
    BST* newNode = malloc (sizeof(BST));

    newNode->data = data;
    newNode->RC = NULL;
    newNode->LC = NULL;

    
}

// ============================================
// HELPER FUNCTIONS (you might need these)
// ============================================

// Helper: Get height of tree (you already know this one!)
int getHeight(BST* B) {
    if (B == NULL) {
        return -1;
    }
    
    int leftHeight = getHeight(B->LC);
    int rightHeight = getHeight(B->RC);
    
    if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    } else {
        return 1 + rightHeight;
    }
}

// Helper: Count leaves (you already know this one!)
int countLeaves(BST* B) {
    if (B == NULL) {
        return 0;
    }
    
    if (B->LC == NULL && B->RC == NULL) {
        return 1;
    }
    
    int leftCount = countLeaves(B->LC);
    int rightCount = countLeaves(B->RC);
    
    return leftCount + rightCount;
}


// ============================================
// LEVEL 1: WARMUP PROBLEMS
// ============================================

// Problem 1: Count ALL nodes in the tree
// Example: Tree with 5,3,8,1,7,9 -> returns 6
int countNodes(BST* B) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    } 

    int leftCount = countNodes(B->LC);
    int rightCount = countNodes(B->RC);
    
    
    

    return 1 + leftCount + rightCount;
    
}

// Problem 2: Sum all values in the tree
// Example: Tree with 5,3,8,1,7,9 -> returns 33 (5+3+8+1+7+9)
int sumTree(BST* B) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    }

    int sumLeft =+ sumTree(B->LC);
    int sumRight =+ sumTree(B->RC);

    return B->data + sumLeft + sumRight;
    
}

// Problem 3: Find minimum value in tree
// Example: Tree with 5,3,8,1,7,9 -> returns 1
// Hint: In BST, keep going left!
int findMin(BST* B) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    }

    if (B->LC == NULL){
        return B->data;
    }
   
    return findMin(B->LC);
    
}

// Problem 4: Find maximum value in tree
// Example: Tree with 5,3,8,1,7,9 -> returns 9
// Hint: In BST, keep going right!
int findMax(BST* B) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    }

    if (B->RC == NULL){
        return B->data;
    }

    return findMax(B->RC);
    
}

// Problem 5: Check if a value exists in the tree
// Example: contains(tree, 7) -> returns 1 (true)
//          contains(tree, 99) -> returns 0 (false)
int contains(BST* B, int target) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    }

    if (B->data == target){
        return 1;
    } 
        //traverse and look for each subtree
        int leftResult = contains(B->LC, target);
        int rightResult = contains(B->RC, target);
       
    return leftResult || rightResult;
}


// ============================================
// LEVEL 2: INTERMEDIATE PROBLEMS
// ============================================

// Problem 6: Count nodes at a specific level
// Example: Tree with 5,3,8,1,7,9
//          Level 0 -> 1 (just 5)
//          Level 1 -> 2 (3 and 8)
//          Level 2 -> 3 (1,7,9)
int countAtLevel(BST* B, int targetLevel, int currentLevel) {
    // TODO: Write your logic here
    // Hint: currentLevel starts at 0 for root
    if (B == NULL){
        return 0;
    }

     if (targetLevel == currentLevel){
        return 1;
    }

    
    int leftCount = countAtLevel(B->LC, targetLevel, currentLevel + 1);
    int rightCount = countAtLevel(B->RC, targetLevel, currentLevel + 1);

   
    return rightCount + leftCount;
    
}

// Problem 7: Check if tree is just a single node (a leaf)
// Returns 1 if single node, 0 otherwise
int isSingleNode(BST* B) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    } else if (B->LC == NULL && B->RC == NULL){
        return 1;
    } else {
        return 0;
    }
    
}

// Problem 8: Count internal nodes (nodes with at least one child)
// Example: Tree with 5,3,8,1,7,9 -> returns 3 (nodes 5,3,8 have children)
int countInternalNodes(BST* B) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    }
    if (B->LC == NULL && B->RC == NULL ){
        return 0;
    } 

   
    int leftCount = countInternalNodes(B->LC);
    int rightCount = countInternalNodes(B->RC);

     

    return 1 + leftCount + rightCount;
    
}

// Problem 9: Check if value exists at a specific level
// Returns 1 if found at that level, 0 otherwise
int isAtLevel(BST* B, int target, int targetLevel, int currentLevel) {
    // TODO: Write your logic here
    if (B == NULL){
        return  0;
    }

    if (targetLevel == currentLevel){
        return B->data == target ? 1 : 0;
    }

    int leftCount = isAtLevel(B->LC, target, targetLevel, currentLevel + 1);
    int rightCount = isAtLevel(B->RC, target, targetLevel, currentLevel + 1);

    return (leftCount || rightCount);
}

// Problem 10: Count how many nodes have exactly one child
int countOneChild(BST* B) {
    // TODO: Write your logic here
    // Hint: Check if (left != NULL && right == NULL) || (left == NULL && right != NULL)
    if (B == NULL){
        return 0;
    }

    if (B->LC != NULL && B->RC == NULL){
        return 1;
    } else if (B->LC == NULL && B->RC != NULL){
        return 1;
    }
    
    int left = countOneChild(B->LC);
    int right = countOneChild(B->RC);

    return left + right;
}


// ============================================
// LEVEL 3: EXAM-LEVEL PROBLEMS
// ============================================

// Problem 11: Check if two trees are identical
// Returns 1 if same structure and values, 0 otherwise
int areIdentical(BST* tree1, BST* tree2) {
    // TODO: Write your logic here
    // Hint: Both NULL? Both have same value? Recurse on both subtrees?
    if (tree1 == NULL && tree2 == NULL){
        return 1;
    }

    if (tree1->data != tree2->data){
        return 0;
    }

    int left = areIdentical(tree1->LC, tree2->LC);
    int right = areIdentical(tree1->RC, tree2->RC);
    
    return (left == 0 || right == 0) ? 0 : 1;

    
}

// Problem 12: Find the depth of a specific value
// Returns depth (0 for root), or -1 if not found
int findDepth(BST* B, int target, int currentDepth) {
    // TODO: Write your logic here
    if (B == NULL){
        return -1;
    }

    if(!contains(B, target)){
        return -1;
    }

    if (B->data == target){
        return currentDepth;
    }

    int leftResult = findDepth(B->LC, target, currentDepth + 1);
    int rightResult = findDepth(B->RC, target, currentDepth + 1);

    return 1 + (leftResult || rightResult); //+1 to count current depth

}

int getHeightLeft(BST *B){

    if (B == NULL){
        return -1;
    }

    int leftCount = getHeightLeft(B->LC);
    int rightCount = getHeightLeft(B->RC);

    return 1 + leftCount + rightCount;
}

int getHeightRight(BST *B){

    if (B == NULL){
        return -1;
    }

    int leftCount = getHeightLeft(B->LC);
    int rightCount = getHeightLeft(B->RC);

    return 1 + leftCount + rightCount;
}
// Problem 13: Check if tree is balanced
// A tree is balanced if left and right heights differ by at most 1
// Returns 1 if balanced, 0 otherwise
int isBalanced(BST* B) {
    // TODO: Write your logic here
    // Hint: You might need a helper function to get height 
    int leftCount = getHeightLeft(B->LC);
    int rightCount = getHeightRight(B->RC);

    int difference = leftCount - rightCount;
    if (difference > 1){
        return 0; 
    } else {
        return 1;
    }
    
}

// Problem 14: Check if there's a path from root to leaf that sums to target
// Example: Tree with 5,3,8,1,7,9
//          pathSum(tree, 9) -> 1 (path: 5->3->1 = 9)
//          pathSum(tree, 100) -> 0 (no such path)
int hasPathSum(BST* B, int targetSum, int currentSum) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    }

    currentSum += B->data;
    if (B->LC == NULL && B->RC == NULL){
        return (targetSum == currentSum) ? 1 : 0;
    }
  

    int leftResult = hasPathSum(B->LC, targetSum, currentSum);
    int rightResult = hasPathSum(B->RC, targetSum, currentSum);
    
    return (leftResult || rightResult);
}

// Problem 15: Count how many nodes have two children
int countTwoChildren(BST* B) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    }
    int count = 0;
    if (B->LC != NULL && B->RC != NULL){
        count = 1;;
    }

    int leftCount = countTwoChildren(B->LC);
    int rightCount = countTwoChildren(B->RC);

    return count + leftCount + rightCount;
    
}


// ============================================
// BONUS CHALLENGE PROBLEMS
// ============================================

// Bonus 1: Find the second minimum value in the tree
int findSecondMin(BST* B) {
    // TODO: Write your logic here
    // Hint: This is tricky! Think about going left, then checking right child
    if (B == NULL){
        return 0;
    }
    
    BST* parent = NULL;
    BST* current = B;

    while (current->LC != NULL){
       parent = current;
       current = current->LC;
    }

    if (current->RC != NULL){
        return findMin(current->RC);
    }

    return parent->data;
}

// Bonus 2: Count nodes greater than a given value
int countGreaterThan(BST* B, int value) {
    // TODO: Write your logic here
    if (B == NULL){
        return 0;
    }
    int count = 0;
    if (B->data > value){
        count = 1;
    }

    int leftCount = countGreaterThan(B->LC, value);
    int rightCount = countGreaterThan(B->RC, value);
    
    return count  + leftCount + rightCount;
}

int sumAtLevel(BST* B, int targetLevel, int currentLevel) {
    // TODO: Write your logic here
    // Hint: currentLevel starts at 0 for root
    if (B == NULL){
        return -1;
    }


     if (targetLevel == currentLevel){
        return B->data;
    }

    
    int leftSum = sumAtLevel(B->LC, targetLevel, currentLevel + 1);
    int rightSum = sumAtLevel(B->RC, targetLevel, currentLevel + 1);

   
    return  (leftSum + rightSum);
    
}

// Bonus 3: Find the level with maximum sum of node values
// Returns the level number (0-indexed)
int levelWithMaxSum(BST* B) {
    // TODO: Write your logic here
    // Hint: This is HARD! Might need multiple helper functions
    if (B == NULL){
        return 0;
    }

    int maxSum = -9999;
    int height = getHeight(B);
    int maxLevel = 0;
    for (int i = 0; i <= height; i++){
        int currentSum = sumAtLevel(B, i, 0);
        // printf("current sum = %d\n", currentSum);
        if (currentSum > maxSum){
            maxSum = currentSum;
            maxLevel = i;
            // printf("max sum = %d max level = %d\n", maxSum, maxLevel);
        }
    }

    return maxLevel;

}




// ============================================
// TESTING TEMPLATE
// ============================================

int main() {
    printf("=== BUILDING TEST TREES ===\n\n");
    
    // Tree 1: Main test tree
    //       5
    //      / \
    //     3   8
    //    /   / \
    //   1   7   9
    BST* root = createNode(5);
    root->LC = createNode(3);
    root->RC = createNode(8);
    root->LC->LC = createNode(1);
    root->RC->LC = createNode(7);
    root->RC->RC = createNode(9);
    
    // Tree 2: Single node for testing
    BST* singleNode = createNode(42);
    
    // Tree 3: Identical copy of tree 1
    BST* root2 = createNode(5);
    root2->LC = createNode(3);
    root2->RC = createNode(8);
    root2->LC->LC = createNode(1);
    root2->RC->LC = createNode(7);
    root2->RC->RC = createNode(9);
    
    // Tree 4: Different tree
    BST* root3 = createNode(10);
    root3->LC = createNode(5);
    root3->RC = createNode(15);
    
    printf("=== LEVEL 1: WARMUP PROBLEMS ===\n");
    printf("Count nodes: %d (should be 6)\n", countNodes(root));
    printf("Sum tree: %d (should be 33)\n", sumTree(root));
    printf("Find min: %d (should be 1)\n", findMin(root));
    printf("Find max: %d (should be 9)\n", findMax(root));
    printf("Contains 7: %d (should be 1)\n", contains(root, 7));
    printf("Contains 99: %d (should be 0)\n", contains(root, 99));
    
    printf("\n=== LEVEL 2: INTERMEDIATE PROBLEMS ===\n");
    printf("Count at level 0: %d (should be 1)\n", countAtLevel(root, 0, 0));
    printf("Count at level 1: %d (should be 2)\n", countAtLevel(root, 1, 0));
    printf("Count at level 2: %d (should be 3)\n", countAtLevel(root, 2, 0));
    printf("Is single node (root): %d (should be 0)\n", isSingleNode(root));
    printf("Is single node (42): %d (should be 1)\n", isSingleNode(singleNode));
    printf("Count internal nodes: %d (should be 3)\n", countInternalNodes(root));
    printf("Is 7 at level 2: %d (should be 1)\n", isAtLevel(root, 7, 2, 0));
    printf("Is 5 at level 2: %d (should be 0)\n", isAtLevel(root, 5, 2, 0));
    printf("Count one child: %d (should be 1 - node 3)\n", countOneChild(root));
    
    printf("\n=== LEVEL 3: EXAM-LEVEL PROBLEMS ===\n");
    printf("Are root and root2 identical: %d (should be 1)\n", areIdentical(root, root2));
    printf("Are root and root3 identical: %d (should be 0)\n", areIdentical(root, root3));
    printf("Depth of 7: %d (should be 2)\n", findDepth(root, 7, 0));
    printf("Depth of 5: %d (should be 0)\n", findDepth(root, 5, 0));
    printf("Depth of 99: %d (should be -1)\n", findDepth(root, 99, 0));
    printf("Is tree balanced: %d (should be 1)\n", isBalanced(root));
    printf("Has path sum to 9: %d (should be 1, path: 5->3->1)\n", hasPathSum(root, 9, 0));
    printf("Has path sum to 22: %d (should be 1, path: 5->8->9)\n", hasPathSum(root, 22, 0));
    printf("Has path sum to 100: %d (should be 0)\n", hasPathSum(root, 100, 0));
    printf("Count two children: %d (should be 2 - nodes 5 and 8)\n", countTwoChildren(root));
    
    printf("\n=== BONUS PROBLEMS ===\n");
    printf("Second min: %d (should be 3)\n", findSecondMin(root));
    printf("Count greater than 5: %d (should be 3 - nodes 8,7,9)\n", countGreaterThan(root, 5));
    printf("Count greater than 10: %d (should be 0)\n", countGreaterThan(root, 10));
    printf("Level with Max Sum: %d (should be 2)\n", levelWithMaxSum(root));

    printf("\n=== HELPER FUNCTIONS ===\n");
    printf("Height: %d (should be 2)\n", getHeight(root));
    printf("Count leaves: %d (should be 3 - nodes 1,7,9)\n", countLeaves(root));
    
    printf("\n=== ALL TESTS COMPLETE! ===\n");
    
    return 0;
}
