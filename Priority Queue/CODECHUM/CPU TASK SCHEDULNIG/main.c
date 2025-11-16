#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/**
 * @brief Prints the current processes in the queue (in heap order, not sorted).
 * @param pq Pointer to the PriorityQueue.
 */
void printQueue(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Current Ready Queue: [Empty]\n");
        return;
    }

    printf("\n--- Current Ready Queue (Heap Order: Priority, PID) ---\n");
    for (int i = 0; i < pq->size; i++) {
        printf("| P%d (Pri:%d) ", pq->heap[i].pid, pq->heap[i].priority);
    }
    printf("|\n------------------------------------------------------\n");
}

int main() {
    int choice;

    printf("=============== OS SCHEDULER PRIORITY QUEUE MENU ===============");
    printf("\nSelect a Test Scenario to Run:");
    printf("\n1. Enqueue Test (Demonstrates Max Heap build on insertion)");
    printf("\n2. Dequeue Test (Demonstrates Max Heap extraction/scheduling)");
    printf("\n3. Full Combination Test (Dynamic OS Scheduling Scenario)");
    printf("\n==================================================================");
    printf("\nEnter your choice (1, 2, or 3): ");

    if (scanf("%d", &choice) != 1) {
        printf("\n\n--- INVALID INPUT: Please enter a number (1-3). Exiting. ---\n");
        return 1;
    }

    switch (choice) {
        case 1:
            runEnqueueTest();
            break;
        case 2:
            runDequeueTest();
            break;
        case 3:
            runCombinationTest();
            break;
        default:
            printf("\n\n--- INVALID CHOICE: Please selected 1, 2, or 3. Exiting. ---\n");
            break;
    }

    printf("\nProgram finished execution.\n");

    return 0;
}