#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define a maximum length for the key
#define MAX_KEY_LEN 100

// 1. Structure Definition
typedef struct node {
   char *key;          // The string element used for comparison and storage
   struct node* LC;   // Left Child pointer
   struct node* RC;   // Right Child pointer
} Node, *BST;


/**
 * @brief Deletes a node with the given key from the BST.
 * @param root The current root of the BST.
 * @param key_data The string key to delete.
 * @return BST The new root of the BST after deletion.
 */
 
 BST findSuccessor(BST root){
     
     while (root->LC != NULL){
         root = root->LC;
     }
     
     return root;
 }
 
 
 //recursion
BST deleteNode(BST root, const char *key_data) {
    // TODO...
    if (root == NULL){
        return root;
    }
    
    if (strcmp(key_data, root->key) < 0){
        root->LC = deleteNode(root->LC, key_data);
    } else if (strcmp(key_data, root->key) > 0){
        root->RC = deleteNode(root->RC, key_data);
    } else {
        if (root->LC == NULL){
            BST temp = root->RC;
            free(root->key);
            free(root);
            return temp;
        } else if (root->RC == NULL){
            BST temp = root->LC;
            free(root->key);
            free(root);
            return temp;
        } else {
            BST successor = findSuccessor(root->RC);
            free(root->key);
            root->key = malloc (sizeof(strlen(successor->key) + 1));
            strcpy(root->key, successor->key);
            root->RC = deleteNode(root->RC, successor->key);
        }
    }
    return root;
}

//iterative
// BST deleteNode(BST root, const char *key_data) {
//     // TODO...
//     if (root == NULL){
//         return root;
//     }
//     BST* trav, *trav2, holder;
    
//     for (trav = &root; *trav != NULL && strcmp(key_data, (*trav)->key) != 0;){
//         trav = (strcmp(key_data, (*trav)->key) < 0) ? &(*trav)->LC : &(*trav)->RC;
//     }
    
//     if (*trav != NULL){
//         if ((*trav)->LC == NULL){
//             holder = *trav;
//             *trav = holder->RC;
//             free(holder->key);
//             free(holder);
//         } else if ((*trav)->RC == NULL){
//             holder = *trav;
//             *trav = holder->LC;
//             free(holder->key);
//             free(holder);
//         } else {
            
//             for (*trav2 = (*trav)->RC; (*trav2)->LC != NULL && strcmp(key_data, (*trav2)->key) != 0 ; trav2 = &(*trav2)->LC){
                
//             }
            
//             holder = *trav2;
//             *trav2 = holder->RC;
//             free((*trav)->key);
//             (*trav)->key = malloc (strlen(holder->key) + 1);
//             strcpy((*trav)->key, holder->key);
//             free(holder->key);
//             free(holder);
//         }
//     }
    
//     return root;
// }

BST createNode(const char* data){
    BST newNode = (BST) malloc (sizeof(Node));
    newNode->key = malloc (strlen(data) + 1);
    strcpy(newNode->key, data);
    newNode->LC = NULL;
    newNode->RC = NULL;
    
    return newNode;
}



//recursion
void insert(BST *tree, const char *key_data) {
    // TODO...
    if (*tree == NULL){
        *tree = createNode(key_data);
    }
    
    if (strcmp(key_data, (*tree)->key) < 0){
        insert(&(*tree)->LC, key_data);
    } else if (strcmp(key_data ,(*tree)->key) > 0){
        insert(&(*tree)->RC, key_data);
    }
}




void inorderTraversal(BST tree) {
    // TODO...
    
    if (tree == NULL){
        return;
    }
    
    inorderTraversal(tree->LC);
    printf("%s ", tree->key);
    inorderTraversal(tree->RC);
}

void preorderTraversal(BST tree) {
    // TODO...
    if (tree == NULL){
        return;
    }
    
    printf("%s ", tree->key);
    preorderTraversal(tree->LC);
    preorderTraversal(tree->RC);
    
}

void postorderTraversal(BST tree) {
    // TODO...
    if (tree == NULL){
        return;
    }
    
    postorderTraversal(tree->LC);
    postorderTraversal(tree->RC);
    printf("%s ", tree->key);

}

/**
 * @brief Frees all memory allocated for the BST nodes, including the string keys.
 * * @param tree The root of the tree to destroy.
 */
void destroyTree(BST tree) {
    if (tree != NULL) {
        destroyTree(tree->LC);
        destroyTree(tree->RC);

        if (tree->key != NULL) {
            free(tree->key);
        }

        free(tree);
    }
}

int main() {
    // 1. Create and initialize the tree
    BST myTree = NULL;

    printf("--- Building BST for Deletion Test ---\n");
    // Keys: Apple, Banana, Grape, Kiwi, Mango(ROOT), Orange, Pineapple
    insert(&myTree, "Mango");      // Root
    insert(&myTree, "Apple");      // Left of Mango
    insert(&myTree, "Pineapple");  // Right of Mango
    insert(&myTree, "Banana");     // Right of Apple
    insert(&myTree, "Grape");      // Left of Pineapple
    insert(&myTree, "Orange");     // Right of Grape
    insert(&myTree, "Kiwi");       // Left of Orange

    printf("\nInitial In-Order Traversal:\n   ");
    inorderTraversal(myTree);
    printf("\n");

    // --- Deletion Tests ---

    printf("\n--- Test 1: Delete Leaf Node (Kiwi) ---\n");
    // Kiwi is a leaf node (0 children)
    myTree = deleteNode(myTree, "Kiwi");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 2: Delete Node with 1 Child (Apple) ---\n");
    // Apple has 1 child (Banana)
    myTree = deleteNode(myTree, "Apple");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 3: Delete Node with 2 Children (Mango - the Root) ---\n");
    // Mango is replaced by its successor (Orange)
    myTree = deleteNode(myTree, "Mango");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 4: Delete Non-Existent Key (Zebra) ---\n");
    myTree = deleteNode(myTree, "Zebra");
    printf("No change expected: ");
    inorderTraversal(myTree);
    printf("\n");

    // 2. Clean up memory
    destroyTree(myTree);
    printf("\nTree destroyed and memory freed.\n");

    return 0;
}