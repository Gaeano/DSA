#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arrayQueue.h"

int main (){
    Queue* line = initialize();
    Queue* priority = initialize();

    int choice;
    int number = 1;
    int prio = 1;
    int i = 0;
    while (1){
        printf("1. Regular\n2. Priority\n3.Display Line\nChoice: ");
        scanf("%d", &choice);

         if (choice == -1){
            break;
        }

        switch (choice){
            case 1:
            enqueue(line, number);
            printf("Added to regular lane, Your number is: %d\n", number);
            number++;
            break;

            case 2:
            enqueue(priority, prio);
            printf("Added to priority lane, Your number is: %d\n", prio);
            prio++;
            break;

            case 3:
            printf("\nPriority Line\n");
            display(priority);
            printf("\nRegular Line:\n");
            display(line);
            break;
            
            default:
            printf("wrong choice\n");
        }
        
       
    }   
    //call numbr
    while (1){
        int callChoice;
        printf("call next customer?:\n1: yes\n2: no\nchoice: ");
        scanf("%d", &callChoice);

        if(callChoice == 2){
            break;
        }

        if (isEmpty(line) && isEmpty(priority)){
            printf("both queues are empty!\n");
            break;
        }
        printf("------------------------------------------\n");
        if (!isEmpty(priority)){
            printf("PRIORITY LINE\n");

            int data = front(priority);
            printf("Calling customer: %d\n", data);
            dequeue(priority);
            printf("------------------------------------------\n");

        } else {
            if(!isEmpty(line)){
                printf("REGULAR LINE\n");
                int data = front(line);
                printf("Calling customer: %d\n", data);
                dequeue(line);
            printf("------------------------------------------\n");
            }
        }
        

      
    }
    

    free(line);
    free(priority);
    return 0;

}