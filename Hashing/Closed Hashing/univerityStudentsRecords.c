#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student {
    int studentID;
    char name[50];
    float gpa;
    char major[30];
    struct Student* next;  // For chaining
} Student;

typedef struct HashTable {
    Student** table;  // Array of pointers to Student
    int size;
    int count;
} HashTable;


HashTable* createHashTable(int size);
int hashFunction(int studentID, int tableSize);
void insertStudent(HashTable* ht, int id, char* name, float gpa, char* major);
Student* searchStudent(HashTable* ht, int studentID);
void deleteStudent(HashTable* ht, int studentID);
void displayChain(HashTable* ht, int index);
float calculateLoadFactor(HashTable* ht);
void displayStatistics(HashTable* ht);

HashTable* createHashTable(int size){
    HashTable * ht= malloc (sizeof(HashTable));
    
    ht->size = size;
    ht->count = 0;
    ht->table = (Student**) malloc (size * sizeof(Student*));
    int i;
    for (i = 0; i < size; i++){
        ht->table[i] = NULL;
    }
    return ht;
}

int hashFunction(int studentID, int tableSize){
    return studentID % tableSize;
}

void insertStudent(HashTable* ht, int id, char* name, float gpa, char* major){
    int hashCode = hashFunction(id, ht->size);
     //create new student
        Student* newStudent = malloc(sizeof(Student));
        newStudent->gpa = gpa;
        newStudent->studentID = id;
        strcpy(newStudent->name , name);
        strcpy(newStudent->major, major);
        newStudent->next = NULL;
        //end of create newStudent

    if (ht->table[hashCode] == NULL){ 
        ht->table[hashCode] = newStudent;
        ht->count++;

    } else {
        Student* trav;

        for (trav = ht->table[hashCode]; trav->next != NULL; trav = trav->next){

        }
        trav->next = newStudent;
        ht->count++;
    }
}

Student* searchStudent(HashTable* ht, int studentID){
    int hashCode =  hashFunction(studentID, ht->size);

    if (ht->table[hashCode] != NULL && ht->table[hashCode]->studentID == studentID){
        return ht->table[hashCode];
    } else {
        Student* trav;

        for (trav = ht->table[hashCode]; trav != NULL  && trav->studentID != studentID; trav = trav->next){}

        if (trav != NULL){
            return trav;
        }
    }
    
}

void deleteStudent(HashTable* ht, int studentID){
    int hashCode = hashFunction(studentID, ht->size);

    if (ht->table[hashCode] != NULL && ht->table[hashCode]->studentID == studentID){
        Student* temp;
        temp = ht->table[hashCode];
        ht->table[hashCode] = temp->next;
        free(temp);
        ht->count--;
    } else {
        Student * trav;
        Student* prev = NULL;
        for (trav = ht->table[hashCode]; trav != NULL && trav->studentID != studentID; trav = trav->next){
            prev = trav;
        }

        if (trav != NULL){
            prev->next = trav->next;
            free(trav);
        } 
    }
}

void displayChain(HashTable* ht, int index){
    Student* trav;

    for (trav = ht->table[index]; trav != NULL; trav = trav->next){
        printf("-> ID: %d, Name: %s, GPA = %.2f, Major= %s\n", trav->studentID, trav->name, trav->gpa, trav->major);
    }


}

float calculateLoadFactor(HashTable* ht){
    return (float)ht->count / ht->size;
}

void displayStatistics(HashTable* ht){
    Student* trav;
    int longestChain = 0;
    int chainLength;
    int i;
    for (i = 0; i < ht->size; i++){
        if (ht->table[i] != NULL){
            chainLength = 0;
            for (trav = ht->table[i]; trav != NULL; trav = trav->next){
                chainLength++;
            }

            if (chainLength > longestChain){
                longestChain = chainLength;
            }
        }
        
    }

    printf("Total students: %d\n", ht->count);
    printf("Table size: %d\n", ht->size);
    float loadFactor = calculateLoadFactor(ht);
    printf("Load factor: %.2f\n", loadFactor);
    printf("Empty slots: %d\n", ht->size-ht->count);
    printf("Longest chain: %d\n", longestChain);
    printf("Average chain length: %.2f\n", loadFactor);
}
int main() {
    printf("=== Test Case 1.2: Collision Handling ===\n\n");
    
    HashTable* ht = createHashTable(7);
    printf("Created hash table with size: 7\n\n");
    
    // Insert students that will collide (all should hash to same index)
    // Assuming IDs that differ by table size hash to same location
    printf("Inserting students with IDs that will collide...\n");
    insertStudent(ht, 1001, "Alice Johnson", 3.8, "Computer Science");
    printf("Inserted: ID=1001 (hash=%d)\n", 1001 % 7);
    
    insertStudent(ht, 1008, "Bob Smith", 3.5, "Mathematics");
    printf("Inserted: ID=1008 (hash=%d)\n", 1008 % 7);
    
    insertStudent(ht, 1015, "Carol White", 3.9, "Physics");
    printf("Inserted: ID=1015 (hash=%d)\n", 1015 % 7);
    
    insertStudent(ht, 1022, "David Brown", 3.7, "Chemistry");
    printf("Inserted: ID=1022 (hash=%d)\n\n", 1022 % 7);
    
    // Display the chain at index where they collided
    int collisionIndex = 1001 % 7;
    printf("Displaying chain at index %d:\n", collisionIndex);
    displayChain(ht, collisionIndex);
    printf("\n");
    
    // Search for students in the chain
    printf("Searching for students in collision chain...\n");
    Student* result = searchStudent(ht, 1008);
    if (result != NULL) {
        printf("Found: ID=%d, Name=%s\n", result->studentID, result->name);
    }
    
    result = searchStudent(ht, 1015);
    if (result != NULL) {
        printf("Found: ID=%d, Name=%s\n", result->studentID, result->name);
    }
    
    result = searchStudent(ht, 1022);
    if (result != NULL) {
        printf("Found: ID=%d, Name=%s\n\n", result->studentID, result->name);
    }
    
    // Display statistics
    printf("Table Statistics:\n");
    displayStatistics(ht);
    
    return 0;
}

