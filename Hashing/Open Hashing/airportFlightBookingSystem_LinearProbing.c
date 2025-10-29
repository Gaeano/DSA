#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include <stdbool.h>

typedef enum {
    EMPTY,
    OCCUPIED,
    DELETED
} SlotStatus;

typedef struct Flight {
    char flightCode[7];
    char destination[50];
    int availableSeats;
    float price;
    SlotStatus status;
} Flight;

typedef struct FlightHashTable {
    Flight* table;
    int size;
    int occupiedCount;
    int deletedCount;
} FlightHashTable;


FlightHashTable * createFlightTable(int size);
int hashFlightCode(char* flightCode, int tableSize);
int insertFlight(FlightHashTable* ht, char* code, char* dest, int seats, float price);
Flight* searchFlight(FlightHashTable* ht, char* flightCode);
int deleteFlight(FlightHashTable* ht, char* flightCode);
bool needsRehashing(FlightHashTable* ht);
FlightHashTable* rehash(FlightHashTable* ht);


FlightHashTable * createFlightTable(int size){
    FlightHashTable* flightTable = malloc (sizeof(FlightHashTable));
    flightTable->size = size;

    flightTable->table = (Flight*) malloc (size * sizeof(Flight));
    flightTable->occupiedCount = 0;
    flightTable->deletedCount = 0;

    int i;
    for (i = 0; i < size; i++){
        flightTable->table[i].status = EMPTY;
    }
    return flightTable;
}

int hashFlightCode(char* flightCode, int tableSize){
    int length = strlen(flightCode);
    int i; 
    int sum = 0;
    for (i = 0; i < length; i++){
        sum += flightCode[i] * (i+1);
    }

    return sum % tableSize;
}


int insertFlight(FlightHashTable* ht, char* code, char* dest, int seats, float price){
    int hashCode = hashFlightCode(code, ht->size);
    int success = 0;
    int i;
 
     for (i = 0; i < ht->size && success == 0; i++){
            int newHashcode;
            newHashcode = (hashCode + i) % ht->size;

            if (ht->table[newHashcode].status != OCCUPIED){
                strcpy(ht->table[newHashcode].flightCode, code);
                ht->table[newHashcode].availableSeats = seats;
                strcpy(ht->table[newHashcode].destination, dest);
                ht->table[newHashcode].price = price;
                ht->table[newHashcode].status = OCCUPIED;

                ht->occupiedCount++;
                success = 1;
            }
        }
            return success;
    }

    


Flight* searchFlight(FlightHashTable* ht, char* flightCode){
    int hashCode = hashFlightCode(flightCode, ht->size);
    int success = 0;
        int i;
        int newHashCode;
        for (i = 0; i < ht->size && success == 0; i++){
            newHashCode = (hashCode + i) % ht->size;

            if (ht->table[newHashCode].status != EMPTY && strcmp(ht->table[newHashCode].flightCode, flightCode) == 0){
                return &ht->table[newHashCode];
            }
        }

          printf("Fliight not found bossing\n");
    }

  


int deleteFlight(FlightHashTable* ht, char* flightCode){
    int hashCode = hashFlightCode(flightCode, ht->size);
    int success = 0;

        int i;
        int newHashCode;

        for (i = 0; i < ht->size && success == 0; i++){
            newHashCode = (hashCode + i) % ht->size;

            if ( ht->table[newHashCode].status == OCCUPIED && strcmp(ht->table[newHashCode].flightCode, flightCode) == 0){
                ht->table[newHashCode].status = DELETED;
                ht->deletedCount++;
                ht->occupiedCount--;    

                success = 1;

            }
        }
        return success;
    }


bool needsRehashing(FlightHashTable* ht){
    float load_factor;
    int tro = 0;
    load_factor = (float)ht->size / ht->occupiedCount;
    if (load_factor > 0.7 || ht->deletedCount > (ht->size / 2)){
       tro = 1;
    }

    return (tro == 1) ? true : false;
}



FlightHashTable* rehash(FlightHashTable* ht){
    int newSize = ht->size * 2;
    int i;
    FlightHashTable* newTable = createFlightTable(newSize);

    for (i = 0; i < ht->size; i++){
        if (ht->table[i].status == OCCUPIED){
        insertFlight(newTable, ht->table[i].flightCode, ht->table[i].destination, ht->table[i].availableSeats, ht->table[i].price);
        }
    }

    return newTable;
}

// int main() {
//     printf("=== Test Case 2.1: Basic Linear Probing ===\n\n");
    
//     FlightHashTable* ht = createFlightTable(11);
//     printf("Created flight hash table with size: 11\n\n");
    
//     // Insert flights
//     printf("Inserting flights...\n");
//     int result = insertFlight(ht, "AA1234", "New York", 150, 299.99);
//     printf("Insert AA1234: %s (index=%d)\n", 
//            result ? "Success" : "Failed", 
//            hashFlightCode("AA1234", 11));
    
//     result = insertFlight(ht, "BB5678", "London", 200, 599.99);
//     printf("Insert BB5678: %s (index=%d)\n", 
//            result ? "Success" : "Failed",
//            hashFlightCode("BB5678", 11));
    
//     result = insertFlight(ht, "CC9012", "Tokyo", 180, 899.99);
//     printf("Insert CC9012: %s (index=%d)\n\n", 
//            result ? "Success" : "Failed",
//            hashFlightCode("CC9012", 11));
    
//     // Search for flights
//     printf("Searching for flights...\n");
//     Flight* flight = searchFlight(ht, "BB5678");
//     if (flight != NULL) {
//         printf("Found: %s -> %s, Seats=%d, Price=$%.2f\n\n",
//                flight->flightCode, flight->destination,
//                flight->availableSeats, flight->price);
//     }
    
//     // Display table status
//     printf("Table Status:\n");
//     printf("Occupied slots: %d\n", ht->occupiedCount);
//     printf("Deleted slots: %d\n", ht->deletedCount);
//     printf("Load factor: %.2f\n", (float)ht->occupiedCount / ht->size);
    
//     return 0;
// }

// int main() {
//     printf("=== Test Case 2.2: Linear Probing Collisions ===\n\n");
    
//     FlightHashTable* ht = createFlightTable(11);
//     printf("Created flight hash table with size: 11\n\n");
    
//     // Insert flights that will collide
//     printf("Inserting flights with collisions...\n");
    
//     insertFlight(ht, "FL0001", "Paris", 150, 450.00);
//     int home1 = hashFlightCode("FL0001", 11);
//     printf("Inserted FL0001 at home position: %d\n", home1);
    
//     insertFlight(ht, "FL0012", "Rome", 160, 480.00);
//     int home2 = hashFlightCode("FL0012", 11);
//     printf("Inserted FL0012 (home=%d, ", home2);
//     // Find actual position by searching
//     for (int i = 0; i < 11; i++) {
//         if (ht->table[i].status == OCCUPIED && 
//             strcmp(ht->table[i].flightCode, "FL0012") == 0) {
//             printf("actual=%d, probes=%d)\n", i, (i - home2 + 11) % 11 + 1);
//             break;
//         }
//     }
    
//     insertFlight(ht, "FL0023", "Berlin", 170, 500.00);
//     int home3 = hashFlightCode("FL0023", 11);
//     printf("Inserted FL0023 (home=%d, ", home3);
//     for (int i = 0; i < 11; i++) {
//         if (ht->table[i].status == OCCUPIED && 
//             strcmp(ht->table[i].flightCode, "FL0023") == 0) {
//             printf("actual=%d, probes=%d)\n\n", i, (i - home3 + 11) % 11 + 1);
//             break;
//         }
//     }
    
//     // Display table layout
//     printf("Table layout:\n");
//     printf("Index | Status    | Flight Code | Destination\n");
//     printf("------|-----------|-------------|-------------\n");
//     for (int i = 0; i < 11; i++) {
//         char* status;
//         if (ht->table[i].status == EMPTY) status = "EMPTY";
//         else if (ht->table[i].status == OCCUPIED) status = "OCCUPIED";
//         else status = "DELETED";
        
//         if (ht->table[i].status == OCCUPIED) {
//             printf("  %2d  | %-9s | %-11s | %s\n", i, status,
//                    ht->table[i].flightCode, ht->table[i].destination);
//         } else {
//             printf("  %2d  | %-9s | -           | -\n", i, status);
//         }
//     }
//     printf("\n");
    
//     // Search with probe counting
//     printf("Searching for FL0023...\n");
//     Flight* flight = searchFlight(ht, "FL0023");
//     if (flight != NULL) {
//         printf("Found: %s -> %s\n", flight->flightCode, flight->destination);
//     }
    
//     printf("\nObservation: Primary clustering visible - consecutive occupied slots\n");
    
//     return 0;
// }

int main() {
    printf("=== Test Case 2.3: Lazy Deletion ===\n\n");
    
    FlightHashTable* ht = createFlightTable(11);
    
    // Setup: Insert flights with collisions (all hash to index 3)
    printf("Setup: Inserting flights...\n");
    insertFlight(ht, "FL0001", "Paris", 150, 450.00);
    insertFlight(ht, "FL0012", "Rome", 160, 480.00);
    insertFlight(ht, "FL0023", "Berlin", 170, 500.00);
    insertFlight(ht, "FL0034", "Madrid", 180, 520.00);
    printf("Inserted 4 flights\n\n");
    
    // Display initial table
    printf("Initial table:\n");
    for (int i = 0; i < 11; i++) {
        if (ht->table[i].status == OCCUPIED) {
            printf("Index %2d: %s -> %s\n", i, 
                   ht->table[i].flightCode, ht->table[i].destination);
        }
    }
    printf("\n");
    
    // Delete a flight in the middle of probe sequence
    printf("Deleting FL0012...\n");
    int delResult = deleteFlight(ht, "FL0012");
    printf("Delete result: %s\n\n", delResult ? "Success" : "Failed");
    
    // Display table after deletion
    printf("Table after deletion:\n");
    for (int i = 0; i < 11; i++) {
        if (ht->table[i].status == OCCUPIED) {
            printf("Index %2d: %s -> %s\n", i,
                   ht->table[i].flightCode, ht->table[i].destination);
        } else if (ht->table[i].status == DELETED) {
            printf("Index %2d: [DELETED]\n", i);
        }
    }
    printf("\n");
    
    // Search for flight after the deleted one
    printf("Searching for FL0023 (should pass through DELETED slot)...\n");
    Flight* flight = searchFlight(ht, "FL0023");
    if (flight != NULL) {
        printf("Found: %s -> %s (correct - search continued through DELETED)\n\n",
               flight->flightCode, flight->destination);
    }
    
    // Verify deleted flight is not found
    printf("Searching for deleted flight FL0012...\n");
    flight = searchFlight(ht, "FL0012");
    printf("Result: %s\n\n", flight == NULL ? "Not found (correct)" : "Found (error)");
    
    // Insert new flight - should reuse DELETED slot
    printf("Inserting new flight FL9999...\n");
    insertFlight(ht, "FL9999", "Athens", 190, 540.00);
    
    printf("\nTable after new insertion:\n");
    for (int i = 0; i < 11; i++) {
        if (ht->table[i].status == OCCUPIED) {
            printf("Index %2d: %s -> %s\n", i,
                   ht->table[i].flightCode, ht->table[i].destination);
        } else if (ht->table[i].status == DELETED) {
            printf("Index %2d: [DELETED]\n", i);
        }
    }
    
    printf("\nTable statistics:\n");
    printf("Occupied: %d, Deleted: %d, Load factor: %.2f\n",
           ht->occupiedCount, ht->deletedCount,
           (float)ht->occupiedCount / ht->size);
    
    return 0;
}
