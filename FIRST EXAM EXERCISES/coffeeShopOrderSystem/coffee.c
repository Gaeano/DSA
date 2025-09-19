#include <stdio.h>
#include <stdbool.h>
#include "queueArray.h"

int main (){
    Queue q;

    initQueue(&q);

    while (1){
        int choice;
        printf("1. Order\n2.Serve\n3. Serve all orders\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 4){
            break;
        }

        switch(choice){
            case 1:
            int item;
            printf("Enter item for customer: ");
            scanf("%d", &item);
            enqueue(&q, item);
            break;
            case 2:
            dequeue(&q);
            break;
            
            case 3:
            display(&q);
            break;
            default:
            printf("wrong choice mam\npiliin mo ko habang buhay pls\n");
        }
    }

    return 0;

}