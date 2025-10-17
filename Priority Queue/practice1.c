#include <stdio.h>
#include <stdlib.h>
//pharmacy queue using priority queue

#define max 40

typedef struct{
    int queue[max];
    int count;
    int lastNdx;
}PriorityQueue;

//heapsort for minheap is descending


void Upheapify(PriorityQueue* pq, int index); //used for insert
void Downheapify(PriorityQueue* pq, int index); //used for delete
void enqueue(PriorityQueue* pq, int value); //insert at tail
void deleteMin(PriorityQueue* pq); //dequeue top
void swap(int *a, int *b); //useful in heapify functions
int peek(PriorityQueue* pq);
void displayQueue(PriorityQueue pq);

//to access left child,( 2*n + 1 ); right child =( 2*n + 2)
//to access parent (index - 1 / 2)

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Upheapify(PriorityQueue* pq, int index){ //used for insert
    int parentPrio = ((index - 1) / 2);

    if (pq->queue[parentPrio] > pq->queue[index]){
        swap(&pq->queue[index], &pq->queue[parentPrio]);
        Upheapify(pq, parentPrio); //call this again coz u gotta do the parent over and over again until the condition is not met!
    } //parent is greater! which is nono cause dis is minHeap

}

void Downheapify(PriorityQueue* pq, int index){//used for delete
    int leftChild = (2*index + 1);
    int rightChild  = (2*index + 2);
    int smallest = index;

    if (pq->queue[smallest] > leftChild){ //find the smallest between the parent and hte left
        smallest = leftChild; // parent is greater than child, make smallest the leftchild
    }

    if (pq->queue[smallest] > rightChild){ //compare leftchild and rightchild
        smallest = rightChild; //if leftchild is bigger than rightchild, make smallest rightchild
    }

    if (index != smallest){ //if the original index is not equal to teh smallest swap it.
        swap(&pq->queue[index], &pq->queue[smallest]);
        Downheapify(pq, smallest); //repeat until index == smallest
    }

    
} 

void enqueue(PriorityQueue* pq, int value){//insert at tail
    if (pq->count == max){
        printf("queue is full");
    } else {
        pq->queue[pq->count] = value;
        pq->lastNdx = pq->count;
        pq->count++;
        Upheapify(pq, pq->count-1);
        printf("enqueued value %d at index %d\n", value, pq->count-1);
    }
} 

void deleteMin(PriorityQueue* pq){ //dequeue top

    if (pq->count == 0){
        printf("its empty!");
    }

    printf("Dequeued value %d\n", pq->queue[0]);
    pq->queue[0] = pq->queue[pq->count-1];
    pq->count--;
    pq->lastNdx = pq->count;
    Downheapify(pq, 0);
} 
int peek(PriorityQueue* pq){
    return pq->queue[0];
}

void displayQueue(PriorityQueue pq){
    int i;

    for (i = 0; i < pq.count; i++){
        printf("%d\n", pq.queue[i]);
    }
    printf("\n");
}


int main (){
    PriorityQueue pq;
    
    pq.count = 0;
    
    printf("--INSERTING VALUES--\n");
    enqueue(&pq, 2);
    enqueue(&pq, 1);
    enqueue(&pq, 6);
    enqueue(&pq, 0);
    enqueue(&pq, 3);

    printf("--PRINTING TOP VALUE--\n");
    int top = peek(&pq);
    printf("TOP VALUE: %d\n", top);

    printf("--DISPLAYING QUEUE--\n");
    displayQueue(pq);

    printf("--DEQUEUE--\n");
    deleteMin(&pq);

    printf("--AFTER QUEUE--\n");
    displayQueue(pq);


    return 0;

    
}