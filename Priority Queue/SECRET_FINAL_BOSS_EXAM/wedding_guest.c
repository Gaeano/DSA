#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_NAME 50

// Guest structure
typedef struct {
    char name[MAX_NAME];
    int priority; // 1=VIP, 2=Family, 3=Friends, 4=Others
} Guest;

// Priority Queue structure
typedef struct {
    Guest guests[MAX_GUESTS];
    int size;
} PriorityQueue;

// Initialize priority queue
void initPQ(PriorityQueue* pq) {
    pq->size = 0;
}

void swap (Guest* a, Guest* b){
    Guest temp = *a;
    *a = *b;
    *b = temp;
}


void upHeapify(PriorityQueue *pq, int index){
    if (pq->size > 0){
            int parent = (index - 1) / 2;
        
        if (parent < pq->size && pq->guests[index].priority < pq->guests[parent].priority){
        swap(&pq->guests[index], &pq->guests[parent]);
        index = parent;
        upHeapify(pq, index);
        }
    }
    
    
}

// TODO: Implement insert function
// Insert a guest into the priority queue based on priority
void insert(PriorityQueue* pq, char* name, int priority) {
    Guest newGuest;
    newGuest.priority = priority;
    strcpy(newGuest.name, name);
    pq->guests[pq->size] = newGuest;
    pq->size++; 
    upHeapify(pq, pq->size-1);
    
    // Your code here
}

void downHeapify(PriorityQueue* pq, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < pq->size && pq->guests[left].priority < pq->guests[smallest].priority){
        smallest = left;
    }
    
    if (right < pq->size && pq->guests[right].priority < pq->guests[smallest].priority){
        smallest = right;
    }
    
    if (smallest != index){
        swap(&pq->guests[smallest], &pq->guests[index]);
        index = smallest;
        downHeapify(pq, index);    
    }
}

// TODO: Implement isEmpty function
int isEmpty(PriorityQueue* pq) {
    // Your code here
    return (pq->size == 0) ? 1 : 0;
}

// TODO: Implement extractMin function
// Extract the guest with highest priority (lowest priority number)
Guest extractMin(PriorityQueue* pq) {
    Guest emptyGuest = {"", -1};
    // Your code here
    if (!isEmpty(pq)){
         Guest minGuest = pq->guests[0];
        pq->guests[0] = pq->guests[pq->size-1];
        downHeapify(pq, 0);
        pq->size--;
        
        return minGuest;
    }
   
    
    return emptyGuest;
}



// Process wedding guests in priority order
void processWeddingGuests(Guest guests[], int n) {
    PriorityQueue pq;
    initPQ(&pq);
    
    printf("Adding guests to priority queue:\n");
    for (int i = 0; i < n; i++) {
        printf("  %s (Priority: %d)\n", guests[i].name, guests[i].priority);
        insert(&pq, guests[i].name, guests[i].priority);
    }
    
    printf("\nSeating order (by priority):\n");
    int position = 1;
    while (!isEmpty(&pq)) {
        Guest g = extractMin(&pq);
        printf("  %d. %s (Priority: %d)\n", position++, g.name, g.priority);
    }
}

int main() {
    printf("========== WEDDING GUEST PRIORITY QUEUE ==========\n\n");
    
    // Test case
    Guest guests[] = {
        {"Alice", 2},    // Family
        {"Bob", 1},      // VIP
        {"Charlie", 4},  // Others
        {"Diana", 2},    // Family
        {"Eve", 3},      // Friends
        {"Frank", 1},    // VIP
        {"Grace", 3},    // Friends
        {"Henry", 4}     // Others
    };
    
    int n = sizeof(guests) / sizeof(guests[0]);
    
    printf("Priority Levels:\n");
    printf("  1 = VIP\n");
    printf("  2 = Family\n");
    printf("  3 = Friends\n");
    printf("  4 = Others\n\n");
    
    processWeddingGuests(guests, n);
    
    printf("\n========== EXPECTED OUTPUT ==========\n");
    printf("Seating order (by priority):\n");
    printf("  1. Bob (Priority: 1)\n");
    printf("  2. Frank (Priority: 1)\n");
    printf("  3. Alice (Priority: 2)\n");
    printf("  4. Diana (Priority: 2)\n");
    printf("  5. Eve (Priority: 3)\n");
    printf("  6. Grace (Priority: 3)\n");
    printf("  7. Charlie (Priority: 4)\n");
    printf("  8. Henry (Priority: 4)\n");
    
    return 0;
}