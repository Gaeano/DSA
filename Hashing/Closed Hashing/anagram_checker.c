#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EMPTY '~'
#define DELETED '!'
#define MAX 211

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct {
    char elem;
    int frequency;
} Element;

typedef Element Dictionary[MAX];

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);
int hash(char elem);

/*********************************/
/*          YOUR TASKS           */
/*********************************/

void insert(Dictionary D, char elem);
void delete(Dictionary D, char elem);
bool isMember(Dictionary D, char elem);
bool isAnagram(char* s, char* t);

int main(void) {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    if (isAnagram(s1, s2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", s1, s2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", s1, s2);
    }

    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i].elem = EMPTY;
        D[i].frequency = 0;
    }
}

int hash(char elem) {
    return ((int)elem) % MAX;
}

/*********************************/
/*          YOUR TASKS           */
/*********************************/


void insert(Dictionary D, char elem) {
    // TODO: Implement insert with linear probing
    int hashCode = hash(elem);
    

    int i;
    int success = 0;
    for (i = 0; i < MAX && success == 0; i++){
        int newHashCode = (hashCode + i) % MAX;

        if (D[newHashCode].elem == EMPTY){
            D[newHashCode].elem = elem;
            D[newHashCode].frequency++;
            success = 1;
        }
    }
}

void delete(Dictionary D, char elem) {
    // TODO: Implement delete with linear probing
    int hashCode = hash(elem);
    int i;
    int success = 0;
    for (i = 0; i < MAX & success == 0; i++){
         int newHashCode = (hashCode + i) % MAX;

         if (D[newHashCode].elem != EMPTY){
            D[newHashCode].elem = DELETED;
            D[newHashCode].frequency--;

            success = 1;
         }
    }
    
}

bool isMember(Dictionary D, char elem) {
    // TODO: Implement membership check
    int hashCode = hash (elem);

    int i;
    int success = 0;
    for (i = 0; i < MAX && success == 0; i++){
        int newHashCode = (hashCode + i) % MAX;

        if (D[newHashCode].elem != EMPTY && D[newHashCode].elem == elem){
            success = 1;
        }
    }

    return (success == 1) ? true : false;
    
}

bool isAnagram(char* s, char* t) {
    // TODO: Implement anagram checker
    int c[256] = {0}; 

    int anagram = 0;
    if (strlen(s) == strlen(t)){
        anagram = 1;
    }

    int i = 0;
    while (s[i]){
        c[s[i]]++;
        c[t[i]]--;
        i++;
    }   

    for (i = 0; i < MAX; i++){
        if (c[i] != 0){
            anagram = 0;
        }
    }

    return (anagram == 1) ? true : false;

    
}