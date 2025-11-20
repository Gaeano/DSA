    #include <stdio.h>
    #include <stdlib.h>
    #include "types.h"

    /*typedef struct {
        int pid;      // Process ID (Unique Identifier)
        int priority; // Priority level (Higher number = Higher priority)
    } Process;
    */
    // Priority Queue Structure (Max Heap Implementation)
    // The heap array will store the processes.

    /*typedef struct {
        Process heap[MAX_PROCESSES]; // Array to store the heap elements
        int size;                    // Current number of processes in the queue
        int capacity;                // Maximum capacity of the queue
    } PriorityQueue;
    */
    void initQueue(PriorityQueue *pq){
        pq->size = 0;
        pq->capacity = MAX_PROCESSES;
        printf("\n--- Scheduler Queue initialized with capacity %d. ---\n", pq->capacity);
    }

    void swap(Process *a, Process *b){
        Process temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyDown(PriorityQueue *pq, int index){
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        
        if (pq->heap[left].priority > pq->heap[largest].priority && left < pq->size){
            largest = left;
        }
        
        if (pq->heap[right].priority > pq->heap[largest].priority && right < pq->size){
            largest = right;
        }
        
        if (largest != index){
            swap(&pq->heap[largest], &pq->heap[index]);
            heapifyDown(pq, largest);
        }
    }

    void heapifyUp(PriorityQueue* pq, int index){
        
        int parent = (index - 1 )/ 2;
        
        if (pq->heap[parent].priority < pq->heap[index].priority){
            swap(&pq->heap[parent], &pq->heap[index]);
            index = parent;
            heapifyUp(pq, index);
        }

    }

    void insertProcess(PriorityQueue *pq, Process newProcess){
        pq->heap[pq->size] = newProcess;
        printf("-> ENQUEUED: Process ID %d (Priority: %d)\n", newProcess.pid, newProcess.priority);
        
        heapifyUp(pq, pq->size);
        pq->size++;

    }

    Process extractMax(PriorityQueue *pq){
        if (pq->size != 0){
            Process orig = pq->heap[0];
            
            pq->heap[0] = pq->heap[pq->size-1];
            pq->size--;
            heapifyDown(pq, 0);
            return orig;
        } 
    }

