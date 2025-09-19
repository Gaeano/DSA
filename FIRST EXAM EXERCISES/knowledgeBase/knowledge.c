#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cursorBased.h"


int main (){
    VHeap heap;
    List L = -1;

    initHeap(&heap);

   while (1){
    
    int choice;
    printf("---------------------------------------\n");
    printf("1. Insert Article\n2.View List of Articles\n3.Search for an article\n4.Delete an article\npress -1 to exit\nchoice: ");
    scanf("%d", &choice);
    getchar();


    if (choice == -1){
        break;
    }

    switch(choice){
        case 1:
        int i;
        int pos; 
        int id;
        i++;
        Article* art = (Article*) malloc (sizeof(Article));
        printf("Enter Title: ");
        scanf("%[^\n]s", &art->title);
        // fgets(art->title, sizeof(art->title), stdin);
        getchar();

        // art->title[strcspn(art->title, "\n")] = '\0';


        printf("Enter Description: ");
        scanf("%[^\n]s", &art->content);
        // fgets(art->content, sizeof(art->content), stdin);
        getchar();
        // art->content[strcspn(art->content, "\n")] = '\0';
        

        art->id = i;
        printf("Enter position to insert: ");
        scanf("%d", &pos);
        getchar();

        


        insertPos(&heap, &L, pos, art);
        break;

        case 2:
        display(&heap, &L);
        break;

        case 3:
        printf("Enter id of the article to find: ");
        scanf("%d", &id);
        locate(&heap, &L, id);
        break;

        case 4:
        printf("Enter id of the article to delete: ");
        scanf("%d", &id);

        deleteArticle(&heap, &L, id);
        break;

        default:
        printf("Wrong choice!");

    } 

   }

}