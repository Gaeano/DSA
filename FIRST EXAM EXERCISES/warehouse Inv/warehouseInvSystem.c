//three stacks
//has a container inside

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayStack.h"
#include "container.h"
#define MAXSTAk 3
void addContainer(Stack* s, containerPtr data);
void removeContainer(Stack* s);
void findContainer(Stack* s, int find);

void removeContainer(Stack* s){
    int i;

    for (i = MAXSTAk - 1; i > 0 && isEmpty(&s[i]); i--){

    }

    if (i > MAXSTAk){
        printf("all stacks are full!!");
    }

    containerPtr data;
    data->ID = peek(&s[i]);
    pop(&s[i]);

    printf("Container with data %d successfully removed from stack: %d\n", data->ID, i+1);

}

// Write the code for adding a container to the next available stack
void addContainer(Stack* s, containerPtr data){
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
    int i;
    Stack temp;
    containerPtr data;

    int flag = 0;
    while(i < MAXSTAk && flag == 0){
        temp = s[i];
        data->ID = peek(&temp);
        if (data->ID == find){
            flag = 1;
        }
        i++;
    }

    if (i == MAXSTAk - 1){
        printf("container not found huhu\n");
    } else {
        printf("container id %d exists in stack: %d\n",find, i);
    }
}

int main (){
    Stack s[MAXSTAk];
    int i;
    for (i = 0; i < MAXSTAk; i++){
        initialize(&s[i]);
    }

    containerPtr cont1 = (containerPtr) malloc (sizeof(Container));
    if (cont1 == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    containerPtr cont2 = (containerPtr) malloc (sizeof(Container));
    if (cont2 == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    containerPtr cont3 = (containerPtr) malloc (sizeof(Container));
    if (cont3 == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    containerPtr cont4 = (containerPtr) malloc (sizeof(Container));
    if (cont4 == NULL){
        printf("memory alloc failed");
        exit(1);
    }

    containerPtr cont5 = (containerPtr) malloc (sizeof(Container));
    if (cont5 == NULL){
        printf("memory alloc failed");
        exit(1);
    }

    containerPtr cont6 = (containerPtr) malloc (sizeof(Container));
    if (cont6 == NULL){
        printf("memory alloc failed");
        exit(1);
    }

    //populate studs
    strcpy(cont1->containerName, "Nicole");
    cont1->ID = 1;
    
    strcpy(cont2->containerName, "Lukas");
    cont2->ID = 2;

    strcpy(cont3->containerName, "Antoinette");
    cont3->ID = 3;
    
    strcpy(cont4->containerName, "Jules");
    cont4->ID = 4;
    
    strcpy(cont4->containerName, "Sofia ");
    cont4->ID = 5;


    strcpy(cont5->containerName, "Alicia ");
    cont5->ID = 6;


    addContainer(s, cont1);
    addContainer(s, cont2);
    addContainer(s, cont3);
    addContainer(s, cont4);
    addContainer(s, cont5);
    printf("Stack 1\n");
    display(&s[0]);

    addContainer(s, cont2);
    addContainer(s, cont5);
    addContainer(s, cont3);
    addContainer(s, cont4);
    addContainer(s, cont1);
    printf("Stack 2\n");
    // addContainer(&s[1], 11);
    display(&s[1]);

    printf("Stack 3\n");

    addContainer(s, cont5);
    addContainer(s, cont4);
    addContainer(s, cont3);
    addContainer(s, cont2);
    addContainer(s, cont1);
    printf("Stack 1\n");
    display(&s[2]);
    
    findContainer(s, 12);
    printf("\n");
    removeContainer(s); //problem is in this function
    

    for (i = 0; i < MAXSTAk; i++){
        printf("Stack: %d\n", i+1);
        display(&s[i]);
        printf("\n");
    }
    

    // Write the code for checking if a container exists
}


