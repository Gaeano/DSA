#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5
#define infi -99999

typedef struct{
    int maxNumVertices;
    int numVertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];
}AdjMatrix;


void initMatrix(AdjMatrix* C){
    C->maxNumVertices  = MAX_VERTICES;
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++){
        for (j = 0; j < MAX_VERTICES; j++){
            C->matrix[i][j] = infi;
        }
    }
}

void insertToMatrix(AdjMatrix* C, int data, int src, int dest){

    int i;

    C->matrix[src][dest] = data;
    printf("Inserting data: %d with tail: %d head: %d\n", data, src, dest);
    C->numVertices++;
}




void dijkstrasAlgo(AdjMatrix* C, int srcNode){
    int D[MAX_VERTICES];
    int i, j;
    int DifferenceV_and_S[MAX_VERTICES];
    int differenceCount = 0;
    int w;
    int Vertices[MAX_VERTICES]; //this array if for Vertices that have not been visited
    int S[MAX_VERTICES]; //array for used vertices

    
    //populate D first with the row of the srcNode
    for (i = 0; i < MAX_VERTICES; i++){
            D[i] = C->matrix[srcNode][j];
            Vertices[i] = i;
    }
    //loop through the S and Vertices and insert to DifferenceV_and_S 
    for (i = 0; i < MAX_VERTICES; i++){
        for (j = 0; j < MAX_VERTICES; j++){
            if (Vertices[i] != S[j]){
                //broken fix this
                DifferenceV_and_S[i] = Vertices[i];
                break;
            }
        }
    }

    while (differenceCount < 0){




    }
    


    //assign the minimum to the D with the vertices index;
    D[Vertices[i]] =  (D[Vertices[i]] < D[w] + C->matrix[w][Vertices[i]]) ? D[Vertices[i]] : D[w] + C->matrix[w][Vertices[i]];

    

}







int main (){
    AdjMatrix C;

    printf("--Initializing Matrix--\n");
    initMatrix(&C);

    printf("\n--Inserting Data--\n\n");

    insertToMatrix(&C, 12, 0, 1);
    insertToMatrix(&C, 7, 0, 2);
    insertToMatrix(&C, 10, 1, 4);
    insertToMatrix(&C, 2, 2, 1);
    insertToMatrix(&C, 9, 2, 3);
    insertToMatrix(&C, 4, 3, 4);
    insertToMatrix(&C, 5, 3, 5);
    insertToMatrix(&C, 3, 4, 5);





}