#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// 1. CHANGED: 'data' to 'dest' (store the index, not the char)
typedef struct vertex{
    int dest; 
    struct vertex* tail;
} Vertex;

typedef struct{
    Vertex* list[MAX];
    int count;
} Graph;

typedef struct{
    int elem[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q){
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue *q){
    return ((q->rear + 1) % MAX) == q->front;
}

bool isFull(Queue* q){
    return ((q->rear + 2) % MAX) == q->front;
} 

void enqueue(Queue * q, int data){
    if (!isFull(q)){
        q->rear = (q->rear + 1) % MAX;
        q->elem[q->rear] = data;
    }
}

// 2. FIXED: Actually return the value!
int dequeue(Queue* q){
    int dataToReturn = -1; // Default error value
    if (!isEmpty(q)){
        if (q->rear == q->front){ // Logic for when only 1 item is left
            dataToReturn = q->elem[q->rear];
            q->rear = -1; // Resetting queue is one way to handle it
            q->front = 0;
        } else {
            dataToReturn = q->elem[q->front]; // Get data BEFORE moving front
            q->front = (q->front + 1 ) % MAX;
        }
    }
    return dataToReturn; // <--- THIS WAS MISSING
}

void initGraph(Graph* g){
    int i;
    for (i = 0; i < MAX; i++){
        g->list[i] = NULL;
    }
    g->count = 0;
}

Vertex* createVertex(int dest){
    Vertex* newVertex = malloc(sizeof(Vertex));
    newVertex->dest = dest;
    newVertex->tail = NULL;
    return newVertex;
}

// 3. UPDATED: Insert neighbor index
void insertToGraph(Graph* g, int src, int dest){
    Vertex * newVertex = createVertex(dest);

    // Insert at HEAD of the linked list (O(1) time)
    newVertex->tail = g->list[src];
    g->list[src] = newVertex;
}

void displayList(Graph* g){
    int i;
    // Helper to print letters based on index
    char labels[] = {'A', 'B', 'C', 'D', 'E'}; 

    for (i = 0; i < MAX; i++){
        if(g->list[i] != NULL || i < 3) { // Just printing first few for demo
            printf("%c -> ", labels[i]);
            Vertex* trav;
            for (trav = g->list[i]; trav != NULL; trav = trav->tail){
                // Print the Label of the neighbor, not the int
                printf("%c -> ", labels[trav->dest]); 
            }
            printf("NULL\n");
        }
    }
}

void displayListBFS(Graph* g){
    Queue q;
    bool Visited[MAX] = {false};
    initQueue(&q);
    
    // Start at Index 0 ('A')
    int startVertex = 0;

    Visited[startVertex] = true;
    enqueue(&q, startVertex);

    char labels[] = {'A', 'B', 'C', 'D', 'E'};

    while (!isEmpty(&q)){
        int currentVertex = dequeue(&q);
        
        // Print the Letter representation
        printf("%c ", labels[currentVertex]); 

        Vertex* temp = g->list[currentVertex];

        while (temp != NULL){
            // 4. FIXED: temp->dest is an INT (0, 1, 2) so it fits in Visited[]
            if (Visited[temp->dest] == false){
                Visited[temp->dest] = true;
                enqueue(&q, temp->dest);
            }
            temp = temp->tail;
        }
    }
    printf("\n");
}

int main (){
    Graph g;

    initGraph(&g);
    
    // MAPPING: 0=A, 1=B, 2=C, 3=D

    // 0 (A) is connected to B(1) and C(2)
    insertToGraph(&g, 0, 1); 
    insertToGraph(&g, 0, 2); 

    // 1 (B) is connected to D(3) and A(0)
    insertToGraph(&g, 1, 3);
    insertToGraph(&g, 1, 0);

    // 2 (C) is connected to D(3)
    insertToGraph(&g, 2, 3);

    printf("== ADJACENCY LIST ==\n");
    displayList(&g);

    printf("\n== BFS TRAVERSAL ==\n");
    displayListBFS(&g);

    return 0;
}