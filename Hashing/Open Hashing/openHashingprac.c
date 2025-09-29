/*create a c program that inserts, deletes and searches the RGB value in an open hashing dictionary
a. the hash function accepts an RGB vlaue and returns a digit constrained in a 64 pallete 
b. given this structure, formulate this into an open hasing dictionary */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * colorName;
    int RGBval[3]; //index 0 red, 1, green, 2 blue 
}Color;

typedef struct node{
    Color color;
    struct node* next;
}Dictionary;

//size of array is 64
Dictionary* initDictionary (Dictionary* dic);
void insert(Dictionary** dictio, Color insertCol);
void delete(Dictionary** dictio, int val);
void search(Dictionary** dictio, int val);
int hash(Color color);

Dictionary* initDictionary (Dictionary* dic){
    dic = (Dictionary*) malloc  (sizeof(Dictionary));
}

int hash(Color color){
    return (color.RGBval[0] + color.RGBval[1] + color.RGBval[2]) % 64;
}

void insert(Dictionary** dictio, Color insertCol){
    int insertVal = hash(insertCol);
    int i;
    for (i = 0; i <= insertVal; i++){
        if (dictio[i] == NULL){
            dictio[i]->color = insertCol;
        } else {
            Dictionary* temp;
            Dictionary* prev = NULL;
            for (temp = dictio; temp != NULL; temp = temp->next){
                prev = temp;
            }
            prev->next->color = insertCol;
            
            
        }
    }


}





