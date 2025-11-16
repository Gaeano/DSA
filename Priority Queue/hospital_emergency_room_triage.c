#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct{
    char name[50];
    int priority;
    int arrivalTime;
}Patient;

typedef struct{
    Patient heap[MAX];
    int size; //the count
    int capacity; //max
}PriorityQueue;


void swap (Patient* a, Patient* b);
void initQueue(PriorityQueue * pq);
void UpHeapify(PriorityQueue * pq, int index);
void DownHeapify(PriorityQueue* pq, int index);
Patient deleteMin(PriorityQueue* pq);
void insertPatient(PriorityQueue* pq, Patient newPatient);
void printQueue(PriorityQueue pq);

void swap (Patient* a, Patient* b){
    Patient temp;
    temp = *a;
    *a = *b; 
    *b = temp;
}

void initQueue(PriorityQueue * pq){
    pq->capacity = MAX;
    pq->size = 0;
}

void UpHeapify(PriorityQueue * pq, int index){
    if (pq->size != 0){
        int parent = (index - 1) / 2;

        if (pq->heap[parent].priority > pq->heap[index].priority){
            swap(&pq->heap[parent], &pq->heap[index]);
            index = parent;
            UpHeapify(pq, index);
        }
    }
}

void DownHeapify(PriorityQueue* pq, int index){
    int smallest = index; 
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->heap[left].priority < pq->heap[smallest].priority){
        smallest = left;
    }

    if (right < pq->size && pq->heap[right].priority < pq->heap[smallest].priority){
        smallest = right;
    }

    if (smallest != index){
        swap(&pq->heap[smallest], &pq->heap[index]);
        DownHeapify(pq, smallest);
    }
}

Patient deleteMin(PriorityQueue* pq){
    Patient min = pq->heap[0];
    printf("Calling patient %s with priority number %d\n", min.name, min.priority);
    pq->heap[0] = pq->heap[pq->size-1];
    pq->size--;

    if (pq->size < pq->capacity){
        DownHeapify(pq, 0);
    }

    return min;
}

void insertPatient(PriorityQueue* pq, Patient newPatient){
    pq->heap[pq->size] = newPatient;
    printf("-> Inserting patient %s with priority %d\n", newPatient.name ,newPatient.priority);
    UpHeapify(pq, pq->size);

    pq->size++;

}

void printQueue(PriorityQueue pq){
    int i;

    for (i = 0; i < pq.size; i++){
        printf("Name: %s, Arrival Time: %d, Priority: %d\n", pq.heap[i].name, pq.heap[i].arrivalTime, pq.heap[i].priority);
    }
}

int main (){
    PriorityQueue pq;

    initQueue(&pq);

    Patient patient1;
    strcpy(patient1.name, "Lukas Manlangit");
    patient1.arrivalTime = 2;
    patient1.priority = 1;

    Patient patient2;
    strcpy(patient2.name, "Ana Serrano");
    patient2.arrivalTime = 5;
    patient2.priority = 3;

    Patient patient3;
    strcpy(patient3.name, "Miguel Santos");
    patient3.arrivalTime = 1;
    patient3.priority = 2;

    Patient patient4;
    strcpy(patient4.name, "Rica Delos Reyes");
    patient4.arrivalTime = 4;
    patient4.priority = 1;

    Patient patient5;
    strcpy(patient5.name, "Jasmine Cruz");
    patient5.arrivalTime = 3;
    patient5.priority = 2;

    Patient patient6;
    strcpy(patient6.name, "Omar Villanueva");
    patient6.arrivalTime = 6;
    patient6.priority = 4;
    printf("== ENQUEUE ==\n");
    insertPatient(&pq, patient1);
    insertPatient(&pq, patient2);
    insertPatient(&pq, patient3);
    insertPatient(&pq, patient4);
    insertPatient(&pq, patient5);
    insertPatient(&pq, patient6);

    printf("\n== DEQUEUE ==\n");
    deleteMin(&pq);
    deleteMin(&pq);
    deleteMin(&pq);

    printf("\n== SHOW QUEUE == \n");
    printQueue(pq);

    return 0;
}