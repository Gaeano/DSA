#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "arrayQueue.h"

void sortScroll(Queue* q, Queue* scroll);

int main (){
    /* remainder 0 = q[0]
        remainder 1 = q[1]
        remainder 2 = q[2]
    */
   //initialize the 3 chambers
   Queue q[3];
    int i;
   for (i = 0; i < 3; i++){
        initQueue(&q[i]);
   }

   //given scrolllllll
   Queue scroll;
   initQueue(&scroll);

   enqueue(&scroll, 7);
   enqueue(&scroll, 12);
   enqueue(&scroll, 8);
   enqueue(&scroll, 15);
   enqueue(&scroll, 4);
   enqueue(&scroll, 9);
   
   sortScroll(q, &scroll);
   
   for (i = 0 ; i < 3; i++){
    switch(i){
        case 0:
        printf("Chamber of Divine Remainder Zero\n");
        displayQueue(&q[i]);
        break;
        case 1:
        printf("Chamber of Unity Remainder \n");
        displayQueue(&q[i]);
        break;
        case 2:
        printf("Chamber of Duality Remainder \n");
        displayQueue(&q[i]);
        break;
        default:
        printf("wala naa");
    }
    
   }
}


void sortScroll(Queue* q, Queue* scroll){
   
    for (; !isEmpty(scroll); dequeue(scroll)){
        if (front(scroll) % 3 == 0){
            enqueue(&q[0], front(scroll));
        } else if (front(scroll) % 3 == 1){
            enqueue(&q[1], front(scroll));
        } else if (front(scroll) % 3 == 2){
            enqueue(&q[2], front(scroll));
        }
    }
}

