//three stacks
//has a container inside

#include <stdio.h>
#include "arrayStack.h"
#define MAXSTAk 3
void addContainer(Stack* s, int data);
void removeContainer(Stack* s);
void findContainer(Stack* s, int find);

void removeContainer(Stack* s){
    int i;

    for (i = 0; i < MAXSTAk && isFull(&s[i]); i++){

    }

    if (i > MAXSTAk){
        
    }

    int data = peek(&s[i]);
    pop(&s[i]);

    printf("Container with data %d successfully removed", data);

}

// Write the code for adding a container to the next available stack
void addContainer(Stack* s, int data){
    int i;
    
    for (i = 0 ; i < MAXSTAk && isFull(&s[i]); i++){
    }

    if (i <= MAXSTAk - 1){ //not full
        push(&s[i], data);
    } else {
        printf("all three stacks are full!\n");
    }
}

void findContainer(Stack* s, int find){
    int i = 0;
    Stack temp;
    int data;
    temp = s[i];
    for (; i < MAXSTAk && data != find; i++){
        data = peek(&temp);
        data != find;
    }

    if (i == MAXSTAk - 1){
        printf("container not found huhu\n");
    } else {

    }
}

int main (){
    Stack s[MAXSTAk];
    int i;
    for (i = 0; i < MAXSTAk; i++){
        initialize(&s[i]);
    }

    addContainer(s, 1);
    addContainer(s, 2);
    addContainer(s, 3);
    addContainer(s, 4);
    addContainer(s, 5);
    printf("Stack 1\n");
    display(&s[0]);

    addContainer(s, 6);
    addContainer(s, 7);
    addContainer(s, 8);
    addContainer(s, 9);
    addContainer(s, 10);
    printf("Stack 2\n");
    // addContainer(&s[1], 11);
    display(&s[1]);

    printf("Stack 3\n");

    addContainer(s, 11);
    addContainer(s, 12);
    addContainer(s, 13);
    addContainer(s, 14);
    addContainer(s, 15);
    display(&s[2]);
    
    removeContainer(&s[0]);
    display(&s[0]);


    // Write the code for checking if a container exists
}


