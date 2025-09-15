#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10
typedef struct stack{
    char letter[MAX];
    int top;
}stack;



void unique (stack* s, char data);
void push(stack *s, char data);
void pop(stack* s);
int top (stack *s);
bool isEmpty(stack *s);
bool isFull(stack *s);
void initialize (stack * s);

int main (){
    stack * s  =(stack*) malloc (sizeof(stack));

    initialize(s);

    push(s, 'A');
    push(s, 'C');
    push(s, 'F');
    char data = 'G';

    unique(s, data);
    
    while(!isEmpty(s)){
        char data = top(s);
        printf("%c\n", data);
        pop(s);
    }

    free(s);
    return 0;

}
void initialize (stack * s){
    s->top = -1;
}
bool isEmpty(stack* s){
    return s->top == -1;
}

bool isFull(stack* s){
    return s->top == MAX - 1;
}


void push(stack *s, char data){
    if (isFull(s)){
        printf("stack full");
    } else {
        s->top++;
        s->letter[s->top] = data;
    }
}

void pop(stack* s){
    if(isEmpty(s)){
        printf("stack is empty!");
    } else {
        s->top--;
    }
}


int top(stack * s){
    if(isEmpty(s)){
        printf("stack empty");
        return -1;
    } else {
        return s->letter[s->top];
    }
}

void unique (stack* s, char data){
    if (!isEmpty(s)){
        int found = 0;
        stack temp = *s;

        while(!isEmpty(&temp)){
            char current = top(&temp);
            if (current == data){
                found = 1;
            }
            pop(&temp);
        }

        if (found == 1) {
        printf("can't add %c, it already exists in the stack\n", data);
        } else {
        push (s, data);
        printf("%c successfully added!\n", data);
        }
    } 
    
}

