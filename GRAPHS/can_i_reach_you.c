#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct{
    int data[MAX];
    int top;
}Stack;


void initializeStack(Stack* s){
    s->top = -1;
}


void push(Stack* s, int data){
    if (s->top < MAX){
        s->data[s->top+1] = data;
        s->top++;
    }
}

int pop(Stack* s){
    if (s->top != -1){
        int retVal = s->data[s->top];
        s->top--;
        
        return retVal;
    }
}

Node* adjList[MAX];
int visited[MAX] = {0};

void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void resetVisited() {
    for(int i=0; i<MAX; i++) visited[i] = 0;
}

int hasPath(int start, int target) {
    visited[start] = 1;
    
    Stack s;
    initializeStack(&s);
    push(&s, start);
    
    while (s.top != -1){
        int curr = pop(&s);
        if (curr == target){
            return 1;
        }
        
        Node* temp;
        for (temp = adjList[curr]; temp != NULL; temp = temp->next){
            if (visited[temp->dest] == 0){
                visited[temp->dest] = 1;
                push(&s, temp->dest);
            }
        }
        
        
    }
    
    return 0; // Placeholder
}

int main() {
    for(int i=0; i<MAX; i++) adjList[i] = NULL;
    
    // Graph Connections (Directed):
    // 0 -> 1 -> 2
    // 0 -> 3
    // 4 -> 5
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(0, 3);
    addEdge(4, 5);

    // Test Case 1: Can 0 reach 2?
    resetVisited();
    if (hasPath(0, 2)) printf("Path 0->2: Yes\n");
    else printf("Path 0->2: No\n");

    // Test Case 2: Can 3 reach 1?
    resetVisited();
    if (hasPath(3, 1)) printf("Path 3->1: Yes\n");
    else printf("Path 3->1: No\n");
    
    // Test Case 3: Can 0 reach 5?
    resetVisited();
    if (hasPath(0, 5)) printf("Path 0->5: Yes\n");
    else printf("Path 0->5: No\n");

    return 0;
}

