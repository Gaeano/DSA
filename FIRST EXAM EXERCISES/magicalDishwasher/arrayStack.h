#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef arrayStack_H
#define arrayStack_H

#define MAX 10
typedef struct{
    int arr[MAX];
    int top;
    int count;
}Stack;


void initStack(Stack* s);
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack* s, int plate);
void pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);



void initStack(Stack* s){
    s->top = -1;
    s->count = 0;
}

bool isEmpty(Stack* s){
    return s->top == -1;
}

bool isFull(Stack* s){
    return s->top == MAX - 1;
}

void push(Stack* s, int plate){
    if (!isFull(s)){
        s->top++;
        s->arr[s->top] = plate;
        s->count++;
    }
}

void pop(Stack* s){
    if (!isEmpty(s)){
        s->top--;
        s->count--;
    }
}

int peek(Stack* s){
    return s->arr[s->top];
}

void display(Stack* s){
    Stack temp;
    printf("Plates:\n");
    for(temp = *s; !isEmpty(&temp); pop(&temp)){
        
        printf("%d\n", temp.arr[temp.top]);
    }
}


#endif