#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REQUESTS 100
#define MAX_NAME 50

// Ticket Request structure
typedef struct {
    char name[MAX_NAME];
    int priority;  // 1=Early bird, 2=VIP, 3=Regular
    int timestamp; // Time of request
} TicketRequest;

// Priority Queue structure
typedef struct {
    TicketRequest requests[MAX_REQUESTS];
    int size;
    int lastNdx;
} PriorityQueue;

// Initialize priority queue
void initPQ(PriorityQueue* pq) {
    pq->size = 0;
    pq->lastNdx = -1;
}

void swap(TicketRequest* a, TicketRequest* b){
    TicketRequest temp = *a;
    *a = *b;
    *b = temp;
}

void upHeapify(PriorityQueue* pq, int index){
    if (index >= 0){
        int parent = (index - 1) / 2;
        if (parent < pq->size && pq->requests[parent].priority != pq->requests[index].priority){
            if (parent < pq->size && pq->requests[index].priority < pq->requests[parent].priority){
                swap(&pq->requests[parent], &pq->requests[index]);
                upHeapify(pq, parent);
            }
        } else if (parent < pq->size && pq->requests[parent].priority == pq->requests[index].priority) {
            if (parent < pq->size && pq->requests[index].timestamp < pq->requests[parent].timestamp){
                swap(&pq->requests[parent], &pq->requests[index]);
                upHeapify(pq, parent);
            }
        }
        
    }
}

void downHeapify(PriorityQueue* pq, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
        
        
        //for the left child
         if (left < pq->size && pq->requests[left].priority != pq->requests[smallest].priority){
            if (pq->requests[left].priority < pq->requests[smallest].priority){
                smallest = left;
            }
         } else {
              if (left < pq->size && pq->requests[left].timestamp < pq->requests[smallest].timestamp){
                smallest = left;
            }
         }
         
        //for the right child
        if (right < pq->size && pq->requests[right].priority != pq->requests[smallest].priority){
            if (pq->requests[right].priority < pq->requests[smallest].priority){
                smallest = right;
            }
        } else {
            if (right < pq->size && pq->requests[right].timestamp < pq->requests[smallest].timestamp){
                smallest = right;
            }
        }
        
        if (smallest != index){
            swap(&pq->requests[smallest], &pq->requests[index]);
            index = smallest;
            downHeapify(pq, index);
        }
    
    
   
}

// TODO: Implement insert function
// Insert a ticket request into priority queue
// Priority: First by priority level (1 > 2 > 3), then by timestamp (earlier > later)
void insert(PriorityQueue* pq, char* name, int priority, int timestamp) {
    // Your code here'
    TicketRequest newTicket;
    newTicket.priority = priority;
    newTicket.timestamp = timestamp;
    strcpy(newTicket.name, name);
    
    pq->requests[pq->size] = newTicket;
    pq->lastNdx++;
    pq->size++;
    upHeapify(pq, pq->size-1);
        
}

// TODO: Implement isEmpty function
int isEmpty(PriorityQueue* pq) {
    // Your code here
    return (pq->size == 0) ? 1 : 0;
}

// TODO: Implement extractMin function
// Extract the ticket request with highest priority
TicketRequest extractMin(PriorityQueue* pq) {
    TicketRequest empty = {"", -1, -1};
    // Your code here
    if (!isEmpty(pq)){
        TicketRequest minimum = pq->requests[0];
        pq->requests[0] = pq->requests[pq->size-1];
        pq->size--;
        pq->lastNdx--;
        downHeapify(pq, 0);
        
        return minimum;
    }
    
    
    
    return empty;
}



// Process concert ticket requests
void processConcertTickets(TicketRequest requests[], int n) {
    PriorityQueue pq;
    initPQ(&pq);
    
    printf("Receiving ticket requests:\n");
    for (int i = 0; i < n; i++) {
        printf("  %s (Priority: %d, Time: %d)\n", 
               requests[i].name, requests[i].priority, requests[i].timestamp);
        insert(&pq, requests[i].name, requests[i].priority, requests[i].timestamp);
    }
    
    printf("\nProcessing order:\n");
    int position = 1;
    int orig = pq.lastNdx;
    while (!isEmpty(&pq)) {
        TicketRequest tr = extractMin(&pq);
        printf("  %d. %s (Priority: %d, Time: %d)\n", 
               position++, tr.name, tr.priority, tr.timestamp);
    }
    pq.lastNdx = orig;
}
// TODO: Implement heapSort function
// Sort the ticket requests array using heap sort algorithm
// Should sort by priority first, then by timestamp (same ordering as PQ)
void heapSort(TicketRequest arr[], int n) {
    int orig, i;
    PriorityQueue tempPQ;
    initPQ(&tempPQ);
    
    for (i = 0; i < n; i++){
        insert(&tempPQ, arr[i].name, arr[i].priority, arr[i].timestamp);
    }
     orig = tempPQ.lastNdx;   
    
        
   
    for (i = 0; i < n; i++){
        TicketRequest catcher = extractMin(&tempPQ);
        arr[tempPQ.lastNdx+1] = catcher;
    }
    
}



// Display sorted ticket requests
void displaySortedRequests(TicketRequest requests[], int n) {
    printf("\nSorted ticket requests (using Heap Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("  %d. %s (Priority: %d, Time: %d)\n", 
               i + 1, requests[i].name, requests[i].priority, requests[i].timestamp);
    }
}

int main() {
    printf("========== CONCERT TICKET PRIORITY QUEUE ==========\n\n");
    
    // Test case
    TicketRequest requests[] = {
        {"John", 3, 5},     // Regular, time 5
        {"Sarah", 1, 2},    // Early bird, time 2
        {"Mike", 2, 4},     // VIP, time 4
        {"Emma", 1, 1},     // Early bird, time 1
        {"Tom", 3, 3},      // Regular, time 3
        {"Lisa", 2, 6},     // VIP, time 6
        {"David", 1, 7},    // Early bird, time 7
        {"Anna", 3, 8}      // Regular, time 8
    };
    
    int n = sizeof(requests) / sizeof(requests[0]);
    
    printf("Priority Levels:\n");
    printf("  1 = Early bird (highest priority)\n");
    printf("  2 = VIP\n");
    printf("  3 = Regular (lowest priority)\n");
    printf("\nNote: Within same priority, earlier timestamp is processed first\n\n");
    
    processConcertTickets(requests, n);
    
    printf("\n========== EXPECTED OUTPUT ==========\n");
    printf("Processing order:\n");
    printf("  1. Emma (Priority: 1, Time: 1)\n");
    printf("  2. Sarah (Priority: 1, Time: 2)\n");
    printf("  3. David (Priority: 1, Time: 7)\n");
    printf("  4. Mike (Priority: 2, Time: 4)\n");
    printf("  5. Lisa (Priority: 2, Time: 6)\n");
    printf("  6. Tom (Priority: 3, Time: 3)\n");
    printf("  7. John (Priority: 3, Time: 5)\n");
    printf("  8. Anna (Priority: 3, Time: 8)\n");
    
    // Part 2: Heap Sort approach
    printf("\n\n========== HEAP SORT EXERCISE ==========\n\n");
    
    // Create a copy of requests for heap sort
    TicketRequest requestsCopy[] = {
        {"John", 3, 5},     // Regular, time 5
        {"Sarah", 1, 2},    // Early bird, time 2
        {"Mike", 2, 4},     // VIP, time 4
        {"Emma", 1, 1},     // Early bird, time 1
        {"Tom", 3, 3},      // Regular, time 3
        {"Lisa", 2, 6},     // VIP, time 6
        {"David", 1, 7},    // Early bird, time 7
        {"Anna", 3, 8}      // Regular, time 8
    };
    
    printf("Before Heap Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("  %s (Priority: %d, Time: %d)\n", 
               requestsCopy[i].name, requestsCopy[i].priority, requestsCopy[i].timestamp);
    }
    
    heapSort(requestsCopy, n);
    displaySortedRequests(requestsCopy, n);
    
    printf("\n========== EXPECTED OUTPUT (Heap Sort) ==========\n");
    printf("Sorted ticket requests (using Heap Sort):\n");
    printf("  1. Anna (Priority: 3, Time: 8)\n");
    printf("  2. John (Priority: 3, Time: 5)\n");
    printf("  3. Tom (Priority: 3, Time: 3)\n");
    printf("  4. Lisa (Priority: 2, Time: 6)\n");
    printf("  5. Mike (Priority: 2, Time: 4)\n");
    printf("  6. David (Priority: 1, Time: 7)\n");
    printf("  7. Sarah (Priority: 1, Time: 2)\n");
    printf("  8. Emma (Priority: 1, Time: 1)\n");
    
    return 0;
}