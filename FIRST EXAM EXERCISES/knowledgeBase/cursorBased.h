#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#ifndef cursorBased_H
#define cursorBased_H
#define MAX 20

typedef struct{
    char title[64];
    int id;
    char content[50];
}Article;


typedef struct{
    Article* art;
    int next;
}Heapspace;

typedef struct{
    Heapspace H[MAX];
    int avail;
}VHeap;

typedef int List;
void initHeap(VHeap* heap);
int allocSpace (VHeap *heap);
void deallocSpace(VHeap *heap, int idx);
void insertPos(VHeap * heap, List* L, int pos, Article* data);
void display(VHeap* heap, List* L);
void locate (VHeap* heap, List* L, int id);
void deleteArticle(VHeap * heap, List *L, int id);
bool getIDTrue(VHeap* heap, List* L, int id);

void initHeap(VHeap* heap){
    int i;
    for (i = 0; i < MAX - 1; i++){
        heap->H[i].next = i+1;
    }
    heap->H[i].next = -1;
    heap->avail = 0;
}

int allocSpace (VHeap *heap){
    int retVal;

    if(heap->avail != -1){
        retVal = heap->avail;
        heap->avail = heap->H[retVal].next;
    }

    return retVal;
}

void deallocSpace(VHeap *heap, int idx){
    if (idx != -1 && idx < MAX ){
        heap->H[idx].next = heap->avail;
        heap->avail = idx;
    }
}

void insertPos(VHeap * heap, List* L, int pos, Article* data){
    List temp = allocSpace(heap);
    List* trav;
    if (pos == -1){
        for (trav = L; *trav != -1; trav = &heap->H[*trav].next){
            
        }

        heap->H[temp].art = data;
        heap->H[temp].next = -1;
        *trav = temp;
    } else {
        for (trav = L; *trav != -1 && *trav < pos - 1; trav = &heap->H[*trav].next){
        }
        heap->H[temp].art = data;
        heap->H[temp].next = *trav;
        *trav = temp;

    }

       
        printf("Article with id: %d added to position %d\n", data->id, pos++);
    
}

void display(VHeap* heap, List* L){
    List *trav;
    printf("---------------------------------------\n");
    printf("%-5s %-8s %-10s\n", "ID", "Title", "Description");
    for (trav = L; *trav != -1; trav = &heap->H[*trav].next){
        printf("%-5d %-8s %-10s\n", heap->H[*trav].art->id, heap->H[*trav].art->title, heap->H[*trav].art->content);
    }
}

bool getIDTrue(VHeap* heap, List* L, int id){
    return heap->H[*L].art->id != id;
}

void locate (VHeap* heap, List* L, int id){
    List *trav;

    for (trav = L; *trav != -1 && getIDTrue(heap, trav, id); trav = &heap->H[*trav].next){

    }
    if (*trav != -1){
        printf("Article Found\nID: %d Title: %s Description: %s\n", heap->H[*trav].art->id, heap->H[*trav].art->title, heap->H[*trav].art->content);    
    } else {
        printf("Article not found\n");
    }


}

void deleteArticle(VHeap * heap, List *L, int id){
    List *trav;
    List prev = -1;
    for (trav = L; *trav != -1 && getIDTrue(heap, trav, id); trav = &heap->H[*trav].next){
        prev = *trav;
    }

    if (*trav != -1){
        List tempTodelete = *trav;
        heap->H[prev].next = heap->H[*trav].next;
        deallocSpace(heap, tempTodelete);

        printf("Article with id: %d successfully deleted\n", id);
    } else {
        printf("Article to delete not found\n");
    }
}


#endif