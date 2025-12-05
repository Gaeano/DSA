#include <stdio.h>
#include <stdlib.h>

#define MAX 10

//adjacency list
typedef struct vertex{
    char data;
    struct vertex* tail;
}Vertex;


typedef struct{
    Vertex* list[MAX];
    int count;
}Graph;



void initGraph(Graph* g){
    int i;
    for (i = 0; i < MAX; i++){
        g->list[i] = NULL;
    }
    g->count = 0;
}


Vertex* createVertex(char data){
    Vertex* newVertex = malloc(sizeof(Vertex));
    newVertex->data = data;
    newVertex->tail = NULL;

    return newVertex;
}

void insertToGraph(Graph* g, char data, int src){

        if (g->count == MAX){
            return;
        }

        Vertex * newVertex = createVertex(data);

        if (g->list[src] == NULL){
            g->list[src] = newVertex;
            g->count++;

        } else {
            //insert head
            newVertex->tail = g->list[src];
            g->list[src] = newVertex;
        }

}

void displayList(Graph* g){
    int i;

    for (i = 0; i < g->count; i++){
        printf("%d: -> ",i);
        Vertex* trav;
        for (trav = g->list[i]; trav != NULL; trav = trav->tail){
        char data = trav->data;
            printf("%c -> ",data);
        }
        printf("\n");
        
    }
}







int main (){
    Graph g;

    initGraph(&g);
    insertToGraph(&g, 'A', 0); // Vertex A is at index 0
    insertToGraph(&g, 'B', 0); // Edge from A to B
    insertToGraph(&g, 'C', 0); // Edge from A to C

    // Assume Index 1 is Source Vertex 'B'
    // Source: 1 ('B'), Connections: 'D', 'A'
    insertToGraph(&g, 'B', 1); // Vertex B is at index 1
    insertToGraph(&g, 'D', 1); // Edge from B to D
    insertToGraph(&g, 'A', 1); // Edge from B to A

    // Assume Index 2 is Source Vertex 'C'
    // Source: 2 ('C'), Connection: 'D'
    insertToGraph(&g, 'C', 2); // Vertex C is at index 2
    insertToGraph(&g, 'D', 2); // Edge from C to D

    displayList(&g);
    int i;
    for (i = 0; i < g.count; i++){

        while(g.list[i] != NULL){
            Vertex* temp = g.list[i];
            g.list[i] = temp->tail;
            free(temp);
        }
    }

    return 0;
}