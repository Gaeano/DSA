#ifndef arrayStack_H
#define arrayStacl_H
#include <stdio.h>
#include <stdbool.h>
#include "container.h"
#define MAX 5
typedef struct{
    containerPtr container[MAX];
    int top;
}Stack;


void initialize(Stack *s){
    s->top = -1;
}

bool isFull(Stack *s){
    return s->top == MAX -1;
}

bool isEmpty(Stack* s){
    return s->top == -1;
}

void push (Stack* s, containerPtr value){
    if(!isFull(s)){
        s->top++;
        s->container[s->top] = value;
    }
}

int peek(Stack* s){
    return s->container[s->top]->ID;
}

int pop(Stack* s){
    if (!isEmpty(s)){
        int data = peek(s);
        s->top--;
        return data;
    }
}


void display(Stack *s){
    Stack temp;

    
    for (temp = *s; !isEmpty(&temp); pop(&temp)){
        printf("ContainerID: %d ContainerName = %s\n", temp.container[temp.top]->ID, temp.container[temp.top]->containerName);
    }
}



#endif