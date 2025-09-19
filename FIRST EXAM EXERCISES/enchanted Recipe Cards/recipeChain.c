#include <stdio.h>
#include <stdbool.h>
#include "stackLL.h"

void reverseChain(Stack** s);
int main (){
    Stack* s = (Stack*) malloc (sizeof(Stack));

    initStack(s);


    push(s, 'A');
    push(s, 'B');
    push(s, 'C');

    display(s);
    printf("\n");
    printf("After reversal\n");
    reverseChain(&s);
    display(s);
    return 0;
}

void reverseChain(Stack** s){
    Stack* reverse = (Stack*) malloc (sizeof(Stack));
    initStack(reverse);

    for (; !isEmpty(*s); pop(*s)){
        push(reverse, peek(*s));
    }
    free(*s);
    *s = reverse;
}