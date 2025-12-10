#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;



typedef struct{
    int data[MAX_VERTICES];
    int top;
}Stack;


void initStack(Stack* s){
    s->top = -1;
}

int isEmpty(Stack* s){
    return s->top == -1;
}

int isFull(Stack * s){
    return s->top == MAX_VERTICES-1;
}

void push(Stack* s, int data){
    if (!isFull(s)){
        s->data[s->top+1] = data;
        s->top++;
    }
}


int pop(Stack* s){
    if (!isEmpty(s)){
        int data = s->data[s->top];
        s->top--;
        return data;
    }
}


void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adjMatrix[i][j] = 0;
}

void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
}

// TODO: Implement these functions
bool hasCycleDFS(Graph* g, int v, bool visited[], bool recStack[]) {
    // Your code here
    visited[v] = 1;
    recStack[v] = 1;
    
    
    for(int i = 0 ; i < g->numVertices; i++){
        if (g->adjMatrix[v][i] == 1){
            if (!visited[i]){
                if(hasCycleDFS(g, i, visited, recStack)){
                    return 1;
                }
            } else if(recStack[i]){
                return 1;
            }
        }
    }
    
    visited[v] = 0;
    recStack[v] = 0;
    return 0;
}

bool hasCycle(Graph* g) {
    // Your code here
    bool recStack[g->numVertices];
    bool visited[g->numVertices];
    
    int found = 0;
    
    int i;
    
    for(i = 0; i < g->numVertices; i++){
        if(!visited[i]){
            if (hasCycleDFS(g, i, visited, recStack)){
                found = 1;
                break;
            }
        }
    }
    
    return found;
}

int main() {
    // Test case 1: Graph with cycle (0->1->2->0)
    Graph g1;
    initGraph(&g1, 3);
    addEdge(&g1, 0, 1);
    addEdge(&g1, 1, 2);
    addEdge(&g1, 2, 0);
    
    printf("Graph 1 has cycle: %s\n", hasCycle(&g1) ? "Yes" : "No");
    
    // Test case 2: Graph without cycle (0->1->2)
    Graph g2;
    initGraph(&g2, 3);
    addEdge(&g2, 0, 1);
    addEdge(&g2, 1, 2);
    
    printf("Graph 2 has cycle: %s\n", hasCycle(&g2) ? "Yes" : "No");
    
    return 0;
}