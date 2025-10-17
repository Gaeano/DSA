#include <stdio.h>

//Heapsort practice
#define max 20
typedef struct{
    int queue[20];
    int lastNdx;
    int count;
}PriorityQueue;

void insert(PriorityQueue* pq, int value);
void upHeapify (PriorityQueue* pq, int index);
int deleteMin(PriorityQueue* pq);
void downHeapify(PriorityQueue* pq, int index);
void swap(int *a, int *b);
void heapSort(PriorityQueue* pq);
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(PriorityQueue* pq, int value){
    if (pq->count == max){
        printf("queue is full\n"); 
    } else {
        pq->lastNdx++;
        pq->queue[pq->lastNdx] = value;
        pq->count++;
        upHeapify(pq, pq->count-1);
    }
}

void upHeapify (PriorityQueue* pq, int index){
    int parent = ((index - 1 )/ 2);

    if (pq->queue[parent] > pq->queue[index]){
        swap(&pq->queue[parent], &pq->queue[index]);
        upHeapify(pq, parent);
    }
}

int deleteMin(PriorityQueue* pq){
    int orig;
    if (pq->count == 0){
        printf("queue is empty\n");
    }else {
        orig = pq->queue[0];
        pq->queue[0] = pq->queue[pq->lastNdx];
        pq->lastNdx--;
        pq->count--;
        downHeapify(pq, 0);
    }

    return orig;
}

void downHeapify(PriorityQueue* pq, int index){
    int smallest = index;
    int left = (2*index + 1);
    int right = (2*index + 2);

    if (left < pq->count && pq->queue[smallest] > pq->queue[left]){
        smallest = left;
    }

    if (right < pq->count && pq->queue[smallest] > pq->queue[right]){
        smallest = right;
    }

    if (smallest != index){
        swap(&pq->queue[smallest], &pq->queue[index]);
        downHeapify(pq, smallest);
    }
}

void heapSort(PriorityQueue* pq){
    int orig, catcher, i , x;

    orig = pq->lastNdx;


    while (pq->lastNdx != -1){
        catcher = deleteMin(pq);
        pq->queue[pq->lastNdx+1] = catcher;
    }
    pq->lastNdx = orig;
    pq->count = orig + 1;
}


int main (){
    //minheap
    int i;
    PriorityQueue pq;
    pq.count = 0;
    pq.lastNdx = -1;

    insert(&pq, 0);
    insert(&pq, 6);
    insert(&pq, 8);
    insert(&pq, 1);
    insert(&pq, 7);
    insert(&pq, 5);

    printf("--BEFORE HEAPSORT--\n");
    for (i = 0; i < pq.count;i++){
        printf("%d ", pq.queue[i]);
    }
    printf("\n");

    printf("--AFTER HEAPSORT--\n");
    heapSort(&pq);
     for (i = 0; i < pq.count;i++){
        printf("%d ", pq.queue[i]);
    }

    return 0;

}