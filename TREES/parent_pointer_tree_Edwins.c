#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define ROOT_NODE -1
#define INVALID_NODE -2

// Type definition for a node index
typedef int Node;

// Type definition for the Tree array
// T[i] stores the index of the parent of node i.
typedef int Tree[MAX_NODES];

/**
 * @brief Initializes the tree array.
 * Sets all parent pointers to INVALID_NODE, indicating the tree is empty.
 * @param T The Tree array to initialize.
 */
void initialize(Tree T) {

    int i;
    for (i = 0; i < MAX_NODES; i++){
         T[i] = INVALID_NODE;
    }
    // TODO


}

/**
 * @brief Designates a node as the root.
 * @param T The Tree array.
 * @param r The index of the node to be set as root.
 */
void makeRoot(Tree T, Node r) {

    T[r] = ROOT_NODE;
    // TODO


}

/**
 * @brief Establishes a parent-child relationship.
 * @param T The Tree array.
 * @param child The index of the child node.
 * @param parent The index of the parent node.
 */
void setParent(Tree T, Node child, Node parent) {

    T[child] = parent;
    // TODO


}

/**
 * @brief Returns the parent of a given node.
 * @param n The node index.
 * @param T The Tree array.
 * @return The parent node index, ROOT_NODE if n is the root, or INVALID_NODE if n is invalid/uninitialized.
 */
Node parent(Node n, Tree T) {

    if (T[n] == ROOT_NODE){
        return ROOT_NODE;
    }
    
    if (T[n] != INVALID_NODE){
        return T[n]; 
    } else {
        return INVALID_NODE;
    }
    // TODO


}

/**
 * @brief Returns the leftmost leaf element (the leaf node with the smallest index) in the tree.
 * @param T The Tree array.
 * @return The index of the leftmost leaf, or INVALID_NODE if the tree is empty or has no leaves.
 */
Node left(Tree T) {
    
    int smallest = INVALID_NODE;
    
    int i;
    int found = 0;
    for (i = 0; i < MAX_NODES; i++){
        if (T[i] != INVALID_NODE){ //has parent //get the index of the child that has parent
            found = 0;
            int j;
            
            for (j = 0; j < MAX_NODES && found == 0; j++){
                //traverse through the list and find if hte child index is a parent
                if (T[j] == i){
                    found = 1; //child is a parent (meaning it is not a leaf node)
                }
            }
            if (found == 0){
                if (smallest == INVALID_NODE || i < smallest){
                    smallest = i;
                }
            }
        }
    }

    // TODO

    return smallest;
}

/**
 * @brief Returns the rightmost leaf element (the leaf node with the largest index) in the tree.
 * @param T The Tree array.
 * @return The index of the rightmost leaf, or INVALID_NODE if the tree is empty or has no leaves.
 */
Node right(Tree T) {

    int largest = INVALID_NODE;
    
    int i;
    int found = 0;
    for (i = 0; i < MAX_NODES; i++){
        if (T[i] != INVALID_NODE){ //has parent //get the index of the child that has parent
            found = 0;
            int j;
            
            for (j = 0; j < MAX_NODES && found == 0; j++){
                //traverse through the list and find if hte child index is a parent
                if (T[j] == i){
                    found = 1; //child is a parent (meaning it is not a leaf node)
                }
            }
            if (found == 0){
                if (largest == INVALID_NODE || i > largest){
                    largest = i;
                }
            }
        }
    }

    // TODO

    return largest;


}

// --- Demonstration and Utility ---

/**
 * @brief Prints the contents of the tree array for inspection.
 * @param T The Tree array.
 */
void printTree(Tree T) {
    printf("--- Tree Array Representation ---\n");
    printf("Index (Child) | Parent\n");
    printf("--------------|-------\n");
    for (int i = 0; i < MAX_NODES; i++) {
        if (T[i] == ROOT_NODE) {
            printf("%13d | ROOT\n", i);
        } else if (T[i] == INVALID_NODE) {
            printf("%13d | (Uninitialized)\n", i);
        } else {
            printf("%13d | %d\n", i, T[i]);
        }
    }
    printf("---------------------------------\n");
}

int main() {
    Tree myTree;
    initialize(myTree);

    // --- Building a Sample Tree ---
    // Structure:
    //      0 (Root)
    //     /  \
    //    1    2
    //   / \   |
    //  3   4  5
    //        / \
    //       8   9
    // Leaves: 3, 4, 8, 9
    // Leftmost Leaf (smallest index): 3
    // Rightmost Leaf (largest index): 9

    makeRoot(myTree, 0);       // 0 is the root
    setParent(myTree, 1, 0);   // 1's parent is 0
    setParent(myTree, 2, 0);   // 2's parent is 0
    setParent(myTree, 3, 1);   // 3's parent is 1
    setParent(myTree, 4, 1);   // 4's parent is 1
    setParent(myTree, 5, 2);   // 5's parent is 2
    setParent(myTree, 8, 5);   // 8's parent is 5
    setParent(myTree, 9, 5);   // 9's parent is 5
    // Nodes 6 and 7 remain uninitialized (-2)

    printTree(myTree);

    // --- Testing Operations ---
    printf("\n--- Testing ADT Operations ---\n");

    // 1. Test parent()
    Node node_to_check = 5;
    Node p = parent(node_to_check, myTree);
    if (p == ROOT_NODE) {
        printf("Parent of Node %d: (It is the Root)\n", node_to_check);
    } else if (p == INVALID_NODE) {
        printf("Parent of Node %d: (Node is Invalid/Uninitialized)\n", node_to_check);
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p); // Expected: 2
    }

    node_to_check = 0; // The Root
    p = parent(node_to_check, myTree);
    if (p == ROOT_NODE) {
        printf("Parent of Node %d: (It is the Root)\n", node_to_check); // Expected: ROOT_NODE
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p);
    }

    // 2. Test left() - leftmost leaf
    Node l = left(myTree);
    if (l != INVALID_NODE) {
        printf("Leftmost Leaf: Node %d\n", l); // Expected: 3
    } else {
        printf("Leftmost Leaf: Tree is empty or has no leaves.\n");
    }

    // 3. Test right() - rightmost leaf
    Node r = right(myTree);
    if (r != INVALID_NODE) {
        printf("Rightmost Leaf: Node %d\n", r); // Expected: 9
    } else {
        printf("Rightmost Leaf: Tree is empty or has no leaves.\n");
    }

    return 0;
}