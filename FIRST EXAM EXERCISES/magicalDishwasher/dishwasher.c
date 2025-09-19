#include <stdio.h>
#include <stdlib.h>
#include "arrayStack.h"

void sortPlates(Stack* s);

int main (){
    Stack dirty;

    initStack(&dirty);

    push(&dirty, 2);
    push(&dirty, 1);
    push(&dirty, 9);
    push(&dirty, 3);
    push(&dirty, 6);

    display(&dirty);
    sortPlates(&dirty);

    display(&dirty);
    return 0;

}

void sortPlates(Stack* s){
    Stack clean;    

    while (!isEmpty(s)){
        int data = peek(s);
        pop(s);

        while (!isEmpty(&clean) && peek(&clean) < data){
            push(s, peek(&clean));
            pop(&clean);
        }
        push(&clean, data);
    }
    while (!isEmpty(&clean)){
        push(s, peek(&clean));
        pop(&clean);
    }

   
}
