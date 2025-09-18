#ifndef arrayStack_H
#define arrayStacl_H
#include <stdio.h>
#include <stdbool.h>
#define MAX 5
typedef struct{
    int container[MAX];
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

void push (Stack* s, int value){
    if(!isFull(s)){
        s->top++;
        s->container[s->top] = value;
    }
}

int peek(Stack* s){
    return s->container[s->top];
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
        printf("Container: %d\n", temp.container[temp.top]);
    }
}



#endif