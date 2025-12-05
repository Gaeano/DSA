#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5
#define infi -99999

typedef struct{
    char vertex;
    int weight;
    int matrix[5][5];
}AdjMatrix;

// Initialize matrix
void initializeMatrix(AdjMatrix* m){
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++){
        for(j = 0; j < MAX_VERTICES; j++){
            m->matrix[i][j] = infi;
        }
    }
}

// Insert edge
void insertToMatrix(AdjMatrix *m, int src, int dest, int weight){
    m->matrix[src][dest] = weight;
}

// Display matrix
void displayMatrix(AdjMatrix * m){
    int i, j;
    for(i = 0; i < MAX_VERTICES; i++){
        for(j = 0; j < MAX_VERTICES; j++){
            if(m->matrix[i][j] == infi){
                printf("inf ");
            } else {
                printf("%3d ", m->matrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Exercise 1: Check if edge exists
int hasEdge(AdjMatrix *m, int src, int dest){
    // TODO: Return 1 if edge exists, 0 otherwise
    if (m->matrix[src][dest] != infi){
        return 1;
    } else {
        return 0;
    }
}

// Exercise 2: Count outgoing edges from a vertex
int countOutgoingEdges(AdjMatrix *m, int vertex){
    // TODO: Count how many edges go OUT from this vertex
    int i, count = 0;
    for (i = 0; i < MAX_VERTICES; i++){
        if (m->matrix[vertex][i] != infi){
            count++;
        }
    }
    return count;
}

// Exercise 3: Count incoming edges to a vertex
int countIncomingEdges(AdjMatrix *m, int vertex){
    // TODO: Count how many edges come INTO this vertex
    int i, count = 0;
    for (i = 0; i < MAX_VERTICES; i++){
        if (m->matrix[i][vertex] != infi){
            count++;
        }
    }
    return count;
}

// Exercise 4: Find maximum weight edge
int findMaxWeight(AdjMatrix *m){
    // TODO: Find the maximum weight among all edges
    int i, j, max = m->matrix[0][0];
    for (i = 0; i < MAX_VERTICES; i++){
        for (j = 0; j < MAX_VERTICES; j++){
            if (max < m->matrix[i][j]){
                max = m->matrix[i][j];
            }
        }
    }
    return max;
}

// Exercise 5: Delete an edge
void deleteEdge(AdjMatrix *m, int src, int dest){
    // TODO: Remove the edge by setting it to infi
    m->matrix[src][dest] = infi;
}

// Exercise 6: Check if vertex is isolated
int isIsolated(AdjMatrix *m, int vertex){
    // TODO: Return 1 if vertex has no incoming or outgoing edges
    int i, hasIncoming = 0, hasOutgoing = 0;
    for (i = 0 ; i < MAX_VERTICES; i++){
        if (m->matrix[i][vertex] != infi){
            hasIncoming = 1;
        }
    }

    for (i = 0 ; i < MAX_VERTICES; i++){
        if (m->matrix[vertex][i] != infi){
            hasOutgoing = 1;
        }
    }

    return (hasOutgoing == 1 || hasIncoming == 1) ? 0 : 1;
}

// Exercise 7: Print all neighbors of a vertex
void printNeighbors(AdjMatrix *m, int vertex){
    // TODO: Print all vertices that this vertex connects to
    int i;
    //going to vertex
    // for (i = 0; i < MAX_VERTICES; i++){
    //     int data = m->matrix[i][vertex];
    //     printf("%d ", data);
    // }

    //from thevertex
    for (i = 0; i < MAX_VERTICES; i++){
        if (m->matrix[vertex][i] != infi){
            printf("%d ", i);
        }
    }
}

// Exercise 8: Count total edges in graph
int countTotalEdges(AdjMatrix *m){
    // TODO: Count total number of edges in the entire graph
    int i, j, count = 0;

    for (i = 0; i < MAX_VERTICES; i++){
        for (j = 0; j < MAX_VERTICES; j++){
            if (m->matrix[i][j] != infi){
                count++;
            }
        }
    }
    return count;
}

// Exercise 9: Check if graph is complete
int isComplete(AdjMatrix *m){
    // TODO: Return 1 if every vertex connects to every other vertex
    int i, j, count = 0;

    for (i = 0; i < MAX_VERTICES; i++){
        for (j = 0; j < MAX_VERTICES; j++){
            if (m->matrix[i][j] == infi){
                return 0;
            }
        }
    }
    return 1;
}

// Exercise 10: Find shortest edge from a vertex
int findShortestEdge(AdjMatrix *m, int vertex){
    // TODO: Find minimum weight edge from this vertex
    int i, min = 10000;
    for (i = 1 ; i < MAX_VERTICES; i++){
        if ( m->matrix[vertex][i] < min && i != vertex){
            min =  m->matrix[vertex][i];
        }
       
    }

    return min;
}

// Exercise 11: Update edge weight
void updateEdge(AdjMatrix *m, int src, int dest, int newWeight){
    // TODO: Update the weight of existing edge
    m->matrix[src][dest] = newWeight;
}

// Exercise 12: Check if path A->B->C exists
int hasPathABC(AdjMatrix *m, int a, int b, int c){
    // TODO: Check if edges A->B and B->C both exist
    int itExists1 = 0, itExists2 = 0;

    if (m->matrix[a][b] != infi){
        itExists1 = 1;
    } 
    if (m->matrix[b][c] != infi){
        itExists2 = 1;
    } 

    return (itExists1 == 1 && itExists2 == 1) ? 1 : 0;
}

// Exercise 13: Transpose graph
void transposeGraph(AdjMatrix *m, AdjMatrix *transposed){
    // TODO: Create transpose (reverse all edges)
}

// Exercise 14: Count self loops
int countSelfLoops(AdjMatrix *m){
    // TODO: Count vertices that have edges to themselves
}

// Exercise 15: Find vertex with most connections
int findMostConnected(AdjMatrix *m){
    // TODO: Find which vertex has the most outgoing edges
}


int main() {
    AdjMatrix graph;
    
    // Initialize the matrix
    initializeMatrix(&graph);
    
    // Add edges
    insertToMatrix(&graph, 0, 1, 10);
    insertToMatrix(&graph, 0, 3, 5);
    insertToMatrix(&graph, 1, 2, 1);
    insertToMatrix(&graph, 1, 3, 2);
    insertToMatrix(&graph, 2, 4, 4);
    insertToMatrix(&graph, 3, 1, 3);
    insertToMatrix(&graph, 3, 2, 9);
    insertToMatrix(&graph, 3, 4, 2);
    insertToMatrix(&graph, 4, 0, 7);
    insertToMatrix(&graph, 4, 2, 6);
    
    // Display the matrix
    printf("Adjacency Matrix:\n");
    displayMatrix(&graph);
    printf("\n");
    /* Expected:
    inf  10 inf   5 inf 
    inf inf   1   2 inf 
    inf inf inf inf   4 
    inf   3   9 inf   2 
      7 inf   6 inf inf 
    */
    
    // Test Exercise 1
    printf("Exercise 1 - Has edge 0->1: %d\n", hasEdge(&graph, 0, 1));      // Expected: 1
    printf("Exercise 1 - Has edge 0->2: %d\n\n", hasEdge(&graph, 0, 2));    // Expected: 0
    
    // Test Exercise 2
    printf("Exercise 2 - Outgoing edges from vertex 0: %d\n", countOutgoingEdges(&graph, 0));    // Expected: 2
    printf("Exercise 2 - Outgoing edges from vertex 3: %d\n\n", countOutgoingEdges(&graph, 3));  // Expected: 3
    
    // Test Exercise 3
    printf("Exercise 3 - Incoming edges to vertex 1: %d\n", countIncomingEdges(&graph, 1));    // Expected: 2
    printf("Exercise 3 - Incoming edges to vertex 2: %d\n\n", countIncomingEdges(&graph, 2));  // Expected: 3
    
    // Test Exercise 4
    printf("Exercise 4 - Maximum weight: %d\n\n", findMaxWeight(&graph));    // Expected: 10
    
    // Test Exercise 5
    printf("Exercise 5 - Deleting edge 0->1\n");
    deleteEdge(&graph, 0, 1);
    displayMatrix(&graph);
    /* Expected:
    inf inf inf   5 inf 
    inf inf   1   2 inf 
    inf inf inf inf   4 
    inf   3   9 inf   2 
      7 inf   6 inf inf 
    */
    insertToMatrix(&graph, 0, 1, 10); // Restore for other tests
    printf("\n");
    
    // Test Exercise 6
    printf("Exercise 6 - Is vertex 0 isolated: %d\n", isIsolated(&graph, 0));    // Expected: 0
    printf("Exercise 6 - Is vertex 2 isolated: %d\n\n", isIsolated(&graph, 2));  // Expected: 0
    
    // Test Exercise 7
    printf("Exercise 7 - Neighbors of vertex 3: ");
    printNeighbors(&graph, 3);    // Expected: 1 2 4
    printf("\n");
    
    // Test Exercise 8
    printf("Exercise 8 - Total edges in graph: %d\n\n", countTotalEdges(&graph));    // Expected: 10
    
    // Test Exercise 9
    printf("Exercise 9 - Is graph complete: %d\n\n", isComplete(&graph));    // Expected: 0
    
    // Test Exercise 10
    printf("Exercise 10 - Shortest edge from vertex 3: %d\n\n", findShortestEdge(&graph, 3));    // Expected: 2
    
    // Test Exercise 11
    printf("Exercise 11 - Updating edge 0->3 to weight 15\n");
    updateEdge(&graph, 0, 3, 15);
    displayMatrix(&graph);
    /* Expected:
    inf  10 inf  15 inf 
    inf inf   1   2 inf 
    inf inf inf inf   4 
    inf   3   9 inf   2 
      7 inf   6 inf inf 
    */
    printf("\n");
    
    // Test Exercise 12
    printf("Exercise 12 - Path 0->1->2 exists: %d\n", hasPathABC(&graph, 0, 1, 2));    // Expected: 1
    printf("Exercise 12 - Path 0->3->4 exists: %d\n\n", hasPathABC(&graph, 0, 3, 4));  // Expected: 1
    
    // Test Exercise 13
    AdjMatrix transposed;
    initializeMatrix(&transposed);
    transposeGraph(&graph, &transposed);
    printf("Exercise 13 - Transposed graph:\n");
    displayMatrix(&transposed);
    /* Expected (all edges reversed):
    inf inf inf inf   7 
     10 inf inf   3 inf 
    inf   1 inf   9   6 
     15   2 inf inf inf 
    inf inf   4   2 inf 
    */
    printf("\n");
    
    // Test Exercise 14
    printf("Exercise 14 - Self loops count: %d\n\n", countSelfLoops(&graph));    // Expected: 0
    
    // Test Exercise 15
    printf("Exercise 15 - Most connected vertex: %d\n", findMostConnected(&graph));    // Expected: 3
    
    return 0;
}