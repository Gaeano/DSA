#include <stdio.h>
#include <stdlib.h>
#include "types.h"

// =================================================================
//                 TEST SCENARIOS IMPLEMENTATION
// =================================================================

/**
 * @brief Test Scenario 1: Focuses solely on Enqueuing processes.
 * Demonstrates how the Max Heap is built upon insertion.
 */
void runEnqueueTest() {
    PriorityQueue schedulerQueue;
    initQueue(&schedulerQueue);

    printf("\n--- Test 1: ENQUEUE (Process Arrival) ---\n");
    printf("Inserting processes in various priority orders:\n");

    insertProcess(&schedulerQueue, (Process){.pid = 10, .priority = 5});
    insertProcess(&schedulerQueue, (Process){.pid = 20, .priority = 8}); // Higher priority than 10
    insertProcess(&schedulerQueue, (Process){.pid = 30, .priority = 3});
    insertProcess(&schedulerQueue, (Process){.pid = 40, .priority = 9}); // Highest priority
    insertProcess(&schedulerQueue, (Process){.pid = 50, .priority = 7});

    printQueue(&schedulerQueue);
    printf("NOTE: The highest priority process (PID 40, Pri 9) is at the top of the heap (first in the list).\n");
}

/**
 * @brief Test Scenario 2: Focuses solely on Dequeuing processes.
 * Requires pre-loading data to demonstrate extraction behavior.
 */
void runDequeueTest() {
    PriorityQueue schedulerQueue;
    initQueue(&schedulerQueue);

    printf("\n--- Test 2: DEQUEUE (Scheduling Dispatch) ---\n");
    printf("Pre-loading 5 processes for scheduling...\n");

    // Pre-load data
    insertProcess(&schedulerQueue, (Process){.pid = 100, .priority = 4});
    insertProcess(&schedulerQueue, (Process){.pid = 200, .priority = 1});
    insertProcess(&schedulerQueue, (Process){.pid = 300, .priority = 6});
    insertProcess(&schedulerQueue, (Process){.pid = 400, .priority = 3});
    insertProcess(&schedulerQueue, (Process){.pid = 500, .priority = 5});

    printf("\nReady Queue before dispatch:\n");
    printQueue(&schedulerQueue);

    printf("\nDispatching processes in order of priority (Max Heap extraction):\n");
    while (schedulerQueue.size > 0) {
        Process dispatched = extractMax(&schedulerQueue);
        if (dispatched.pid != -1) {
            printf("<- DEQUEUED: SCHEDULING Process ID %d (Priority: %d)\n", dispatched.pid, dispatched.priority);
            printQueue(&schedulerQueue); // Show state after each dispatch
        }
    }
    printf("\nQueue is now empty.\n");
}


/**
 * @brief Test Scenario 3: The original combination of Enqueue and Dequeue,
 * demonstrating a dynamic scheduling environment.
 */
void runCombinationTest() {
    PriorityQueue schedulerQueue;
    initQueue(&schedulerQueue);

    printf("\n--- Test 3: COMBINATION (Dynamic OS Scheduling) ---\n");

    printf("\n--- STEP 1: Process Arrival (Enqueuing Tasks) ---\n");

    // Scenario: High priority interactive task arrives
    insertProcess(&schedulerQueue, (Process){.pid = 101, .priority = 9}); // High priority
    // Scenario: Background job arrives
    insertProcess(&schedulerQueue, (Process){.pid = 205, .priority = 3}); // Low priority
    // Scenario: Medium-priority system task
    insertProcess(&schedulerQueue, (Process){.pid = 312, .priority = 5}); // Medium priority
    // Scenario: Another background job arrives (lower priority than previous one)
    insertProcess(&schedulerQueue, (Process){.pid = 400, .priority = 2}); // Lowest priority

    printQueue(&schedulerQueue);

    printf("\n--- STEP 2: Scheduler Dispatch (Dequeuing Highest Priority) ---\n");

    // The scheduler picks the task with the highest priority (PID 101, Pri 9)
    Process dispatched1 = extractMax(&schedulerQueue);
    printf("<- DEQUEUED: SCHEDULING Process ID %d (Priority: %d)\n", dispatched1.pid, dispatched1.priority);

    // Scenario: A new critical process arrives while others are waiting
    printf("\nNew critical process arrives:\n");
    insertProcess(&schedulerQueue, (Process){.pid = 550, .priority = 10}); // NEW Highest priority

    printQueue(&schedulerQueue);

    // The scheduler picks the next task. It should be PID 550 (Pri 10) now.
    Process dispatched2 = extractMax(&schedulerQueue);
    printf("<- DEQUEUED: SCHEDULING Process ID %d (Priority: %d)\n", dispatched2.pid, dispatched2.priority);

    // Continue scheduling the remaining tasks
    printf("\n--- STEP 3: Scheduling Remaining Tasks ---\n");

    while (schedulerQueue.size > 0) {
        Process dispatched = extractMax(&schedulerQueue);
        printf("<- DEQUEUED: SCHEDULING Process ID %d (Priority: %d)\n", dispatched.pid, dispatched.priority);
    }

    printf("\nAll processes have been scheduled and executed in priority order.\n");
}