#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Node definition for Adjacency List
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Graph structure
Node* adjList[MAX];
int visited[MAX] = {0};

// Helper to add edge (Already written for you)
void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

int countInfectedComputers(int startNode) {
    int count = 0;
    
    // Queue implementation using simple array
    int queue[MAX];
    int front = 0, rear = 0;
    
    // Step 1: Enqueue startNode and mark visited
    queue[rear++] = startNode;
    visited[startNode] = 1;
    count++;
    
    while(front < rear) {
        // Step 2: Dequeue current node
        int current = queue[front++];
        
        
        Node* trav;
        for(trav = adjList[current]; trav != NULL; trav = trav->next){
            if (visited[trav->dest] == 0 ){
                visited[trav->dest] = 1;
                queue[rear++] = trav->dest;
                count++;
            }
        }
        
        // TODO: Traverse neighbors of 'current'
        // Pointer to traverse list: Node* temp = adjList[current];
        
        // YOUR CODE HERE
        // While temp is not NULL:
        //    If temp->dest is not visited:
        //       Mark temp->dest as visited
        //       Enqueue temp->dest
        //       Increment count
        //       Move to next neighbor (temp = temp->next)
    }
    
    return count;
}

int main() {
    // Creating the graph
    // 0 -> 1
    // 0 -> 2
    // 1 -> 3
    // 2 -> 4 (Node 4 is connected to 2)
    // Node 5 is isolated (not in list)
    
    for(int i=0; i<MAX; i++) adjList[i] = NULL; // Init
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    int total = countInfectedComputers(0);
    printf("Total computers infected: %d", total);
    
    return 0;
}
