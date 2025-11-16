#ifndef TYPES_H
#define TYPES_H

// Maximum number of processes the scheduler can hold
#define MAX_PROCESSES 10

// Process Structure
// A structure representing a task/process in the operating system.
typedef struct {
    int pid;      // Process ID (Unique Identifier)
    int priority; // Priority level (Higher number = Higher priority)
} Process;

// Priority Queue Structure (Max Heap Implementation)
// The heap array will store the processes.
typedef struct {
    Process heap[MAX_PROCESSES]; // Array to store the heap elements
    int size;                    // Current number of processes in the queue
    int capacity;                // Maximum capacity of the queue
} PriorityQueue;

void initQueue(PriorityQueue *pq);
void swap(Process *a, Process *b);
void heapifyDown(PriorityQueue *pq, int index);
void insertProcess(PriorityQueue *pq, Process newProcess);
Process extractMax(PriorityQueue *pq);
void printQueue(PriorityQueue *pq);
void runEnqueueTest(void);
void runDequeueTest(void);
void runCombinationTest(void);

#endif