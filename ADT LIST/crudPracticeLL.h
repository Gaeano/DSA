#include <stdio.h>
#include <stdlib.h>
#ifndef crudPracticeLL_H
#define crudPracticeLL_H
#include "studtype.h"

typedef struct node{
    StudPtr data;
    struct node* next;
}Node;

typedef struct {
    Node *head;
    int count;
}ListLL;

ListLL * initialize (){
    ListLL* l = (ListLL*) malloc (sizeof(ListLL));
    if (l == NULL){
        printf("oh no memory alloc failed");
    } else {
        l->head = NULL;
        l->count = 0;
    }

    return l;
}

void empty(ListLL * l){
    Node* temp;
    while (l->head != NULL){
        temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}


void insertFirst(ListLL* l, StudPtr data){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (newNode == NULL){
        printf("memory alloc failed");
    } else {
        newNode->data = data;
        newNode->next = l->head;
        l->head = newNode;
        l->count++;
    }
}

void insertLast(ListLL* l, StudPtr data){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (newNode == NULL){
        printf("memory alloc failed");
    } else {
        newNode->data = data;
        newNode->next = NULL;
       if (l->head == NULL){
        l->head = newNode; // list empty
        l->count++;
       } else {
        Node* cur;
        for (cur = l->head; cur->next != NULL; cur = cur->next){}
        
        cur->next = newNode;
        l->count++;
       }
    }
}

void insertPosLL(ListLL *l, StudPtr data, int index){
    if (index  > l->count){
        printf("index invalid!");
    } else if (index == 0){
        insertFirst(l, data);
    } else if (index == l->count){
        insertLast(l, data);
    } else {
        Node* newNode = (Node*) malloc (sizeof(Node));
        if (newNode == NULL){
            printf("memory alloc failed");
        } else{
            newNode->data = data;
            Node* cur;
            int ite = 0;
            for (cur = l->head; cur->next != NULL && ite < index - 1; cur = cur->next){
                ite++;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            l->count++;
        }
    }
}

void deleteStart(ListLL * l){
    if(l->head == NULL){
        printf("linked list empty");
    } else {
        Node* cur = l->head;
        l->head = cur->next;
        free(cur);
        l->count--;
        printf("first node successfully deleted...\n");
    }
    
}

void deleteLast(ListLL* l){
    if (l->head == NULL){
        printf("linked list empty");
    } else {

        if (l->head->next == NULL){
            free(l->head);
            l->head = NULL;
        } else {
            Node* cur;
            for (cur = l->head; cur->next->next != NULL; cur = cur->next){}
            free(cur->next);
            cur->next = NULL;
            printf("last node successfully deleted...\n");
        }
        
        l->count--;
    }
}

void deletePosLL(ListLL *l, int index){

    if (index < 0 || index >= l->count){
        printf("invalid position\n\n");
    } else {
        if (index == 0){
            deleteStart(l);
        } else if (index == l->count - 1){
            deleteLast(l);
        } else {
            Node* cur;
            int ite;
            for (ite = 0; ite < index - 1; ite++){
                cur = cur->next;
            }
            Node* temp = cur->next;

            cur->next = temp->next;

            free(temp);
            l->count--;
            printf("node successfully deleted at position %d...\n\n", index);

    }
    }

   
}

StudPtr retrieve(ListLL* l, int index){
    if (index > l->count){
        printf("invalid index");
    } else {
        Node* cur;
        int ite = 0;
        for (cur = l->head; cur->next != NULL && ite <= index; cur = cur->next){
            ite++;
        }

        return cur->data;
    }
}

int locateLL(ListLL *l, StudPtr data){
    Node* temp;
    int pos = 1;
    int i = 0;
    int retval = -1;
    for(temp = l->head; temp != NULL && data != temp->data; temp = temp->next){
        i++;
    }

        if (temp != NULL){
            retval = i;
        } else {
            printf("data not found");
        }
        
        return retval;
}



void displayLL(ListLL* l) {
    Node* temp;
    printf("%-15s %-15s %-10s %-5s %-5s\n", "First Name", "Last Name", "Course", "Yr", "ID");
        printf("-------------------------------------------------------\n");
    for (temp = l->head; temp != NULL; temp = temp->next) {
        printf("%-15s %-15s %-10s %-5d %-5d\n",
                    temp->data->name.FName,
                    temp->data->name.LName,
                    temp->data->course,
                    temp->data->age,
                    temp->data->id);
    }
}



#endif