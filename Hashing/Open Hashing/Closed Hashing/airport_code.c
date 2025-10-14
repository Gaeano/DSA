#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 20

typedef int List;

typedef struct{
    char code[4];
    int next;
}heap;


typedef struct{
    heap H[max];
    int avail;
}VHeap;

int hash(char *code);
VHeap* initialize(VHeap * dictionary);
int allocSpace(VHeap* dictionary);
void dealloc(VHeap* dictionary, int index);
void insertCode(VHeap* dictionary, char* code);
void displaySet(VHeap *dictionary);

VHeap* initialize(VHeap * dictionary){
    int primaryStorage = max / 2;
    int i;
    for (i = 0; i < primaryStorage; i++){
        strcpy(dictionary->H[i].code, "");
        dictionary->H[i].next = -1;
    }

    for (i = primaryStorage; i < max; i++){
        dictionary->H[i].next = i+1;
    }

    dictionary->avail = primaryStorage;

    return dictionary;
}


int hash(char *code){
    return ((code[0] - 'A') * 26 * 26 + (code[1] - 'A') * 26 + (code[2] - 'A')) % 10;
}

int allocSpace(VHeap* dictionary){
    int retVal = dictionary->avail;
    if (dictionary->avail != -1){
        dictionary->avail = dictionary->H[retVal].next;
    }
    return retVal;
}

void dealloc(VHeap* dictionary, int index){
    if (index != -1 && index < max){
        dictionary->H[index].next = dictionary->avail;
        dictionary->avail = index;
    }
}

void insertCode(VHeap* dictionary, char* code){
    List hashCode = hash(code);
    List* trav;
  
    if (strcmp(dictionary->H[hashCode].code, "") == 0){ //empty
        strcpy(dictionary->H[hashCode].code, code); //put code in the elem
        printf("Inserted %s to primary storage\n", code);
    } else { //if elem is already occupied
        int newIndex = allocSpace(dictionary); 
        if (newIndex != -1){
            dictionary->H[hashCode].next = newIndex;
            strcpy(dictionary->H[newIndex].code, code);
            dictionary->H[newIndex].next = -1;
            printf("Inserted %s to secondary storage\n", code);
        }
        
    }
}

void displaySet(VHeap *dictionary){

    int primaryStorage = max / 2;
    printf("\n--- Hash Table Contents ---\n");
    for (int i = 0; i < primaryStorage; i++) {
        printf("[%d] %s", i, dictionary->H[i].code);
        int trav = dictionary->H[i].next;
        while (trav != -1) {
            printf(" -> %s", dictionary->H[trav].code);
            trav = dictionary->H[trav].next;
        }
        printf("\n");
    }



}

int main (){
    VHeap* dictionary = malloc (sizeof(VHeap));
    if (dictionary == NULL){
        printf("memory alloc failed\n");
    }
    VHeap* set = malloc (sizeof(VHeap));

    initialize(dictionary);

    char* codes[] = {"JFK", "LAX", "SFO", "CDG", "LHR", "NRT", "ATL", "DXB", "PEK", "MIA", "SYD", "ORD"};
    int numCodes = sizeof(codes) / sizeof(codes[0]);


   
    int i;
    for (i = 0; i < numCodes; i++){
        insertCode(dictionary, codes[i]);
    }
    displaySet(dictionary);

    free(dictionary);
    
    return 0;
}