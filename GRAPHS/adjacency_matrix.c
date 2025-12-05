#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5
#define infi -99999
typedef struct{
    char vertex;
    int weight;
    int matrix[5][5];
}AdjMatrix;



//this representation is for the connections / edges

void initializeMatrix(AdjMatrix* m){
    int i, j;

    for (i = 0; i < MAX_VERTICES; i++){
        for(j = 0; j < MAX_VERTICES;j++){
            m->matrix[i][j] = infi;
            //initialize all the inifinity
        }
    }
}


void insertToMatrix(AdjMatrix *m, int src, int dest, int weight){

    m->matrix[src][dest] = weight;

}


void diplayMatrix(AdjMatrix * m){

    int i, j;
    for(i = 0;i < MAX_VERTICES; i++){
        printf("%d | ", i);
        for(j = 0; j < MAX_VERTICES; j++){
            if (m->matrix[i][j] == infi){
                printf("∞ ");
            } else {
                printf("%d ", m->matrix[i][j]);
            }
            
        }
        printf("\n");
    }
}

int main (){
    AdjMatrix graph;
    
    // Initialize the matrix with infinity values
    initializeMatrix(&graph);
    
    // Add edges to the graph
    // Format: insertToMatrix(&graph, source, destination, weight)
    
    // Vertex 0 connections
    insertToMatrix(&graph, 0, 1, 10);  // 0 -> 1 with weight 10
    insertToMatrix(&graph, 0, 3, 5);   // 0 -> 3 with weight 5
    
    // Vertex 1 connections
    insertToMatrix(&graph, 1, 2, 1);   // 1 -> 2 with weight 1
    insertToMatrix(&graph, 1, 3, 2);   // 1 -> 3 with weight 2
    
    // Vertex 2 connections
    insertToMatrix(&graph, 2, 4, 4);   // 2 -> 4 with weight 4
    
    // Vertex 3 connections
    insertToMatrix(&graph, 3, 1, 3);   // 3 -> 1 with weight 3
    insertToMatrix(&graph, 3, 2, 9);   // 3 -> 2 with weight 9
    insertToMatrix(&graph, 3, 4, 2);   // 3 -> 4 with weight 2
    
    // Vertex 4 connections
    insertToMatrix(&graph, 4, 0, 7);   // 4 -> 0 with weight 7
    insertToMatrix(&graph, 4, 2, 6);   // 4 -> 2 with weight 6
    
    // Display the adjacency matrix
    printf("Adjacency Matrix (Weighted Directed Graph):\n");
    printf("(infinity represented as %d)\n\n", infi);
    diplayMatrix(&graph);
    
    return 0;

}