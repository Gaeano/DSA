#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define ROOT_NODE -1
#define INVALID_NODE -2

// Type definition for a node index
typedef int Node;

// 1. Linked List Node Definition
// Each node in the linked list represents a child of the parent (array index)
typedef struct ChildNode {
    Node childIndex;
    struct ChildNode *next;
} ChildNode;

// 2. Tree Structure Definition
// The Tree holds the root index and an array of head pointers for the children lists.
typedef struct {
    Node rootIndex;
    // Array of heads of linked lists.
    // children[i] points to the first child of node i.
    ChildNode* children[MAX_NODES];
} Tree;


/**
 * @brief Initializes the Tree structure.
 * Sets the root index to INVALID_NODE and all children list heads to NULL.
 * @param T Pointer to the Tree structure to initialize.
 */
void initializeTree(Tree *T) {

    T->rootIndex = INVALID_NODE;
    
    int i;
    for (i = 0; i < MAX_NODES; i++){
        T->children[i] = NULL;
    }
    // TODO


}

/**
 * @brief Designates a node as the root.
 * @param T Pointer to the Tree structure.
 * @param r The index of the node to be set as root.
 */
void makeRoot(Tree *T, Node r) {
    T->rootIndex = r;

    // TODO

}

/**
 * @brief Adds a new child node to the parent's linked list.
 * @param T Pointer to the Tree structure.
 * @param parent_index The index of the parent node (array index).
 * @param child_index The index of the child node (value in the linked list).
 */
 
ChildNode* createNode(Node data){
    ChildNode* newNode = malloc (sizeof(ChildNode));
    
    newNode->childIndex = data;
    newNode->next = NULL;
    
    return newNode;
}
void addChild(Tree *T, Node parent_index, Node child_index) {
    
    ChildNode* temp;
    
    ChildNode* newNode = createNode(child_index);
    
    
    if (T->children[parent_index] == NULL){
        T->children[parent_index] = newNode;
    } else {
       newNode->next = T->children[parent_index]; //head
        T->children[parent_index] = newNode;
    
    }
    

    // TODO


}


/**
 * @brief Returns the parent of a given node.
 * Requires searching through all parent lists to find the node.
 * @param n The node index (child).
 * @param T Pointer to the Tree structure.
 * @return The parent node index, ROOT_NODE if n is the root, or INVALID_NODE if n is invalid/uninitialized.
 */
Node parent(Node n, const Tree *T) {
        
    if (n == T->rootIndex){
        return ROOT_NODE;
    }
    int i;
    ChildNode* trav;
    int found = 0;
    Node parent = INVALID_NODE;
   
    for (i = 0; i < MAX_NODES && found == 0; i++){
        for (trav = T->children[i]; trav != NULL && found == 0; trav = trav->next){
            if (trav->childIndex == n){
                found = 1;
                parent = i;
            }
        }
    }
    
    return parent;
    
    
    // TODO


}

/**
 * @brief Returns the leftmost leaf element (the leaf node with the smallest index) in the tree.
 * @param T Pointer to the Tree structure.
 * @return The index of the leftmost leaf, or INVALID_NODE if the tree is empty or has no leaves.
 */
Node left(const Tree *T) {

    ChildNode* trav;
    Node smallest;
    
    int i;
    smallest =INVALID_NODE;
    if (T->rootIndex == INVALID_NODE){
        return INVALID_NODE;
    }
    
    
    for (i = 0; i < MAX_NODES; i++){
        if (T->children[i] == NULL){
            
            if (i == T->rootIndex){
                if (smallest == INVALID_NODE || i < smallest){
                    smallest = i;
                }
            }  else {
                int found= 0;
                int j;
                for (j = 0; j < MAX_NODES && found == 0; j++){
                    for (trav = T->children[j]; trav != NULL; trav = trav->next){
                        if (trav->childIndex == i){
                            found = 1;
                            
                            if (smallest == INVALID_NODE || i < smallest){
                                smallest = i;
                            }
                            
                            
                        }
                    }
                }
            }
        }
        
    }
    
    return smallest;
    // TODO


}

/**
 * @brief Returns the rightmost leaf element (the leaf node with the largest index) in the tree.
 * @param T Pointer to the Tree structure.
 * @return The index of the rightmost leaf, or INVALID_NODE if the tree is empty or has no leaves.
 */
Node right(const Tree *T) {


    
    ChildNode* trav;
    Node largest;
    
    int i;
    largest =INVALID_NODE;
    if (T->rootIndex == INVALID_NODE){
        return INVALID_NODE;
    }
    
    
    for (i = 0; i < MAX_NODES; i++){
        if (T->children[i]== NULL){
            
            if (i == T->rootIndex){
                if (largest == INVALID_NODE || i < largest){
                    largest = i;
                }
            } else {
                int found= 0;
                int j;
                for (j = 0; j < MAX_NODES && found == 0; j++){
                    for (trav = T->children[j]; trav != NULL; trav = trav->next){
                        if (trav->childIndex == i){
                            found = 1;
                            
                            if (largest == INVALID_NODE || i > largest){
                                largest = i;
                            }
                            
                            
                        }
                    }
                }
            }
        } 
        
    }
    
    return largest;
}

/**
 * @brief Frees the memory allocated for the children linked lists.
 * @param T Pointer to the Tree structure.
 */
void freeTree(Tree *T) {
    for (int i = 0; i < MAX_NODES; i++) {
        ChildNode *current = T->children[i];
        ChildNode *next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        T->children[i] = NULL; // Reset pointer to NULL after freeing
    }
    printf("\nTree memory cleaned up.\n");
}


// --- Demonstration and Utility ---

/**
 * @brief Prints the contents of the tree array representation.
 * @param T Pointer to the Tree structure.
 */
void printTree(const Tree *T) {
    printf("--- Tree Children List Representation ---\n");
    printf("Root Index: %d\n", T->rootIndex);
    printf("Parent Index | Children List\n");
    printf("-------------|---------------\n");

    for (int i = 0; i < MAX_NODES; i++) {
        printf("%12d | ", i);
        ChildNode *current = T->children[i];
        if (current == NULL) {
            printf("(None)\n");
        } else {
            while (current != NULL) {
                printf("%d -> ", current->childIndex);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
    printf("-----------------------------------------\n");
}


int main() {
    Tree myTree;
    initializeTree(&myTree);

    // --- Building a Sample Tree ---
    // Structure:
    //      0 (Root)
    //     /  \
    //    1    2
    //   / \   |
    //  3   4  5
    //        / \
    //       8   9

    makeRoot(&myTree, 0);       // 0 is the root

    // Add children to 0
    addChild(&myTree, 0, 1);
    addChild(&myTree, 0, 2);

    // Add children to 1
    addChild(&myTree, 1, 3);
    addChild(&myTree, 1, 4);

    // Add children to 2
    addChild(&myTree, 2, 5);

    // Add children to 5
    addChild(&myTree, 5, 8);
    addChild(&myTree, 5, 9);
    // Node indices 3, 4, 8, 9 are the leaves.
    // Leftmost leaf (smallest index) is 3.
    // Rightmost leaf (largest index) is 9.

    printTree(&myTree);

    // --- Testing Operations ---
    printf("\n--- Testing ADT Operations ---\n");

    // 1. Test parent()
    Node node_to_check = 5;
    Node p = parent(node_to_check, &myTree);
    if (p == ROOT_NODE) {
        printf("Parent of Node %d: (It is the Root)\n", node_to_check);
    } else if (p == INVALID_NODE) {
        printf("Parent of Node %d: (Node is Invalid/Not Found)\n", node_to_check);
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p); // Expected: 2
    }

    node_to_check = 0; // The Root
    p = parent(node_to_check, &myTree);
    if (p == ROOT_NODE) {
        printf("Parent of Node %d: (It is the Root)\n", node_to_check); // Expected: ROOT_NODE
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p);
    }

    node_to_check = 7; // Not in tree
    p = parent(node_to_check, &myTree);
    if (p == INVALID_NODE) {
        printf("Parent of Node %d: (Node is Invalid/Not Found)\n", node_to_check); // Expected: INVALID_NODE
    } else {
        printf("Parent of Node %d: Node %d\n", node_to_check, p);
    }


    // 2. Test left() - leftmost leaf (smallest index leaf)
    Node l = left(&myTree);
    if (l != INVALID_NODE) {
        printf("Leftmost Leaf: Node %d\n", l); // Expected: 3
    } else {
        printf("Leftmost Leaf: Tree is empty or has no leaves.\n");
    }

    // 3. Test right() - rightmost leaf (largest index leaf)
    Node r = right(&myTree);
    if (r != INVALID_NODE) {
        printf("Rightmost Leaf: Node %d\n", r); // Expected: 9
    } else {
        printf("Rightmost Leaf: Tree is empty or has no leaves.\n");
    }

    // Clean up memory
    freeTree(&myTree);

    return 0;
}