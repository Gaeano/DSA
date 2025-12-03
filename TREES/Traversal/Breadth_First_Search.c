#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}Node;


typedef struct{
    int front;
    int rear;
    Node* tree[MAX];   
}Queue;


void enqueue(Queue* q, Node* value);
Node* dequeue(Queue* q);
bool isEmpty(Queue q);
void bfs(Node* n);


void enqueue(Queue* q, Node* value){
    q->rear++;
    q->tree[q->rear] = value;
}

Node* dequeue(Queue* q){
    if (q->front == q->rear){
        q->front = q->rear= -1;
    }
    q->front++;
    return q->tree[q->front];
}

bool isEmpty(Queue q){
    return q.rear == -1;
}

void bfs(Node* n){
    Queue q;
    q.front = -1;
    q.rear = -1;

    enqueue(&q, n);

    while (!isEmpty(q)){
        Node* current = dequeue(&q);

        printf("%d ", current);

        if (current->left != NULL){
            enqueue(&q ,current->left);
        }

        if (current->right != NULL){
            enqueue(&q, current->right);
        }
    }
}

int main (){
    int PPRep[MAX];
    Node* CLRep[MAX];

    int i;
    for (i = 0; i < MAX; i++){
        PPRep[i] = -2; //initialize to all DNE
    }



}


