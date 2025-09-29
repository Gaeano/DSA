/*create a c program that inserts, deletes and searches the RGB value in an open hashing dictionary
a. the hash function accepts an RGB vlaue and returns a digit constrained in a 64 pallete 
b. given this structure, formulate this into an open hasing dictionary */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 64

typedef struct {
    char * colorName;
    int RGBval[3]; //index 0 red, 1, green, 2 blue 
}Color;

typedef struct node{
    Color color;
    struct node* next;
}Node;

//size of array is 64
void initDictionary (Node** dic);
void insert(Node** dictio, Color insertCol);
Node* createNewNode(Color color);
void delete(Node** dictio, Color color);
void search(Node** dictio, int val);
int hash(Color color);
bool isEqual(Node* dictio, Color color);

void initDictionary (Node** dic){
    int i;

    for (i = 0; i < MAX_SIZE; i++){
        dic[i] = NULL;
    }
}

Node* createNewNode(Color color){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (newNode == NULL){
        printf("memory alloc failed\n");
        exit(1);
    }
    newNode->color = color;
    newNode->next = NULL;

    return newNode;
}

int hash(Color color){
    return (color.RGBval[0] + color.RGBval[1] + color.RGBval[2]) % 64;
}



void insert(Node** dictio, Color insertCol){
    Node* newNode = createNewNode(insertCol);

    int index = hash(insertCol);

    int i;

    if (dictio[index] == NULL){
        dictio[index] = newNode; //insert to da head;
    } else { 
        Node* temp;
        for (temp = dictio[index]; temp->next != NULL; temp = temp->next){ //insert to the tail
        }
        temp->next = newNode;
    }

}

bool isEqual(Node* dictio, Color color){
    return (strcmp(dictio->color.colorName, color.colorName) == 0);
}
void delete(Node** dictio, Color color){
    int index = hash(color); //get the index of the color to del
    if (dictio[index] == NULL){
        printf("Color %s not found\n", color.colorName);
    } else {
        if (isEqual(dictio[index], color)){
        Node* del = dictio[index];
        dictio[index] = dictio[index]->next;
        free(del);
        } else {
            Node* temp;
            Node* prev = NULL;
            for (temp = dictio[index]; temp != NULL && !isEqual(temp, color); temp = temp->next){
                prev = temp;
            } //traverse until it finds a match
            Node* del = temp;
            prev->next = temp->next;
            free(del);
        }
    }

    
}

int main (){
    Node* dictionary[MAX_SIZE]; 
    initDictionary(dictionary);
    Color color[5] = {{"red", {0,4,7}}, 
                    {"blue", {4, 8 ,10}},
                {"gaea", {0,0,0}}};   

    int i;
    for (i = 0; i < 3; i++){
        insert(dictionary, color[i]);
    }
    Color chain = {"chain", {0,4,7}};
    insert(dictionary, chain);
    Color del = {"red", {0,4,7}};

    delete(dictionary, del);

    for (i = 0 ; i < MAX_SIZE; i++){ //display
        if (dictionary[i] == NULL){ //its empty displayt null
            printf("NULL\n");
        } else { //linked list not empty display the chain
            Node* temp;
            for (temp = dictionary[i]; temp != NULL; temp = temp->next){
                printf("%s -> ", temp->color.colorName);
            }
            printf("NULL\n");
        }
    }
    
}

