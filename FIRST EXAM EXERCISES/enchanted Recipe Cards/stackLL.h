#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef stackLL_H
#define stackLL_H

typedef struct node{
    char card;
    struct node* next;
}Node;

typedef struct{
    Node* head;
    int size;
}Stack;

void initStack(Stack* s);
bool isEmpty(Stack *s);
void push(Stack* s, char data);
void pop(Stack* s);
char peek(Stack* s);
void display(Stack* s);
Node* createNode(char data);

Node* createNode(char data){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (newNode == NULL){
        printf("memory alloc failed");
        exit(1);
    }

    newNode->card = data;
    newNode->next = NULL;
    
    return newNode;
}
void initStack(Stack* s){
    s->head = NULL;
    s->size = 0;
}

bool isEmpty(Stack *s){
    return s->size == 0;
}
void push(Stack* s, char data){
    Node *newNode = createNode(data);
    if (s->head == NULL){
        s->head = newNode;
        s->size++;
    } else {
        newNode->next = s->head;
        s->head = newNode;
        s->size++;
    }
    
}

void pop(Stack* s){
    if (!isEmpty(s)){
        Node* temp = s->head;
        s->head = temp->next;
        // free(temp); so no complicationz
        s->size--;
    }
}

char peek(Stack* s){
    return s->head->card;
}

void display(Stack* s){
    Stack tempStack = *s;
    Node temp ;
    int i = 0;
    for (tempStack = *s; !isEmpty(&tempStack); pop(&tempStack)){
        printf("Card %c ", peek(&tempStack));
        if (i < s->size - 1){
            printf("-> ");
        }
        i++;
    }
}


#endif